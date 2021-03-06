/**
  ******************************************************************************
  * @file    sh1106.h
  * @author  Waveshare Team
  * @version
  * @date    21-June-2017
  * @brief   This file includes the OLED driver for SH1106 display moudle
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, WAVESHARE SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  ******************************************************************************
  */

#ifndef _SH1106_H_
#define _SH1106_H_

#include <avr/pgmspace.h>

#define VCCSTATE SH1106_SWITCHCAPVCC
#define WIDTH   128
#define HEIGHT   64
#define NUM_PAGE  8

#define OLED_RST  9
#define OLED_DC   8
#define OLED_CS  10
#define SPI_MOSI 11     /* connect to the DIN pin of OLED */
#define SPI_SCK  13     /* connect to the CLK pin of OLED */

void SH1106_begin();
void SH1106_display(uint8_t* buffer);
void SH1106_clear(uint8_t* buffer);
void SH1106_pixel(int x,int y,char color, uint8_t* buffer);
void SH1106_bitmap(uint8_t x,uint8_t y,const uint8_t *pBmp, uint8_t chWidth, uint8_t chHeight, uint8_t* buffer);
void SH1106_char1616(uint8_t x,uint8_t y,uint8_t chChar, uint8_t* buffer);
void SH1106_char3216(uint8_t x, uint8_t y, uint8_t chChar, uint8_t* buffer);
void SH1106_string(uint8_t x, uint8_t y, const char *pString, uint8_t Size, uint8_t Mode, uint8_t* buffer);
void SPIWrite(uint8_t *buffer, int bufferLength);
void command(uint8_t cmd);

extern const uint8_t Font1612[11][32];
extern const uint8_t Font3216[11][64];
extern const uint8_t good[1024];
extern const uint8_t needWater[1024];
extern const uint8_t toMuchWater[1024];

#endif
