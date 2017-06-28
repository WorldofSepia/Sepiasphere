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
#define MAXPRGS 12  // Maximum available programs


// Variables
bool outLeft = true;    // Is left output selected?
bool outRight = false;  // Is right output selected?


// Configuration
// https://playground.arduino.cc/Code/EEPROMLoadAndSaveSettings

// Constants
#define CONFIG_OFFSET 32        // EEPROM configuration offset
#define CONFIG_VERSION "v01"    // EEPROM versoin check/magic number

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
        // TODO UMaybe use EEPROM.put()
        EEPROM.update(CONFIG_OFFSET + i, *((char*)&conf + i));
    }
}


// Setup routine
void setup() {
    // Serial
    // TODO Do we need a serial connection, e.g. for debugging?
    //Serial.begin(9600);

    // Read data from EEPROM
    Config conf;
    loadConfig(&conf);

    // I/O
    // Step switch
    int inputs[] = {A0, A1, A2, A3, A4, A5, A6, 2, 3, 4, 5, 6};
    size_t size = sizeof(inputs) / sizeof(inputs[0]);
    for (unsigned int i = 0; i < size; i++) {
        pinMode(inputs[i], INPUT_PULLUP);
    }

    // Potentiometer
    pinMode(A7, INPUT);

    // Left/Both/Right selection
    // TODO Implement
    //pinMode(AX, INPUT);
    //pinMode(AY, INPUt);

    // Define outputs
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);

    // Initialize LED rings
    // TODO Implement

}


// Main loop
void loop() {
    // TODO Implement everything here

    // Read output switch (left/both/right)

    // Read Step Switch


    // Read Potentiometer


    // Save on configuration


    // Change LED rings…


}
