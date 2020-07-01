#include <Arduino.h>
#include "SimpleESC.h"


// specify the pin here
SimpleESC motor(15);


void setup() {
    // Attaching motor will set pin to OUTPUT and and started making PWM pulse.
    // Since default pulse is 0, no pulse will be generated.
    motor.attach();

    // unlock ESC
    motor.write(1000);
    delay(1000);

}

void loop() {


    for (int i = 1000; i < 2000; ++i) {

        // Write microseconds
        motor.write(i);

        //wait for 10ms just for fun :)
        // changes take effect every REFRESH_INTERVAL (defined in SimpleESC.h)
        delay(10);
    }

    // Disable motor/stop generating PWM pulse
    motor.detach();
    delay(5000);

    // Enable motor again. Motor speed will not be overwritten!
    motor.attach();
    delay(5000);


    // Read last thing that was written to motor.
    if(motor.read() > 1000){
        // do something
    }


}

