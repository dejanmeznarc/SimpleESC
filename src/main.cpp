#include <Arduino.h>
#include "SimpleESC.h"


SimpleESC motor(15);


void setup() {
    motor.attach();

    motor.write(1000);
    delay(1000);
    motor.write(1100);
    delay(10000);

}

void loop() {

}