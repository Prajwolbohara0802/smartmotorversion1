#include <Arduino.h>
#include<SPFD5408_Adafruit_GFX.h>
#include<SPFD5408_Adafruit_TFTLCD.h>
#include<SPFD5408_TouchScreen.h>


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
#define LCD_RESET A4  //optional
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


void setup() {
  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
tft.drawLine(81,5,81,178,BLACK);
tft.drawLine(81,177,315,177,BLACK);

  button();
  drawgraph();
  runbox();
  deletebox();
  backbox();
  sensorname();
}
void button(){
   tft.fillRoundRect(140,195 ,40,40 ,5, BLACKM);
tft.fillTriangle(10, 218,55,198 ,55, 238, BLACKM);
tft.fillTriangle(310,218,265,198,265,238,BLACKM);
}
void runbox(){
 tft.fillRoundRect(10,130,35,35,5,BLACKM);
 tft.fillTriangle(40,146.5 ,20,133 ,20,160, GREEN);
}
void deletebox(){
  tft.fillRoundRect(10,80,35,35,5,BLACKM);
    tft.setRotation(1);
tft.setCursor(17, 84);
tft.setTextSize(4);
tft.setTextColor(RED);
tft.print("X");
}
void backbox(){
  tft.fillRoundRect(10,30,35,35,5,BLACKM);
   tft.fillTriangle(15,45 ,35,32 ,35,58, BLUE);
}

void drawgraph(){
// line parellel to yaxis

for(int y=82;y<=320;y+=26){

  tft.drawFastVLine(y,5,172,BLACKM);

}
for(int x=5;x<=193;x+=19.5){
  tft.drawFastHLine(82 ,x ,235,BLACKM);


}
}
void sensorname(){
tft.setRotation(0);
tft.setCursor(105, 60);
tft.setTextSize(2);
tft.setTextColor(BLACKM);
tft.print("ENCODER");

// max
tft.setRotation(1);
tft.setCursor(62,5);
tft.setTextSize(1);
tft.setTextColor(BLACKM);
tft.print("Max");
// 180

tft.setRotation(1);
tft.setCursor(300,180);
tft.setTextSize(1);
tft.setTextColor(BLACKM);
tft.print("180");
//0
tft.setRotation(1);
tft.setCursor(62,180);
tft.setTextSize(1);
tft.setTextColor(BLACKM);
tft.print("Min");
}



void loop() {
 run();

}
int  run(){
for(int i=159;i>=7;i-=19){
tft.fillRect(84, i, 22,15,BLACKM); 
} 
for(int z=84;z<=292;z+=26){
tft.fillRect(z, 159, 22,15,BLACKM); }
}