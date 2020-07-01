# Simple ESC
![PlatformIO compile](https://github.com/dejanmeznarc/SimpleESC/workflows/PlatformIO%20compile/badge.svg)

Library for ESP chips only!

Library enables communication to ESCs using PWM on steroids.


# Protocol
Protocol is similar to standard Servo PWM pulse, 
only refresh interval can be changed.

## Compatibility
Most of stock ESCs.

## Tweaks
Default Servo PWM uses REFRESH_INTERVAL of 20 ms. 
This library uses 3 ms insted.


```
      |           REFRESH_INTERVAL             |
      | <------------------------------------> |       
      |                  3ms                   |
      V                                        V 
     
      |--------|                               |-------|
      |        |                               |       |
      |        |                               |       |
------|        |-------------------------------|       |---------
```

## Tested
* Charisse yellow 30A ESCs (unbranded)
* SimonK 30A

