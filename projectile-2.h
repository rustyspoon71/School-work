#pragma once
/***********************************************************************
 * Header File:
 *    The projectile's location and flight pattern. 
 * Author:
 *    Russell Roberts
 * Summary:
 *    Will keep track of the projectiles location and where it is.
 ************************************************************************/
#include "uiDraw.h"
#include "position.h"
#include "direction.h"
#include "velocity.h"
#include "physics.h"
#include "uiInteract.h"
using namespace std;

class Projectile
{
    // constructor 
public:
    Projectile() 
    {
        mass = 46.71;
        radius = 0.15489 / 2.0;
    }
    void reset();
    void fire(Position pos, int time, Direction angle, double vel);
    void advance(double time);
    void draw(ogstream& gout);
    bool flying();
    double getAltitude();
    Position getPosition();
    double getFlightTime();
    double getFlightDistance();
    double getSpeed();
    double getCurrentTime();
    void setMass(double mass);
    void setRadius(double radius);
    double getMass();
    double getRadius();

private:
    //intialize the member variables.
    double mass;
    double radius;
    Position flightPath[20];
    Velocity velocity;
};
