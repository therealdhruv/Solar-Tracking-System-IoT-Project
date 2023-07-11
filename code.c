// Include the servo motor library
#include <Servo.h>

// Define the LDR sensor pins
#define LDR1 A0
#define LDR2 A1

// Define the error value. You can change it as you like
#define ERROR_THRESHOLD 10

// Starting point of the servo motor
int servoStartingPoint = 90;

// Create an object for the servo motor
Servo servo;

void setup()
{
    // Include servo motor PWM pin
    servo.attach(11);
    servo.write(0);

    // Set the starting point of the servo
    servo.write(servoStartingPoint);
    delay(1000);
}

void loop()
{
    // Get the LDR sensor values
    int ldr1 = analogRead(LDR1);
    int ldr2 = analogRead(LDR2);

    // Get the difference of these values
    int value1 = abs(ldr1 - ldr2);
    int value2 = abs(ldr2 - ldr1);

    // Check these values using an if condition
    if ((value1 <= ERROR_THRESHOLD) || (value2 <= ERROR_THRESHOLD))
    {
        // Values are within the error threshold, no action needed
    }
    else
    {
        // Values are outside the error threshold, adjust the servo position
        if (ldr1 > ldr2)
        {
            servoStartingPoint--;
        }
        if (ldr1 < ldr2)
        {
            servoStartingPoint++;
        }
    }

    // Write the updated servo position
    servo.write(servoStartingPoint);

    delay(80);
}
