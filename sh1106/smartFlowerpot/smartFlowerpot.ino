//vochtigheidsmeter
int mositure = 0; // Value to store the humidity value
int YL100OUT = A0; // Variable for the number of the analog pin to which the sensor is connected
int YL100VCC = 3; // Variable for pin number for sensor power supply

//screen

#include <SPI.h>
#include <Wire.h>
#include "sh1106.h"

#define VCCSTATE SH1106_SWITCHCAPVCC
#define WIDTH     128
#define HEIGHT     64
#define NUM_PAGE    8  /* number of pages */

#define OLED_RST    9
#define OLED_DC     8
#define OLED_CS    10
#define SPI_MOSI   11    /* connect to the DIN pin of OLED */
#define SPI_SCK    13     /* connect to the CLK pin of OLED */

uint8_t oled_buf[WIDTH * HEIGHT / 8];


void setup() {
  //vochtigheidsmeter
  Serial.begin(9600); // Open the serial bus via USB
  pinMode(YL100VCC, OUTPUT); // Set the power pin to the output
  digitalWrite(YL100VCC, LOW); // Set the power level to LOW after power on

  //screen
  SH1106_begin();
  SH1106_clear(oled_buf);
}
  int readYL100() // Function of reading data from the sensor
  {
    digitalWrite(YL100VCC, HIGH); // Turn on the sensor power
    delay(10); // Delay of 10 milliseconds
    mositure = analogRead(YL100OUT); // Read the value from the sensor pin OUT
    digitalWrite(YL100VCC, LOW); // Turn off the power;
    return mositure; // Return the read value
  }


void loop() {

  Serial.print("Soil moisture = "); // Print the output line prefix
  Serial.println(readYL100()); // Get the moisture value from the function and print it
  if (mositure > 600) {
    SH1106_clear(oled_buf);
    SH1106_bitmap(31, 0, toMuchWater, 64, 64, oled_buf);
    SH1106_display(oled_buf);
    delay(5000);
  } else if (mositure >= 400 && mositure <= 600) {
    SH1106_clear(oled_buf);
    SH1106_bitmap(31, 0, good, 128, 128, oled_buf);
    SH1106_display(oled_buf);
    delay(5000);
  } else if (mositure < 400) {
    SH1106_clear(oled_buf);
    SH1106_bitmap(0, 0, needWater, 128, 128, oled_buf);
    SH1106_display(oled_buf);
    delay(3600000);
  }

}
