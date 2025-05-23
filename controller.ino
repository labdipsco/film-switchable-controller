/*
  Code for controlling darkening panels (Sperandio)
  Valid commands:
  oe       → sets pinRele HIGH
  ce       → sets pinRele LOW
  O2000E   → sets pinRele HIGH for 2000 ms, then LOW
  C2000E   → sets pinRele LOW for 2000 ms, then HIGH
*/

// Comment for Tinkercad simulation
#include <Arduino.h>

// Definition of the pin connected to the relay
const int pinRele = 7;

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(195000);

    // Set all valid pins as OUTPUT and turn them off
    pinMode(pinRele, OUTPUT);
}

// Clear serial buffer
void clearSerialInput() {
    while (Serial.available() > 0) {
        Serial.read();
    }
}

bool isDigitChar(char c) {
    return (c >= '0' && c <= '9');
}

unsigned long startTime;
unsigned long currentTime;
int startPinValue;
int pin;

unsigned long uno;
unsigned long due;

void loop() {

      if (Serial.available() > 0) {
        uno = micros();
        char firstChar = Serial.read();

        if (firstChar == 'o') {
            digitalWrite(pinRele, HIGH);
            return;
        }

        if (firstChar == 'c') {
            digitalWrite(pinRele, LOW);
            return;
        }

        if ((firstChar == 'O') || (firstChar == 'C')) {

            String rxBuffer = Serial.readStringUntil('E');

            // Extract the designated time
            long int duration = rxBuffer.toInt();
            duration = duration * 1000; // ms to microseconds

            // Check if the command is Open or Close
            if (firstChar == 'O') {
                startPinValue = HIGH;
            } else if (firstChar == 'C') {
                startPinValue = LOW;
            } else {
                return;
            }

            // Determine final pin state for the end of the cycle
            int stopPinValue = (startPinValue == HIGH) ? LOW : HIGH;

            digitalWrite(pinRele, startPinValue);
            due = micros();
            // due = micros();

            // Start counting the time
            startTime = micros();
             
            // Wait for the indicated time
            while (micros() - startTime < duration);

            digitalWrite(pinRele, stopPinValue);
            

            // Clear any extra commands that arrived during the delay
            clearSerialInput();
            
            // Serial.println(due - uno);
        }
    } // end if Serial.available()
} // end loop
