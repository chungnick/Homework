// Nick Chung
// 104926143
//v5

#include "Actor.h"
#include "StudentWorld.h"

#include <iostream>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp



void GhostRacer::doSomething() {
    if (!getAlive())
        return;
    if (getX() <= ROAD_CENTER - ROAD_WIDTH / 2) {
        if (getDirection() > 90) {
            setHP(-10);
            setDirection(82);
            getWorld()->playSound(SOUND_VEHICLE_CRASH);
        }
    }
    if (getX() >= ROAD_CENTER + ROAD_WIDTH / 2) {
        if (getDirection() < 90) {
            setHP(-10);
            setDirection(98);
            getWorld()->playSound(SOUND_VEHICLE_CRASH);
        }
    }
    int ch;
    if (getWorld()->getKey(ch)) {
        switch (ch) {
        case KEY_PRESS_LEFT: {
            if (getDirection() < 114)
                setDirection(getDirection() + 8);
            break;
        }
        case KEY_PRESS_RIGHT: {
            if (getDirection() > 66)
                setDirection(getDirection() - 8);
            break;
        }
        case KEY_PRESS_UP: {
            if (getVerticalSpeed() < 5)
                setVerticalSpeed(1 + getVerticalSpeed());
            break;
        }
        case KEY_PRESS_DOWN: {
            if (getVerticalSpeed() > -1)
                setVerticalSpeed(getVerticalSpeed() - 1);
            break;
        }
        case KEY_PRESS_SPACE: {
            if (getHolyWater() > 0) {
                getWorld()->playSound(SOUND_PLAYER_SPRAY);
                getWorld()->addSpray();
                setHolyWater(-1);
            }
            break;
        }
        }
    }
    double max_shift_per_tick = 4.0;
    double direction = getDirection();
    static const double PI = 4 * atan(1.0);
    direction = direction * PI / 180;
    if (direction > 360)
        direction -= 360;
    double delta_x = cos(direction) * max_shift_per_tick;
    double cur_x = getX();
    double cur_y = getY();
    moveTo(cur_x + delta_x, cur_y);
    return;
}

void HumanPedestrian::doSomething() {
    if (!getAlive())
        return;
    if (overlap(this, getWorld()->getActor(0))) {
        getRacer()->setAlive(false);
        return;
    }
    verticalScroll();
    int horiz_speed = getHorizontalSpeed();
    setMovePlanDistance(-1);
    if (getMovePlanDistance() > 0)
        return;
    else
        pedMovement();
    return;
}

void ZombiePedestrian::doSomething() {
    if (!getAlive())
        return;
    if (overlap(this, getWorld()->getActor(0))) {
        getRacer()->setHP(-5);
        getWorld()->setScore(150);
        getWorld()->playSound(SOUND_PED_DIE);
        setAlive(false);
        return;
    }
    if (abs(getX() - m_racer->getX()) <= 30 && getY() >= m_racer->getY()) {
        setDirection(270);
        if (getX() < m_racer->getX())
            setHorizontalSpeed(1);
        else if (getX() > m_racer->getX())
            setHorizontalSpeed(-1);
        else
            setHorizontalSpeed(0);
        setTicksToGrunt(getTicksToGrunt() - 1);
        if (getTicksToGrunt() <= 0) {
            getWorld()->playSound(SOUND_ZOMBIE_ATTACK);
            setTicksToGrunt(20);
        }
    }
    verticalScroll();
    if (getMovePlanDistance() > 0) {
        setMovePlanDistance(-1);
        return;
    }
    else
        pedMovement();
    return;
}

void ZombieCab::doSomething() {
    if (!getAlive())
        return;
    if (overlap(this, getWorld()->getActor(0)) && !getDamageGhostRider()) {
        getWorld()->playSound(SOUND_VEHICLE_CRASH);
        getRacer()->setHP(-20);
        if (getX() <= getRacer()->getX()) {
            setHorizontalSpeed(-5);
            setDirection(120 + randInt(0, 19));
        }
        else if (getX() > getRacer()->getX()) {
            setHorizontalSpeed(5);
            setDirection(60 - randInt(0, 19));
        }
        setDamageGhostRider(true);
    }
    verticalScroll();
    // for all actors
    int currLane = getWorld()->getLane(this);
    int lowestY = VIEW_HEIGHT;
    int indexOfLowest = 0;
    bool exists = false;
    
    if (aheadOfMe()) {
        double newSpeed = getVerticalSpeed() - 0.5;
        setVerticalSpeed(newSpeed);
        return;
    } else if (behindMe()) {
        double newSpeed = getVerticalSpeed() + 0.5;
        setVerticalSpeed(newSpeed);
        return;
    }
    setMovePlanDistance(-1);
    if (getMovePlanDistance() <= 0) {
        setMovePlanDistance(randInt(4, 32));
        double speed = getVerticalSpeed() + randInt(-2, 2);
        setVerticalSpeed(speed);
    }
    return;
}

void Environment::doSomething() {
    overlapAction();
    verticalScroll();
}

void OilSlick::overlapAction() {
    if (overlap(this, getWorld()->getActor(0))) {
        getWorld()->playSound(SOUND_OIL_SLICK);
        int negative = randInt(0, 1);
        int spin = randInt(5, 20);
        int direction = getRacer()->getDirection();
        if (negative == 0)
            negative = -1;
        if (direction + (negative * spin) >= 60
            && direction + (negative * spin) <= 120)
            getRacer()->setDirection(direction + (negative * spin));
    }
}

void HealingGoodie::overlapAction() {
    if (overlap(this, getWorld()->getActor(0))) {
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getWorld()->getActor(0)->setHP(10);
        getWorld()->setScore(250);
        setAlive(false);
    }
    return;
}

void LostSoulGoodie::overlapAction() {
    setDirection(getDirection() - 10);
    if (overlap(this, getWorld()->getActor(0))) {
        getRacer()->setSouls2Save(-1);
        setAlive(false);
        getWorld()->playSound(SOUND_GOT_SOUL);
        getWorld()->setScore(100);
    }
    return;
}

void HolyWaterGoodie::overlapAction() {
    if (overlap(this, getWorld()->getActor(0))) {
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getRacer()->setHolyWater(10);
        getWorld()->setScore(50);
        setAlive(false);
    }
    return;
}

void HolyWaterProjectile::doSomething() {
    if (!getAlive())
        return;
    for (int i = 1; i < getWorld()->numberOfActors(); i++) {
        if (overlap(this, getWorld()->getActor(i)))
            if (getWorld()->getActor(i)->getCollisionWorthy() || getWorld()->getActor(i)->getType() == 'J'
                || getWorld()->getActor(i)->getType() == 'K') {
            setAlive(false);
            if (getWorld()->getActor(i)->getType() != 'B')
                getWorld()->getActor(i)->setHP(-1);
            HitBySpray(getWorld()->getActor(i));
            return;
        } else {
            moveForward(SPRITE_HEIGHT);
            setMaxTravelDistance(-1);
            if (getMaxTravelDistance() <= 0) {
                setAlive(false);
                return;
            }
            if (getX() < 0 || getY() < 0 || getX() > VIEW_WIDTH || getY() > VIEW_HEIGHT ) {
                setAlive(false);
                return;
            }
        }
    }
    return;
}

void Actor::HitBySpray(Actor* actor) {
    if (actor->getHP() <= 0 || actor->getType() == 'K' || actor->getType() == 'J') {
        actor->setAlive(false);
        // zombiePed
        if (actor->getType() == 'C') {
            getWorld()->playSound(SOUND_PED_DIE);
            getWorld()->setScore(150);
            if (randInt(0, 4) == 0 && !overlap(actor, getWorld()->getActor(0)))
                getWorld()->addHealing(actor->getX(), actor->getY());
        }
        // zombieCab
        else if (actor->getType() == 'D') {
            getWorld()->playSound(SOUND_VEHICLE_DIE);
            getWorld()->setScore(200);
            if (randInt(0, 4) == 0 && !overlap(actor, getWorld()->getActor(0)))
                getWorld()->addOilSlick(actor->getX(), actor->getY());
        }
        return;
    }
    else {
        // zombiePed
        if (actor->getType() == 'C')
            getWorld()->playSound(SOUND_PED_HURT);
        // zombieCab
        else if (actor->getType() == 'D')
            getWorld()->playSound(SOUND_VEHICLE_HURT);
        // humanPed
        else if (actor->getType() == 'B') {
            int currSpeed = -1 * actor->getHorizontalSpeed();
            actor->setHorizontalSpeed(currSpeed);
            if (actor->getDirection() == 0)
                actor->setDirection(180);
            else if (actor->getDirection() == 180)
                actor->setDirection(0);
            getWorld()->playSound(SOUND_PED_HURT);
        }
        return;
    }
    setHitBySpray(false);
    return;
}

bool Actor::overlap(Actor* A, Actor* B) {
    long double delta_x = abs(A->getX() - B->getX());
    long double delta_y = abs(A->getY() - B->getY());
    int radius_sum = A->getRadius() + B->getRadius();
    if (delta_x < radius_sum * 0.25 && delta_y < radius_sum * 0.6)
        return true;
    return false;
}

void Actor::verticalScroll() {
    int vert_speed = getVerticalSpeed() - getWorld()->getActor(0)->getVerticalSpeed();
    int horiz_speed = getHorizontalSpeed();
    int new_x = getX() + horiz_speed;
    int new_y = getY() + vert_speed;
    moveTo(new_x, new_y);
    if (getX() < 0 || getY() < 0 || getX() > VIEW_WIDTH || getY() > VIEW_HEIGHT) {
        setAlive(false);
        return;
    }
}

void Entity::pedMovement() {
    int horiz_speed = randInt(-3, 3);
    while (horiz_speed == 0) {
        horiz_speed = randInt(-3, 3);
    }
    setHorizontalSpeed(horiz_speed);
    setMovePlanDistance(randInt(4, 32));
    if (getHorizontalSpeed() < 0)
        setDirection(180);
    else if (getHorizontalSpeed() > 0)
        setDirection(0);
    return;
}

bool ZombieCab::behindMe() {
    int currLane = getWorld()->getLane(this);
    for (int i = 0; i < getWorld()->numberOfActors(); i++) {
        if (getWorld()->getActor(i)->getCollisionWorthy() && getWorld()->getLane(getWorld()->getActor(i)) == currLane
            && getWorld()->getActor(i)->getY() < getY() && getY() - getWorld()->getActor(i)->getY() < 96) {
            return true;

        }
    }
    return false;
}

bool ZombieCab::aheadOfMe() {
    int currLane = getWorld()->getLane(this);
    for (int i = 0; i < getWorld()->numberOfActors(); i++) {
        if (getWorld()->getActor(i)->getCollisionWorthy() && getWorld()->getLane(getWorld()->getActor(i)) == currLane
            && getWorld()->getActor(i)->getY() > getY() && getWorld()->getActor(i)->getY() - getY() < 96) {
            return true;
        }
    }
    return false;
}
