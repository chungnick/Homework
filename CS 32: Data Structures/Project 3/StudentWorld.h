// Nick Chung
// 104926143
//v5

#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Actor.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld {
public:
    StudentWorld(std::string assetPath);
    ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();

    void setScore(int score) { m_score += score; }
    int getScore() { return m_score; }

    const int LEFT_EDGE = ROAD_CENTER - ROAD_WIDTH / 2;
    const int RIGHT_EDGE = ROAD_CENTER + ROAD_WIDTH / 2;

    Actor* getActor(int i) { return m_actor[i]; }
    void addSpray() { m_actor.push_back(new HolyWaterProjectile(m_player->getX(), m_player->getY(), m_player->getDirection(), this)); }
    void addHealing(int x, int y) { m_actor.push_back(new HealingGoodie(x, y, this, m_player)); }
    void addOilSlick(int x, int y) { m_actor.push_back(new OilSlick(x, y, randInt(2, 5), this, m_player)); }
    int numberOfActors() { return m_actor.size(); }
    GhostRacer* getRacer() { return m_player; }

    bool inLane(int lane, Actor* actor);
    void setLane(int lane) { m_lane = lane; }
    int getLane(Actor* actor) {
        if (inLane(0, actor))
            return 0;
        else if (inLane(1, actor))
            return 1;
        else if (inLane(2, actor))
            return 2;
        else
            return -1;
    }

    void setDisplayText();
    std::string displayText(int score, int level, int souls2save,
        int lives, int health, int sprays, int bonus);
private:
    std::vector<Actor*> m_actor;
    GhostRacer* m_player = nullptr;
    bool m_levelComplete = false;
    int m_score = 0;
    int m_lane = 0;
};

#endif // STUDENTWORLD_H_
