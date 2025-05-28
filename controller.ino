/*
  ------------------------------------------------------------------------
  USB-Controlled Switchable Film Controller
  ------------------------------------------------------------------------

  DISCLAIMER:
  This code is provided "as is" for educational and research purposes only.

  By using or modifying this code, you acknowledge and agree that:
  - The authors and contributors are not responsible for any damage, injury,
    or legal consequences resulting from the use or misuse of this software.
  - You are solely responsible for ensuring the correct and safe connection
    of all electrical components, especially when dealing with high-voltage AC.
  - This software is not certified for commercial or industrial applications,
    and should only be used in controlled, low-risk environments (e.g., labs).
  - Always test and verify functionality in a safe setup before real-world use.
  - If you are not familiar with electronics or safety standards, consult a
    qualified technician before proceeding.

  Use at your own risk.

  ------------------------------------------------------------------------
*/
/*
  Code for controlling darkening panels (Sperandio)
  Valid commands:
  o       → sets pinRele HIGH
  c       → sets pinRele LOW
  O2000E   → sets pinRele HIGH for 2000 ms, then LOW
  C2000E   → sets pinRele LOW for 2000 ms, then HIGH
*/

// Comment for Tinkercad simulation
//#include <Arduino.h>

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

unsigned long startTime;
int startPinValue;
int pin;


void loop() {

      if (Serial.available() > 0) {
        
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
            
            // Start counting the time
            startTime = micros();
             
            // Wait for the indicated time
            while (micros() - startTime < duration);

            digitalWrite(pinRele, stopPinValue);
            

            // Clear any extra commands that arrived during the delay
            clearSerialInput();
            
        }
    } // end if Serial.available()
} // end loop
