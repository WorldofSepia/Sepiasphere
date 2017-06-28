/**
 * Sepiasphere Source Code for Arduino Nano
 *
 * https://github.com/WorldofSepia/Sepiasphere
 *
 * Copyright (c) 2017, Authors are available via git history
 * 
 * Licensed under GPLv3, see the LICENSE file for more information
 *
 */


// Includes
#include <EEPROM.h>


// Constants
static const unsigned int IN_STEP_SWITCH[] = {A0, A1, A2, A3, A4, A5, A6, 2, 3, 4, 5, 6};   // Step switch input pins
static const unsigned int MAXPRGS = sizeof(IN_STEP_SWITCH); // Maximum available programs
static const unsigned int IN_POTI = A7; // Analog input of potentiometer
static const unsigned int IN_1 = 9;     // Input/LED ring 1 active?
static const unsigned int IN_2 = 10;    // Input/LED ring 2 active?
static const unsigned int OUT_1 = 7;    // Output LED ring 1
static const unsigned int OUT_2 = 8;    // Output LED ring 2


// Configuration
// https://playground.arduino.cc/Code/EEPROMLoadAndSaveSettings

// Constants
static const unsigned int CONFIG_OFFSET = 32;       // EEPROM configuration offset
static const unsigned char CONFIG_VERSION[] = "v01";// EEPROM versoin check/magic number

// Config data type
struct Config {
    // Version check
    char version[4];
    // Variables
    int out1prg;
    int out1pwm;
    int out2prg;
    int out2pwm;
};

// Load configuration
void loadConfig(struct Config *conf) {
    // Check version
    if (EEPROM.read(CONFIG_OFFSET + 0) == CONFIG_VERSION[0] && EEPROM.read(CONFIG_OFFSET + 1) == CONFIG_VERSION[1] && EEPROM.read(CONFIG_OFFSET + 2) == CONFIG_VERSION[2]) {
        // Load configuration
        // TODO Maybe use EEPROM.get()
        for (unsigned int i=0; i<sizeof(conf); i++) {
            *((char*)&conf + i) = EEPROM.read(CONFIG_OFFSET + i);
        }
    } else {
        // Set default values
        memcpy(conf->version, CONFIG_VERSION, sizeof(conf->version));
        conf->out1prg = 0;
        conf->out1pwm = 512;
        conf->out2prg = 0;
        conf->out2pwm = 512;
        // And save them
        saveConfig(conf);
    }
    // Check configuration
    if ( conf->out1prg < 0 || conf->out1prg > MAXPRGS ) {
        conf->out1prg = 0;
    }
    if ( conf->out1pwm < 0 || conf->out1pwm > 1024 ) {
        conf->out1pwm = 512;
    }
    if ( conf->out2prg < 0 || conf->out2prg > MAXPRGS ) {
        conf->out2prg = 0;
    }
    if ( conf->out2pwm < 0 || conf->out2pwm > 1024 ) {
        conf->out2pwm = 512;
    }
}

// Save confuration
void saveConfig(struct Config *conf) {
    for (unsigned int i=0; i<sizeof(conf); i++) {
        // TODO Maybe use EEPROM.put()
        EEPROM.update(CONFIG_OFFSET + i, *((char*)&conf + i));
    }
}


// Setup routine
void setup() {
    // Read data from EEPROM
    Config conf;
    loadConfig(&conf);

    // I/O
    // Step switch
    for (unsigned int i = 0; i < MAXPRGS; i++) {
        pinMode(IN_STEP_SWITCH[i], INPUT_PULLUP);
    }

    // Potentiometer
    pinMode(IN_POTI, INPUT);

    // Input (1/2/both)
    pinMode(IN_1, INPUT_PULLUP);
    pinMode(IN_2, INPUT_PULLUP);

    // Define outputs
    pinMode(OUT_1, OUTPUT);
    pinMode(OUT_2, OUTPUT);

    // Initialize LED rings
    // TODO Implement

}


// Main loop
void loop() {
    // Read output switch (1/2/both)
    

    // Read Step Switch


    // Read Potentiometer


    // Save on configuration


    // Change LED rings…


}
