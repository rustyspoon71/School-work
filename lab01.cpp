
#include <iostream>
#include <cmath>
using namespace std;

// declare properties of Lm and its thrusters
float lmWeight = 15103;
float accelerationOfTheMoon = 1.625;
float powerVertical = 45000;
float powerHorizontal = 450;

// get input from user using these functions
float getHorizontalVelocity(){
    float horizontalVelocity;
    cout << "What is your horizontal velocity (m/s)? ";
    cin >> horizontalVelocity;
    return horizontalVelocity;
}
float getVerticalVelocity(){
    float verticalVelocity;
    cout << "What is your vertical velocity (m/s)? ";
    cin >> verticalVelocity;
    return verticalVelocity;
}
float getAltitude(){
    float altitude;
    cout << "What is your altitude?(m) ";
    cin >> altitude;
    return altitude;
    
}
// create functions to perform the calculations
float verticalAccelerationCalculation(){
    float verticalAcceleration = powerVertical / lmWeight;
    verticalAcceleration = verticalAcceleration - accelerationOfTheMoon;
    return verticalAcceleration;
}
float horizontalAccelertationCalculation(){
    float horizontalAcceleration = powerHorizontal / lmWeight;
    return horizontalAcceleration;
}

float timeCalculation(){
    float acceleration = verticalAccelerationCalculation();
    float altitude = getAltitude();
    float value = (2 * altitude) / acceleration;
    float time = sqrt(value);
    return time;

}
//define global variable as we will be using these a lot rather than passing them around as parameters easier to access if globally enabled for this small example of the project.
float verticalVelocity = getVerticalVelocity();
float horizontalVelocity = getHorizontalVelocity();
float time = timeCalculation();
// more functions to do the calculations
float finalVerticalCalculation(){
    float finalVerticalVelocity = verticalVelocity + (accelerationOfTheMoon * time);
    return finalVerticalVelocity;
}
float finalHorizontalVelocity(){
    float finalHorizontalVelocity = horizontalVelocity + (accelerationOfTheMoon * time);
    return finalHorizontalVelocity; 
}
float totalVelocityCalculation(){
    float acceleration = verticalAccelerationCalculation();
    float totalVelocity = verticalVelocity + (acceleration * time);
    return totalVelocity;
}

// create a display function to show the output
void display(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    float totalVelocity = totalVelocityCalculation();
    float finishedVerticalVelocity = finalVerticalCalculation();
    float finishedHorizontalVelocity = finalHorizontalVelocity();
    cout << "Time to landing:   " << time << endl;  
    cout << "Vertical velocity:    " << finishedVerticalVelocity << endl ; 
    cout << "Horizontal velocity:   " << finishedHorizontalVelocity << endl ; 
    cout << "Total velocity:   " << totalVelocity << endl ; 
    if (finishedVerticalVelocity > 0 ){
        cout << "You will not land but rather fly off into space."<<endl;
    }
    else{
        cout << "You will land on the moon" << endl;
    }

}




int main(){
    display();
    return 1; 


}
