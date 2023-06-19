#include <SPFD5408_Adafruit_GFX.h>    //--> Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> //--> Hardware-specific library
#include <SPFD5408_TouchScreen.h>
#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal

#endif
#define YP A1 //--> must be an analog pin, use "An" notation!
#define XM A2 //--> must be an analog pin, use "An" notation!
#define YM 7  //--> can be a digital pin
#define XP 6  //--> can be a digital pin

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

// optional
#define LCD_RESET A4 //arduino nano reset pin

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BLACKM  0x18E3

#define TS_MAXX 919
#define TS_MAXY 865
#define TS_MINX 145
#define TS_MINY 82

#define MINPRESSURE 10
#define MAXPRESSURE 1000

void setup(void){
Serial.begin(9600);
tft.reset();
tft.begin(0x9341);
tft.setRotation(1);
tft.fillScreen(WHITE);
drawgraph();

tft.fillRoundRect(140,190 ,40,40 ,7, BLACKM);
tft.fillTriangle(10, 210,60,190 ,60, 230, BLACKM);
tft.fillTriangle(310,210,260,190,260,230,BLACKM);
tft.drawLine(59,15,59,185,BLACK);
tft.drawLine(59,185,295,185,BLACK);
tft.setRotation(0);




tft.setCursor(90, 40);
tft.setTextSize(2);
tft.setTextColor(BLACKM);
tft.print("ENCODER");
pot();
}
void pot(){
  pinMode(A5,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:


}
void drawgraph(){
// line parellel to yaxis

for(int y=60;y<=320;y+=26){

  tft.drawFastVLine(y,15,172,BLACK);

}
for(int x=15;x<=193;x+=19.5){
  tft.drawFastHLine(60 ,x ,235,BLACK);
}
}
