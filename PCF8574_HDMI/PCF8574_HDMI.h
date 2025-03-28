#ifndef PCF8574_HDMI_H
#define PCF8574_HDMI_H

#include <Arduino.h>
#include <Wire.h>

class PCF8574_HDMI {
public:
    // Constructor: Initialize with I2C address
    PCF8574_HDMI(uint8_t address);

    // Initialize the PCF8574 device
    void initial();

    // Set resolution of the display
    void resolution(uint16_t x, uint16_t y);

    // Set rotation of the display
    void rotation(uint8_t degree);

    // Send data to display content
    void display();

    // Change display orientation
    void orientation(uint8_t mode);

    // Adjust the display refresh rate
    void displayRefreshRate(uint16_t frequency);

    // Detect connected HDMI device
    bool detect();

    // Identify connected HDMI device
    String identify();

    // Enable sleep mode
    void sleepMode(bool enable);

    // Finalize and reset HDMI
    void final();

private:
    uint8_t _address;  // I2C address of the PCF8574
    uint8_t _state;    // Current state of all 8 channels (P0-P7)
};

#endif