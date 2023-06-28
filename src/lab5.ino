SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);


// Libraries
#include <math.h>

// Pins
const int lightSensorPin = A0;  // Analog pin for light sensor
const int ledPin = D2;          // Digital pin for LED

// Constants
const int minSensorValue = 0;   // Minimum value of light sensor reading
const int maxSensorValue = 4095;// Maximum value of light sensor reading
const int minBrightness = 0;    // Minimum brightness value for LED
const int maxBrightness = 255;  // Maximum brightness value for LED

// Variables
int sensorValue = 0; 
int ledBrightness = 0;

// Function to map a value from one range to another
double mapValue(double value, double fromLow, double fromHigh, double toLow, double toHigh) {
  return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}





/*
 * Project lab5
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(ledPin, OUTPUT);        // Set LED pin as output
  Particle.variable("brightness", ledBrightness);  // Expose brightness variable
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // Read the light sensor value
  sensorValue = analogRead(lightSensorPin);

  // Map the light sensor value to the LED brightness range
  ledBrightness = round(mapValue(sensorValue, minSensorValue, maxSensorValue, minBrightness, maxBrightness));

  // Update the LED brightness
  analogWrite(ledPin, ledBrightness);

  // Delay before next reading
  delay(1000);
}