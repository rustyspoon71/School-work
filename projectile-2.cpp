#include "projectile.h"
#include "position.h"
#include "velocity.h"

using namespace std;
/***********************************************************************
* RESET: The function resets the flight path and the velocity.
***********************************************************************/
void Projectile::reset()
{	
	velocity.setDxDy(0, 0);
	flightPath[0].setPixelsX(0);
	flightPath[0].setPixelsY(0);

	return;
}
/***********************************************************************
* FIRE: The function fires the projectile.
***********************************************************************/
void Projectile::fire(Position pos, int time, Direction angle, double vel) 
{
	reset();
	flightPath[0] = pos;
	velocity.setSpeed(vel);
	velocity.setDirection(angle);
	advance(time);
	return;
}
/***********************************************************************
* ADVANCE: The function will advance the program.
***********************************************************************/
void Projectile::advance(double time) 
{
	// Compute the gravity, density, and drag
	double gravity = gravityFromAltitude(getAltitude());
	double density = densityFromAltitude(getAltitude());
	double mach = machFromSpeed(getSpeed(), getAltitude());
	double drag = dragFromSpeed(getSpeed(), getAltitude());
	double area = areaFromRadius(radius);
	double dragForce = forceFromDrag(density, drag, area, getSpeed());

	// Compute the acceleration from gravity and air resistance.
	double gravityAcceleration = accelerationFromForce(gravity, mass);
	double acceleration = accelerationFromForce(dragForce, mass);

	// Compute the velocity from the acceleration
	double vel1 = velocityFromAcceleration(acceleration, time);
	double gravityVelocity = velocityFromAcceleration(gravityAcceleration, time);

	// Add the gravity
	velocity.addDy(-1 * gravityVelocity);

	// Add the drag
	velocity.addDx(sin(velocity.getDirection().getRadians()) * -1 * vel1);
	velocity.addDy(cos(velocity.getDirection().getRadians()) * -1 * vel1);

	// Move all the positions down one on the array.
	for (int i = 18; i >= 0; i--) 
	{
		flightPath[i + 1] = flightPath[i];
	}

	// Create the new position for the projectile
	Position newPosition = flightPath[0];

	// Add the new position
	newPosition.addMetersX(velocity.getDx());
	newPosition.addMetersY(velocity.getDy());
	flightPath[0] = newPosition;

}
/***********************************************************************
* DRAW: The function will draw the projectile.
***********************************************************************/

void Projectile::draw(ogstream& gout)
{
	Position pos;
	pos.setPixelsX(300);
	pos.setPixelsY(400);
	for (int i = 0; i < 20; i++)
		gout.drawProjectile(flightPath[i], 0.5 * (double)i);
	return;
}
/****************************************************************************
* FLYING: This function will determine if the projectile is still flying.
*****************************************************************************/

bool Projectile::flying() 
{  
	if (flightPath[0].getMetersY() < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
/***********************************************************************************
* GETALTITUDE: This function will return the latest altitude.
***********************************************************************************/
double Projectile::getAltitude() 
{	
	return flightPath[0].getMetersY();
}
/***********************************************************************************
* GETPOSITION: This function will return the position of the projectile.
***********************************************************************************/
Position Projectile::getPosition() 
{
	return flightPath[0];
}
/***********************************************************************************
* GETFLIGHTTIME: This function will return how long the projectile has been flying.
***********************************************************************************/
double Projectile::getFlightTime() 
{
	
	return sizeof(flightPath) / 2;
}
/****************************************************************************************
* GETFLIGHTDISTANCE: This function will return the distance the projectile has flown.
*****************************************************************************************/
double Projectile::getFlightDistance() 
{
	return flightPath[0].getMetersX();
}
/****************************************************************************************
* GETSPEED: This function will return the current speed the projectile is flying.
*****************************************************************************************/
double Projectile::getSpeed() 
{
	return velocity.getSpeed();
}
/****************************************************************************************
* GETCURRENTTIME: This function will return the current time.
*****************************************************************************************/
double Projectile::getCurrentTime() 
{
	return sizeof(flightPath) / 2;
}
/****************************************************************************************
* SETMASS: Set the mass of the projectile.
*****************************************************************************************/
void Projectile::setMass(double mass) 
{
	
	mass = 46.7;		// Kg

}
/****************************************************************************************
* SETRADIUS: Set the radius of the projectile.
*****************************************************************************************/

void Projectile::setRadius(double radius) 
{

	radius = 0.075;		// m^2

}
/****************************************************************************************
* GETMASS: Return the mass set above.
*****************************************************************************************/
double Projectile::getMass() 
{
	return mass;
}
/****************************************************************************************
* GETRADIUS: Return the radius set above.
*****************************************************************************************/
double Projectile::getRadius() 
{
	return radius;
}