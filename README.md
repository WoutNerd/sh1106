# sh1106
For this project you need a oled display sh1106 and a ground mositure meter YL-100.

pins from display to Arduino
          RES/RST   9
          DC        8
          CS        10
          DIN/MOSI  11
          SCK/CLK   13
          VCC       3V/5V (i used 5V but it will work to on 3Và
          GND       GND
          
pins from the mositure meter to Arduino
              VCC                3
              OUT                A0
              GND                GND
              
              
sh1106.cpp and sh1106.h are drivers and libraries for the display.
