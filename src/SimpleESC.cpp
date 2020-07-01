//
// Created by Dejan on 30. 06. 2020.
//

#include "SimpleESC.h"

SimpleESC::SimpleESC(uint8_t pin) : _pin(pin) {}

SimpleESC::~SimpleESC() {
    detach();
}


void SimpleESC::detach() {
    if (_attached) {
        stopWaveform(_pin);
    }
    _attached = false;
    digitalWrite(_pin, LOW);

}

void SimpleESC::attach() {
    if (!_attached) {
        digitalWrite(_pin, LOW);
        pinMode(_pin, OUTPUT);
        _attached = true;
    }
    write(_valueUs);
}

void SimpleESC::write(unsigned long microseconds) {
    _valueUs = microseconds;

    if (_attached && _valueUs < REFRESH_INTERVAL) {

        startWaveform(_pin, _valueUs, REFRESH_INTERVAL - _valueUs, 0);
    }

}

unsigned long SimpleESC::read() {
    return _valueUs;
}
