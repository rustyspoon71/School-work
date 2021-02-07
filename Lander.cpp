/***********************************************************************
* Source File:
*    Lander : All actions for the lander 
* Author:
*    Russell Roberts
* Summary:
*    The functions of the lander 
************************************************************************/
#include "lander.h" // for the lander class definition 
#include "ground.h"

// reset method to reset the lander
void Lander::reset() 
{
    status = true;
    pt.setX(20);
    pt.setY(400);
    angle = 0.0;
    fuel = 2000.0;
}

// check if user is dead.
bool Lander::isDead(Ground ground) 
{
    return ground.hitGround(pt, 10);
}

// check if the user has landed the lander
bool Lander::isLanded(Ground ground)
{
    return ground.onPlatform(pt, 10);
}

// check if the user is still flying
bool Lander::isFlying(Ground ground) 
{
    if (Lander::isLanded(ground) || Lander::isDead(ground)) 
    {
        return false;
    }
    return true;
}

// get the position of the lander
Point Lander::getPosition() 
{
    return pt;
}

// see how much fuel is left
int Lander::getFuel() 
{
    return fuel;
}

// draw the lander 
void Lander::draw(Thrust thrust, ogstream& gout) const
{
    gout.drawLander(pt /*position*/, angle /*angle*/);
    gout.drawLanderFlames(pt, angle, thrust.isMain(), thrust.isCounter(), thrust.isClock());
}

// take input of the user
void Lander::input(Thrust thrust)
{
    if (status) 
    {
        if (thrust.isMain()) 
        {
            v.addDY(0.00001 * (v.getDY() + ((vThrust * cos(angle)) + g) * 0.01));
            v.addDX(-0.00001 * (v.getDX() + ((vThrust * sin(angle)) * 0.01)));
            fuel -= 1;
        }
        else 
        {
            coast();
        }

        if (thrust.isClock())
        {
            angle -= 0.1;
        }
        else if (thrust.isCounter())
        {
            angle += 0.1;
        }
    }
    else 
    {
        land();
    }

    // Update the landers position
    pt.addX(v.getDX());
    pt.addY(v.getDY());
}

// check if the lunar lander is coasting 
void Lander::coast() 
{
    v.addDY(-0.01 * (g * 0.1));
};

// check if the lunar lander has landed 
void Lander::land() 
{
    v.setDX(0.0);
    v.setDY(0.0);
}

// check if the lunar lander has crashed
void Lander::crash()
{
    land();
    angle = 3.14;
    status = false;
}

float Lander::getSpeed() 
{
    return sqrt((v.getDX() * v.getDX()) + (v.getDY() * v.getDY()));
}