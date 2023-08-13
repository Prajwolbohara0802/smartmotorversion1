# Smart Motors using Arduino

React to this comment or reply here to show your support on this project.

## Components Needed

[Arduino Nano](https://static-01.daraz.com.np/p/9f4c40402cecd5b19b21ea068286c35f.jpg_720x720.jpg_.webp)

[TFT LCD Screen](https://udvabony.com/wp-content/uploads/2019/04/2.4-inch-tft-lcd-shield-for-arduino.jpg)

## Library Needed

Adafruit_GFX.h
Touchscreen.h
Adafruit_TFTLCD.h

[FZP71N4IT58ZZL4.zip](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/FZP71N4IT58ZZL4.zip)

All of these library can be found in Arduino IDE

| TFT pin  | Arduino Pin |
| --- | --- |
| LCD_RD | A0 |
| LCD_WR | A1 |
| LCD_RS | A2 |
| LCD_CS | A3 |
| LCD_RST (optional) | A4 |
| LCD_D0 |  8 |
| LCD_D1 | 9 |
| LCD_D2 | 2 |
| LCD_D3 | 3 |
| LCD_D4 | 4 |
| LCD_D5 | 5 |
| LCD_D6 | 6 |
| LCD_D7 | 7 |
| GND | GND |
| 3.3v  | 3.3 v |
- [x]  

## Pin that are used

| analog device  | Arduino pin |
| --- | --- |
| Sensor | A5 |
|  |  |
|  |  |
- it’s optional to connect Arduino 5v to 5V pin of TFT screen because TFT can easily powerup with the help of 3.3 V
- I prefer connecting the LCD_RST pin of TFT with the RST pin of the Arduino because it left a option to connect the other analog reading device.
- **5V**: Module power supply – 5 V
- **3**.**3V**: Module power supply – 3.3 V
- **GND**: Ground
- **LCD_RST**: LCD bus reset signal, low level reset
- **LCD_CS**: LCD bus chip select signal, low level enable
- **LCD_RS:** LCD bus command / data selection signal, low level: command, high level: data
- **LCD_WR:** LCD bus write signal
- **LCD_RD:** LCD bus read signal
- **LCD_D0:** LCD 8-bit data Bit0
- **LCD_D1:** LCD 8-bit data Bit1
- **LCD_D2:** LCD 8-bit data Bit2
- **LCD_D3:** LCD 8-bit data Bit3
- **LCD_D4:** LCD 8-bit data Bit4
- **LCD_D5:** LCD 8-bit data Bit5
- **LCD_D6:** LCD 8-bit data Bit6
- **LCD_D7:** LCD 8-bit data Bit7

