
/**********************************************************************************
 * 
 * Interfacing Arduino with ST7565 Monochrome LCD (128x64 Pixel)
 * This is a free software with NO WARRANTY - Use it at your own risk!
 * https://simple-circuit.com/
 *
***********************************************************************************
 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
************************************************************************************
 Modified to work with ST7565 Monochrome LCD.
 https://simple-circuit.com/
 **********************************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <ST7565_LCD.h>

// ST7565 LCD connection with Arduino board using software SPI
#define LCD_DIN    9
#define LCD_SCLK   8
#define LCD_A0     7
#define LCD_RESET  6
#define LCD_CS     5
ST7565_LCD display = ST7565_LCD(LCD_DIN, LCD_SCLK, LCD_A0, LCD_RESET, LCD_CS);

/*/ Comment out above, uncomment this block to use hardware SPI
// connect LCD 'DIN' & 'SCLK' to board's hardware SPI pins
#define LCD_A0     7
#define LCD_RESET  6
#define LCD_CS     5
ST7565 display = ST7565(LCD_A0, LCD_RESET, LCD_CS);
*/


void setup()   {                
  Serial.begin(9600);

  // initialize the ST7565 LCD display with contrast = 12 (0 <= coontrast <= 63)
  display.begin(13);

  
  // Clear the buffer
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(ST7565_ON); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.println(F("Hello, world!"));
  
  display.display();
  delay(2000);

  // Invert and restore display, pausing in-between
  display.invertDisplay(true);
   display.display();
  delay(1000);
  display.invertDisplay(false);
   display.display();
  delay(1000);

}

// main loop (nothing here!)
void loop() {

}



