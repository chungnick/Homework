// Nick Chung
// 104926143
//v5

#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(int imageID, double startX, double startY, int startDirection,
        double size, int depth, StudentWorld* world) : GraphObject(imageID, startX, startY, startDirection,
            size, depth), m_world(world) {}
    virtual void doSomething() {}
    bool overlap(Actor* A, Actor* B);
    virtual void overlapAction() {}
    void setAlive(bool alive) { m_alive = alive; }
    bool getAlive() { return m_alive; }
    void setSpeed(int horizSpeed, int vertSpeed) { m_horizontalSpeed = horizSpeed; m_verticalSpeed = vertSpeed; }
    void setVerticalSpeed(double verticalSpeed) { m_verticalSpeed = verticalSpeed; }
    double getVerticalSpeed() { return m_verticalSpeed; }
    void setHorizontalSpeed(double horizontalSpeed) { m_horizontalSpeed = horizontalSpeed; }
    double getHorizontalSpeed() { return m_horizontalSpeed; }
    void setCollisionWorthy(bool collisionWorthy) { m_collisionWorthy = collisionWorthy; }
    bool getCollisionWorthy() { return m_collisionWorthy; }
    void setHP(int HP) {
        m_HP += HP;
        if (getHP() <= 0) {
            setAlive(false);
        }
        if (getHP() > 100)
            m_HP = 100;
    }
    int getHP() { return m_HP; }
    void setType(char type) { m_type = type; }
    // Directory of Types
    // GhostRacer :                A
    // HumanPedestrian :        B
    // ZombiePedestiran :        C
    // ZombieCab :                D
    // OilSlick :                E
    // HolyWaterProjectiles:    F
    // WhiteBorderLine:            G
    // YellowBorderLine:        H
    // LostSouls:                I
    // HealingGoodies:            J
    // HolyWaterRefill:            K

    void verticalScroll();

    char getType() { return m_type; }
    StudentWorld* getWorld() { return m_world; }

    void setHitBySpray(bool hit) { m_hit = hit; }
    bool getHitBySpray() { return m_hit; }
    void HitBySpray(Actor* actor);
private:
    bool m_alive = true, m_collisionWorthy = true;
    bool m_hit = false;
    double m_horizontalSpeed = 0, m_verticalSpeed = 0;
    char m_type;
    int m_HP = 0;
    StudentWorld* m_world;
};

class Entity : public Actor {
public:
    Entity(const int imageID, int x, int y, int startDirection, int size, int depth,
        StudentWorld* world) : Actor(imageID, x, y, startDirection, size, depth, world) {}
    
    void setMovePlanDistance(int movePlanDistance) { m_movePlanDistance += movePlanDistance; }
    int getMovePlanDistance() { return m_movePlanDistance; }
    void pedMovement();
    
private:
    int m_movePlanDistance = 0;
};

class GhostRacer : public Entity {
public:
    GhostRacer(StudentWorld* world, int souls2save)
        : Entity(IID_GHOST_RACER, 128, 32, 90, 4.0, 0, world) {
        setHP(100);
        setAlive(true);
        setCollisionWorthy(true);
        setVerticalSpeed(0);
        setHolyWater(10);
        setType('A');
        setSouls2Save(souls2save);
    }
    void setHolyWater(int holyWater) { m_holyWater += holyWater; }
    int getHolyWater() { return m_holyWater; }
    void setSouls2Save(int souls2Save) {
        m_souls2Save += souls2Save;
    }
    int getSouls2Save() { return m_souls2Save; }
    void doSomething();
private:
    int m_HP = 0, m_holyWater = 0, m_souls2Save = 0;
};

class HumanPedestrian : public Entity {
public:
    HumanPedestrian(int startingX, int startingY, StudentWorld* world, GhostRacer* racer)
        : Entity(IID_HUMAN_PED, startingX, startingY, 0, 2.0, 0, world), m_racer(racer) {
        setMovePlanDistance(0);
        setSpeed(0, -4);
        setAlive(true);
        setHP(1);
        setCollisionWorthy(true);
        setType('B');
    }
    void doSomething();
    GhostRacer* getRacer() { return m_racer; }
private:
    GhostRacer* m_racer;
};

class ZombiePedestrian : public Entity {
public:
    ZombiePedestrian(int startingX, int startingY, StudentWorld* world, GhostRacer* racer)
        : Entity(IID_ZOMBIE_PED, startingX, startingY, 0, 3.0, 0, world), m_racer(racer) {
        setMovePlanDistance(0);
        setSpeed(0, -4);
        setAlive(true);
        setHP(2);
        setCollisionWorthy(true);
        setType('C');
    }
    void doSomething();
    void setTicksToGrunt(int ticks) { m_ticks = ticks; }
    int getTicksToGrunt() { return m_ticks; }
    GhostRacer* getRacer() { return m_racer; }
private:
    int m_ticks = 0;
    GhostRacer* m_racer;
};

class ZombieCab : public Entity {
public:
    ZombieCab(int startingX, int startingY, int startingVerticalSPeed, StudentWorld* world, GhostRacer* racer)
        : Entity(IID_ZOMBIE_CAB, startingX, startingY, 90, 4.0, 0, world), m_racer(racer) {
        setHorizontalSpeed(0);
        setVerticalSpeed(startingVerticalSPeed);
        setHP(3);
        setMovePlanDistance(0);
        setCollisionWorthy(true);
        setType('D');
    }
    void doSomething();
    void setDamageGhostRider(bool damageGhostRider) { m_damageGhostRider = damageGhostRider; }
    bool getDamageGhostRider() { return m_damageGhostRider; }
    bool behindMe();
    bool aheadOfMe();
    GhostRacer* getRacer() { return m_racer; }
private:
    bool m_damageGhostRider = false;
    GhostRacer* m_racer;
};

class Environment : public Actor {
public:
    Environment(const int imageID, int x, int y, int startDirection, int size, int depth,
        StudentWorld* world) : Actor(imageID, x, y, startDirection, size, depth, world) {
        setSpeed(0, -4);
        setCollisionWorthy(false);
    }
    void doSomething();
};

class OilSlick : public Environment {
public:
    OilSlick(int startingX, int startingY, int randSize, StudentWorld* world, GhostRacer* racer)
        : Environment(IID_OIL_SLICK, startingX, startingY, 0, randSize, 2, world), m_racer(racer) { setType('E'); }
    void overlapAction();
    GhostRacer* getRacer() { return m_racer; }
private:
    bool m_skid = false;
    GhostRacer* m_racer;
};

class HolyWaterGoodie : public Environment {
public:
    HolyWaterGoodie(int startingX, int startingY, StudentWorld* world, GhostRacer* racer)
        : Environment(IID_HOLY_WATER_GOODIE, startingX, startingY, 90, 2.0, 2, world), m_racer(racer){
        setType('K');
        setHP(1);
    }
    void overlapAction();
    GhostRacer* getRacer() { return m_racer; }
private:
    GhostRacer* m_racer;
};

class HolyWaterProjectile : public Environment {
public:
    HolyWaterProjectile(int startingX, int startingY, int startingDirection, StudentWorld* world)
        : Environment(IID_HOLY_WATER_PROJECTILE, startingX, startingY, startingDirection, 1.0, 1, world) {
        setMaxTravelDistance(20);
        setAlive(true);
    }
    void doSomething();
    void setMaxTravelDistance(int distance) { m_travelDistance += distance; }
    int getMaxTravelDistance() { return m_travelDistance; }
private:
    int m_travelDistance = 0;
    bool m_activate = false;
};

class HealingGoodie : public Environment {
public:
    HealingGoodie(int startingX, int startingY, StudentWorld* world, GhostRacer* racer)
        : Environment(IID_HEAL_GOODIE, startingX, startingY, 0, 1.0, 2, world), m_racer(racer) {
        setType('J');
        setHP(1);
    }
    void overlapAction();
    GhostRacer* getRacer() { return m_racer; }
private:
    GhostRacer* m_racer;
};

class LostSoulGoodie : public Environment {
public:
    LostSoulGoodie(int startingX, int startingY, StudentWorld* world, GhostRacer* racer)
        : Environment(IID_SOUL_GOODIE, startingX, startingY, 0, 4.0, 2, world), m_racer(racer) { setType('I'); }
    void overlapAction();
    GhostRacer* getRacer() { return m_racer; }
private:
    GhostRacer* m_racer;
};

class BorderLine : public Environment {
public:
    BorderLine(const int imageID, int x, int y, StudentWorld* world, Actor* racer)
        : Environment(imageID, x, y, 0, 2, 2, world) {}
};

class WhiteBorderLine : public BorderLine {
public:
    WhiteBorderLine(int x, int y, StudentWorld* world, Actor* racer)
        : BorderLine(IID_WHITE_BORDER_LINE, x, y, world, racer) { setType('G'); }
};

class YellowBorderLine : public BorderLine {
public:
    YellowBorderLine(int x, int y, StudentWorld* world, Actor* racer)
        : BorderLine(IID_YELLOW_BORDER_LINE, x, y, world, racer) { setType('H'); }
};
#endif // ACTOR_H_
