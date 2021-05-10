// Nick Chung
// 104926143
//v5

#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include <sstream>
#include <cmath>

#include <iostream>

using namespace std;

GameWorld* createStudentWorld(string assetPath) {
    return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
    : GameWorld(assetPath)
{
}

int StudentWorld::init() {
    // GhostRacer
    int souls2Save = 2 * getLevel() + 5;
    m_player = new GhostRacer(this, souls2Save);
    m_actor.push_back(m_player);
    // BorderLines
    int N = VIEW_HEIGHT / SPRITE_HEIGHT, M = VIEW_HEIGHT / (4 * SPRITE_HEIGHT);
    for (int j = 0; j <= N - 1; j++) {
        m_actor.push_back(new YellowBorderLine(LEFT_EDGE, j * SPRITE_HEIGHT, this, m_actor[0]));
        m_actor.push_back(new YellowBorderLine(RIGHT_EDGE, j * SPRITE_HEIGHT, this, m_actor[0]));
    }
    for (int j = 0; j <= M - 1; j++) {
        m_actor.push_back(new WhiteBorderLine(LEFT_EDGE + ROAD_WIDTH / 3, j * 4 * SPRITE_HEIGHT, this, m_actor[0]));
        m_actor.push_back(new WhiteBorderLine(RIGHT_EDGE - ROAD_WIDTH / 3, j * 4 * SPRITE_HEIGHT, this, m_actor[0]));
    }


    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    for (vector<Actor*>::iterator i = m_actor.begin(); i != m_actor.end(); i++) {
        if ((*i)->getAlive()) {
            (*i)->doSomething();
            if (m_actor[0]->getAlive() == false) {
                decLives();
                playSound(SOUND_PLAYER_DIE);
                return GWSTATUS_PLAYER_DIED;
            }
            if (m_player->getSouls2Save() <= 0)
                return GWSTATUS_FINISHED_LEVEL;
        }
    }
    vector<Actor*>::iterator i = m_actor.begin();
    while (i != m_actor.end()) {
        if (!(*i)->getAlive()) {
            Actor* temp = *i;
            i = m_actor.erase(i);
            delete temp;
            if (i != m_actor.begin())
                i--;
        }
        i++;
    }
    

    // BorderLines
    int lastWhitePos = 0;
    for (vector<Actor*>::iterator i = m_actor.end() - 1; i != m_actor.begin(); i--) {
        if ((*i)->getType() == 'G') {
            lastWhitePos = (*i)->getY();
            break;
        }
    }
    int new_border_y = VIEW_HEIGHT - SPRITE_HEIGHT;
    int delta_y = new_border_y - lastWhitePos;
    if (delta_y >= SPRITE_HEIGHT) {
        m_actor.push_back(new YellowBorderLine(LEFT_EDGE, new_border_y, this, m_actor[0]));
        m_actor.push_back(new YellowBorderLine(RIGHT_EDGE, new_border_y, this, m_actor[0]));
    }
    if (delta_y >= 4 * SPRITE_HEIGHT) {
        m_actor.push_back(new WhiteBorderLine(LEFT_EDGE + ROAD_WIDTH / 3, new_border_y, this, m_actor[0]));
        m_actor.push_back(new WhiteBorderLine(RIGHT_EDGE - ROAD_WIDTH / 3, new_border_y, this, m_actor[0]));
    }
    // OilSlicks
    int chanceOilSlick = max(150 - getLevel() * 10, 40);
    if (randInt(0, chanceOilSlick - 1) == 0)
        m_actor.push_back(new OilSlick(randInt(LEFT_EDGE, RIGHT_EDGE), VIEW_HEIGHT, randInt(2, 5), this, m_player));
    // Zombiepeds
    int chanceZombiePed = max(100 - getLevel() * 10, 20);
    if (randInt(0, chanceZombiePed - 1) == 0)
        m_actor.push_back(new ZombiePedestrian(randInt(LEFT_EDGE, RIGHT_EDGE), VIEW_HEIGHT, this, m_player));
    // HumanPeds
    int chanceHumanPed = max(100 - getLevel() * 10, 30);
    if (randInt(0, chanceHumanPed - 1) == 0)
        m_actor.push_back(new HumanPedestrian(randInt(0, VIEW_WIDTH), VIEW_HEIGHT, this, m_player));
    // ZombieCab
    int chanceVehicle = max(100 - getLevel() * 10, 20);
    if (randInt(0, chanceVehicle - 1) == 0) {
        int cur_lane = randInt(0, 2);
        bool viableLane = false;
        int startingLane = 0;
        int startingY = 0;
        int startingSpeed = 0;
        int x = 0, y = 0;
        for (int i = 0; i < 3; i++) {
            int indexofLowestY = 0;
            int lowestY = VIEW_HEIGHT;
            int indexofHighestY = 0;
            int highestY = 0;
            bool foundTop = false, foundBottom = false;

            for (int j = 0; j < numberOfActors() - 1; j++) {
                if (getActor(j)->getY() < lowestY && getActor(j)->getCollisionWorthy() && inLane(i, getActor(j))) {
                    lowestY = getActor(j)->getY();
                    indexofLowestY = j;
                    bool foundBottom = true;
                }
                if (getActor(j)->getY() > highestY && getActor(j)->getCollisionWorthy() && inLane(i, getActor(j))) {
                    highestY = getActor(j)->getY();
                    indexofHighestY = j;
                    bool foundTop = true;
                }
            }
            // closest to bottom
            if ((foundBottom && getActor(indexofLowestY)->getY() > VIEW_HEIGHT / 3) || !foundBottom) {
                if (!inLane(cur_lane, getActor(0))) {
                    startingLane = cur_lane;
                    startingY = SPRITE_HEIGHT / 2;
                    startingSpeed = getActor(0)->getVerticalSpeed() + randInt(2, 4);
                    viableLane = true;
                    break;
                }
            }
            // closest to top
            if ((foundTop && getActor(indexofHighestY)->getY() < VIEW_HEIGHT * 2 / 3) || !foundTop) {
                startingLane = cur_lane;
                startingY = VIEW_HEIGHT - SPRITE_HEIGHT / 2;
                startingSpeed = getActor(0)->getVerticalSpeed() - randInt(2, 4);
                viableLane = true;
                break;
            }
            cur_lane = cur_lane + 1;
            if (cur_lane > 2)
                cur_lane = 0;
        }
        if (viableLane) {
            if (startingLane == 0)
                m_actor.push_back(new ZombieCab(ROAD_CENTER - ROAD_WIDTH / 3, startingY, startingSpeed, this, m_player));
            else if (startingLane == 1)
                m_actor.push_back(new ZombieCab(ROAD_CENTER, startingY, startingSpeed, this, m_player));
            else if (startingLane == 2)
                m_actor.push_back(new ZombieCab(ROAD_CENTER + ROAD_WIDTH / 3, startingY, startingSpeed, this, m_player));
        }
    }
    // HolyWaterRefillGoodies
    int chanceOfHolyWater = 100 + 10 * getLevel();
    if (randInt(0, chanceOfHolyWater - 1) == 0)
        m_actor.push_back(new HolyWaterGoodie(randInt(LEFT_EDGE, RIGHT_EDGE), VIEW_HEIGHT, this, m_player));
    // LostSoulGoodies
    int chanceOfLostSoul = 100;
    if (randInt(0, chanceOfLostSoul - 1) == 0)
        m_actor.push_back(new LostSoulGoodie(randInt(LEFT_EDGE, RIGHT_EDGE), VIEW_HEIGHT, this, m_player));

    setDisplayText();
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp() {
    vector<Actor*>::iterator i = m_actor.begin();
    while (i != m_actor.end()) {
        Actor* temp = *i;
        i = m_actor.erase(i);
        delete temp;
    }
}

StudentWorld::~StudentWorld() {
    cleanUp();
}

bool StudentWorld::inLane(int i, Actor* actor) {
    if (i == 0) {
        if (actor->getX() >= LEFT_EDGE && actor->getX() < LEFT_EDGE + ROAD_WIDTH / 3)
            return true;
        else
            return false;
    }
    else if (i == 1) {
        if (actor->getX() >= LEFT_EDGE + ROAD_WIDTH / 3 && actor->getX() < RIGHT_EDGE - ROAD_WIDTH / 3)
            return true;
        else
            return false;
    }
    else if (i == 2) {
        if (actor->getX() >= RIGHT_EDGE - ROAD_WIDTH / 3 && actor->getX() < RIGHT_EDGE)
            return true;
        else
            return false;
    } else
        return false;
}

void StudentWorld::setDisplayText() {
    int score = getScore();
    int level = getLevel();
    int souls2save = m_player->getSouls2Save();
    int lives = getLives();
    int health = m_player->getHP();
    int sprays = m_player->getHolyWater();
    int bonus = 0;
    string s = displayText(score, level, souls2save, lives, health, sprays, bonus);
    setGameStatText(s);
}

string StudentWorld::displayText(int score, int level, int souls2save,
    int lives, int health, int sprays, int bonus) {
    ostringstream oss;
    oss << "Score: " << score << " Lvl: " << level << " Souls2Save: "
        << souls2save << " Lives: " << lives << " Health: " << health << " Sprays: " << sprays
        << " Bonus: " << bonus;
    return oss.str();
}
