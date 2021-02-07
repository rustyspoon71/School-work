/***********************************************************************
* Header File:
*    Lander : All actions for the lander 
* Author:
*    Russell Roberts
* Summary:
*    Where the ground is located and where the landing pad is located
************************************************************************/
#include "thrust.h" // to take input of thrust.
#include "point.h" // take values from the point class
#include "velocity.h"
#include "uiDraw.h"
#include "ground.h"


/***********************************************************
* Lander
*   
* The lander class 
***********************************************************/
class Lander
{
public:
    // Lander constructor to get the whole program going 
    Lander(Point ptUpperRight)
    {
        status = true;
        angle = 0.0;
        fuel = 2000.0;
        weight = 15103.0;
        vThrust = 45000.0;
        hThrust = 450.0;
        g = 1.625;
        pt = ptUpperRight;
        pt.setX(20.0);
        v.setDX(0);
        v.setDY(-0.1);
    }

    // reset method to reset the lander
    void reset();

    // check if user is dead.
    bool isDead(Ground ground);

    // check if the user has landed the lander
    bool isLanded(Ground ground);

    // check if the user is still flying
    bool isFlying(Ground ground);

    // get the position of the lander
    Point getPosition();

    // see how much fuel is left
    int getFuel();

    // draw the lander 
    void draw(Thrust thrust, ogstream& gout) const;

    // take input of the user
    void input(Thrust thrust);

    // check if the lunar lander is coasting 
    void coast();

    // check if the lunar lander has landed 
    void land();

    // check if the lunar lander has crashed
    void crash();

    float getSpeed();

    // set all the private values
private:
    bool status;                    // status of the lander true is alive false is dead
    Point pt;                       // the point and or location of the lander
    Velocity v;                     // get the velocity from the velocity class 
    double angle;                   // find the angle of the lander
    double fuel;                    // the value of fuel the lander has
    double weight;           // the weight of the lander 
    double vThrust;          // vertical thrust 
    double hThrust;          // horizontal thrust
    double g;                // Gravity value 
};
