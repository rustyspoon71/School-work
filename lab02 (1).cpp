/*************************************************************
 * 1. Name:
 *      -your name-
 * 2. Assignment Name:
 *      Lab 02: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      3 hours
 *****************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/* System constants */
#define THRUST 2.979540489   // Acceleration from thrusters is 45000 N / 15103 Kg.
#define GRAVITY -1.625       // Gravity contant for the moon in m/s.
#define PI 3.14159           // About the value of Pi.

/* Define the structures that are used to hold the input and results */
struct Input {
    float vertical;
    float horizontal;
    float altitude;
    float angle;
};

struct Results {
    int time;
    float dy;
    float dx;
    float speed;
    float x;
    float y;
    float angle;
};

/*************************************************************
 * COMPUTERADIAN: The function takes an angle measurement in
 *                degrees and converts it to radians.
 *************************************************************/
float computeRadian(float degrees)
{
    // Use the formula of r = 2 π d / 360° to convert degrees to radians.
    return (2 * PI * degrees / 360);
}

/* Code for getting data from the user */

/*************************************************************
 * GETSTARTANGLE: The function prompts the user for the start
 *                angle of the lunar lander.
 *************************************************************/
float getStartAngle()
{
    // Setup the variable to store the angle.
    float angleDegrees;

    // Prompt the user for the angle in degrees.
    cout << "What is the angle of the LM where 0 is up (degrees)? ";
    cin >> angleDegrees;

    // Convert the value to radians and return it.
    return angleDegrees;
}

/*************************************************************
 * GETANGLE: The function prompts the user for the angle of
 *           the lunar lander.
 *************************************************************/
float getAngle()
{
    // Setup the variable to store the angle.
    float angleDegrees;

    // Prompt the user for the angle in degrees.
    cout << "\nWhat is the new angle of the LM where 0 is up (degrees)? ";
    cin >> angleDegrees;

    // Convert the value to radians and return it.
    return angleDegrees;
}

/*************************************************************
 * GETVERTICAL: The function prompts the user for the vertical
 *              speed the lunar module.
 *************************************************************/
float getVertical() 
{
    // Setup the needed variables.
    float verticalSpeed;

    // Prompt the user for the vertical velocity.
    cout << "What is your vertical velocity (m/s)? ";
    cin >> verticalSpeed;

    // Return the speed.
    return verticalSpeed;
}

/*************************************************************
 * GETHORIZONTAL: The function prompts the user for the
 *                horizontal speed of the lunar module.
 *************************************************************/
float getHorizontal() 
{
    // Setup the needed variables.
    float horizontalSpeed;

    // Prompt the user for the horizontal speed.
    cout << "What is your horizontal velocity (m/s)? ";
    cin >> horizontalSpeed;

    // Return the speed.
    return horizontalSpeed;
}

/*************************************************************
 * GETALTITUDE: The function prompts the user for the altitude
 *              of the lunar module.
 *************************************************************/
float getAltitude()
{
    // Setup the needed variables.
    float altitude;

    // Prompt the user for the current altitude.
    cout << "What is your altitude (m)? ";
    cin >> altitude;

    // Return the altitude.
    return altitude;
}

/*************************************************************
 * GETDATA: The function gets all the needed data from the
 *          user about the lunar module.
 *************************************************************/
Input getData(Input input) 
{
    // Prompt the user for the vertical velocity.
    input.vertical = getVertical();

    // Prompt the user for the horizontal velocity.
    input.horizontal = getHorizontal();

    // Prompt the user for the altitude.
    input.altitude = getAltitude();

    // Prompt the user for the starting angle of the lunar lander.
    input.angle = getStartAngle();

    // Finish the function.
    return input;
}

/* Functions that process the data */

/*************************************************************
 * COMPUTETOTALVELOCITY: The function computes the current
 *                       speed of the lunar lander.
 *************************************************************/
float computeTotalVelocity(float vertical, float horizontal)
{
    // Combine both speed using the Pythagorean Theorem and return the value.
    return sqrt((vertical * vertical) + (horizontal * horizontal));
}

/*************************************************************
 * COMPUTEVERTICAL: The function computes the vertical
 *                  velocity after one second.
 *************************************************************/
float computeVertical(float dy, float angle)
{
    // Return the current dy using dy + Acceleration + Gravity.
    // Vertical Acceleration is thrust * cos(angle).
    return (dy + (THRUST * cos(angle)) + GRAVITY);
}

/*************************************************************
 * COMPUTEHORIZONTAL: The function computes the horizontal
 *                    velocity after one second.
 *************************************************************/
float computeHorizontal(float dx, float angle)
{
    // Return the current dy using dy + Acceleration.
    // Horizontal Acceleration is thrust * sin(angle).
    return (dx + (THRUST * sin(angle)));
}

/*************************************************************
 * COMPUTERESULTS: The function computes the lunar lander's
 *                 current poisition and speed.
 *************************************************************/
Results computeResults(Results result)
{
    // Update the dx and dy.
    // Make sure to convert angles from degrees to radians.
    result.dy = computeVertical(result.dy, computeRadian(result.angle));
    result.dx = computeHorizontal(result.dx, computeRadian(result.angle));

    // Update the lunar lander location from the last second.
    result.x = result.x + result.dx;
    result.y = result.y + result.dy;

    // Compute the total current speed.
    result.speed = computeTotalVelocity(result.dy, result.dx);

    // Return the results.
    return result;
}

/* Code for displaying the results to the user */

/*************************************************************
 * DISPLAY: The function displays the results to the user.
 *************************************************************/
void display(Results result)
{
    // Format the output to display the results to two decimals of accuracy.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Start the main loop for outputing the results.
    // We use 0.01 instead of 0 because the display will only round to 0.00.
    // So we can have a value of 0.001 and it won't prompt the user or continue the loop.
    while (result.y > 0.01)
    {
        // Display message to user before output the next five seconds.
        cout << "\nFor the next 5 seconds with the main engine on, the position of the lander is:\n\n";

        // Loop through the next five seconds worth of outputs.
        for (int i = 0; i < 5; i++)
        {
            // Call the compute function.
            result = computeResults(result);

            // Add one second to time.
            result.time++;

            // Display the results for that one second.
            cout << setw(2) << result.time << "s - x,y:(" << result.x << ", "
                 << result.y << ")m  dx,dy:(" << result.dx << ", " << result.dy
                 << ")m/s  speed:" << result.speed << "m/s  angle:"
                 << result.angle << "deg\n";
            
            // If at any point the y is less than zero meaning we landed, break from the for loop.
            if (result.y <= 0)
            {
                break;
            }
        }

        // Prompt the user for a new angle if we have not landed.
        if (result.y > 0.01)
        {
            result.angle = getAngle();
        }
    }
    // Once done, return to main.
    return;
}

/*************************************************************
 * MAIN: The main function for the program.
 *************************************************************/
int main(int argc, char const *argv[])
{
    // Create the needed structures to hold the data.
    Input mainInput;
    Results result;

    // Get the input from user.
    mainInput = getData(mainInput);

    // Copy all needed values to results.
    result.time = 0;
    result.y = mainInput.altitude;
    result.x = 0;
    result.dx = mainInput.horizontal;
    result.dy = mainInput.vertical;
    result.angle = mainInput.angle;

    // Call the display function.
    display(result);

    // Close the program.
    return 0;
}