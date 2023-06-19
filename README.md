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

![20230329_070803.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/20230329_070803.jpg)

![20230329_070749.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/20230329_070749.jpg)

## Code

[https://github.com/Thesuryagyawali/Smart-Motors-with-arduino](https://github.com/Thesuryagyawali/Smart-Motors-with-arduino)

[Prajwolbohara0802/Smart-Motors-with-arduino at Prajwolbohara0802-patch-1 (github.com)](https://github.com/Prajwolbohara0802/Smart-Motors-with-arduino/tree/Prajwolbohara0802-patch-1)

## Module and Circuit

![IMG-20230405-WA0001.jpeg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/IMG-20230405-WA0001.jpeg)

![IMG-20230405-WA0003.jpeg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/IMG-20230405-WA0003.jpeg)

## Data Sheets/ Reading Resources

[LCD-01-024-Datasheet (1).pdf](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/LCD-01-024-Datasheet_(1).pdf)

[https://www.instructables.com/Arduino-24-Touch-Screen-LCD-Shield-Tutorial/](https://www.instructables.com/Arduino-24-Touch-Screen-LCD-Shield-Tutorial/)

# Feb 1 week

**Working with TFT 2.4 screen**

    **Driver: - 0x9341**

- All the Digital pins of TFT should connect to Arduino UNO for working with the screen because it’s a bus pin each pin is connected with each other.
- All the analog pin of the Arduino must have to connect with the LCD pin of the TFT screen.

**To use a digital pin as an analog input, you will need to use a voltage divider circuit to reduce the voltage of the signal you want to measure to within the range of the analog-to-digital converter (ADC) on the Arduino. You can then connect the output of the voltage divider to the digital pin on the Arduino, and use the analog Read () function to read the voltage and convert it to a digital value that can be used in your code.**

# Pin Number for TFT LCD Display

## **TFT Display calibration.**

### **Calibration value for my TFT**

```cpp
#define TS_MAXX 919
#define TS_MAXY 865
#define TS_MINX 145
#define TS_MINY 82
```

### **For digital and analog pin**

```cpp
#define YP A1 
#define XM A2
#define YM 7  
#define XP 6
```

### for mapping value

```cpp
p.x = map(p.x, TS_MINX, TS_MAXX, 0,tft.height());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
```

Working with the TFT screen 

- [x]  Attaching the Servo motor and rotated

There is 6 analog pin in Arduino, among which 5 pin is used for TFT display, 1 analog pin is used for reading pot value, we are having a problem for connecting other devices because of limit analog pin in Arduino uno.

- Can we use a digital pin for reading analog value in Arduino uno?

Note:- Arduino nano/mini is best alternative board for smart motor and cheap option because we get 8 analog pin in Arduino nano.

![Snapchat-644848723.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-644848723.jpg)

![WhatsApp Image 2023-02-05 at 21.19.44.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/WhatsApp_Image_2023-02-05_at_21.19.44.jpg)

![Snapchat-637569719.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-637569719.jpg)

![Snapchat-163724475.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-163724475.jpg)

[Snapchat-1969261209.mp4](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-1969261209.mp4)

![Snapchat-1963615135.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-1963615135.jpg)

![2.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/2.jpg)

![WhatsApp Image 2023-02-28 at 21.23.21.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/WhatsApp_Image_2023-02-28_at_21.23.21.jpg)

![Snapchat-1030072278.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-1030072278.jpg)

![Snapchat-1517314236.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/Snapchat-1517314236.jpg)

![3.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/3.jpg)

![20230208_081456.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/20230208_081456.jpg)

Experimentation on Arduino Nano

# Smart motor TFT screen with the Arduino nano

*NOTE*➖

- it’s optional to connect Arduino 5v to 5V pin of TFT screen because TFT can easily powerup with the help of 3.3 V
- I prefer connecting the LCD_RST pin of TFT with the RST pin of the Arduino because it left a option to connect the other analog reading device.

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

| analog device  | Arduino pin |
| --- | --- |
| pot | A5 |
| LDR | A6 |
| accelerometer | A7 |
- [x]  Working with GY-61 accelerometer
- [x]  Reading the value from 10k pot
- [x]  Reading the accurate value from the ldr
- [x]  Reading the value of accelerometer and how it really works

LDR value Reading

For reading the ldr value 1 pin of ldr must be connected with 5 v and another pin must connected with analog read A0 further around 1k resistor must connected with 1 pin grounded and one connecting with the ldr pin which is included in analog pin

pot Reading 

for reading the value from the pot middle pin of the pot must have the connect with A5

and side pin of pot should connected with the 5 v and gnd.

Training module graph

## **Storage in the Arduino nano**

Maximum is 30720 bytes.

![345003258_598082802298678_5555715089835656695_n.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/345003258_598082802298678_5555715089835656695_n.jpg)

![343033421_770930424416711_6568535535736997349_n.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/343033421_770930424416711_6568535535736997349_n.jpg)

![IMG_20230316_150415_805.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/IMG_20230316_150415_805.jpg)

![20230505_063046.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/20230505_063046.jpg)

![IMG_20230425_222151_819.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/IMG_20230425_222151_819.jpg)

![IMG_20230425_222209_884.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/IMG_20230425_222209_884.jpg)

![343566467_169662959073536_1008882062306732158_n.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/343566467_169662959073536_1008882062306732158_n.jpg)

![IMG_20230327_162633_635.jpg](Smart%20Motors%20using%20Arduino%20c2e0098330564f6db3aee58281a698de/IMG_20230327_162633_635.jpg)
