#include <PCF8574_HDMI.h>

// Define I2C address for PCF8574
#define PCF8574_ADDRESS 0x20

// Create PCF8574_HDMI object
PCF8574_HDMI hdmi(PCF8574_ADDRESS);

void setup() {
    Serial.begin(9600);
    hdmi.initial();             // Initialize HDMI
    hdmi.resolution(1920, 1080); // Set resolution
    hdmi.rotation(90);           // Rotate display
    hdmi.displayRefreshRate(60); // Set refresh rate
}

void loop() {
    if (hdmi.detect()) {
        Serial.println("HDMI device detected.");
        Serial.println("Identified as: " + hdmi.identify());
        hdmi.display();
        delay(5000);
        hdmi.sleepMode(true);
        delay(2000);
        hdmi.sleepMode(false);
    } else {
        Serial.println("No HDMI device detected.");
    }
    delay(10000);
}