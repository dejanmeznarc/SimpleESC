//
// Created by Dejan on 30. 06. 2020.
//

#ifndef SIMPLEESC_SIMPLEESC_H
#define SIMPLEESC_SIMPLEESC_H

#include <Arduino.h>



// the following are in us (microseconds)
//
#define REFRESH_INTERVAL     3000     // minumim time to refresh servos in microseconds


#if defined(ESP8266)
#include "core_esp8266_waveform.h"
#else
#error "This library only supports ESP chips"
#endif



class SimpleESC {
public:
    SimpleESC(uint8_t pin);
    ~SimpleESC();


    void write(unsigned long microseconds);

    void attach();

    void detach();

private:
    const uint8_t _pin;
    unsigned long  _valueUs;
    bool _attached;
};


#endif //SIMPLEESC_SIMPLEESC_H
