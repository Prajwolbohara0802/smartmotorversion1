#include<SPFD5408_Adafruit_GFX.h>
#include<SPFD5408_Adafruit_TFTLCD.h>
#include<SPFD5408_TouchScreen.h>
#include<Servo.h>
Servo servo_pin;

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
int u=1;
int count=0;
int pages=1;
int q=159;
int analog=0;
 int t=84;
 int distance=0;
 int potval=0;
int read[30][3];
int servopin=12;

void setup(void) {
pinMode(13,OUTPUT);
pinMode(A5,INPUT);
pinMode(A6,OUTPUT);
pinMode(A7,OUTPUT);
pinMode(servopin,OUTPUT);
servo_pin.attach(servopin);

  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9341);
frontpage();
setting();

}

void graph(){               // training  mode display code
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
void frontpage(){    // karkhana samuha page
tft.setRotation(1); 

  drawBorder();
  
  // Initial screen
  
  tft.setCursor (90, 50);
  tft.setTextSize (2);
  tft.setTextColor(RED);
  tft.println("Smart Motors");
  tft.setTextColor(BLACK);
  
  tft.setCursor (120, 85);
  tft.println("(Mark I)");
  
  tft.setCursor (85, 150);
  tft.setTextSize (2);
  tft.setTextColor(BLACK);
  tft.println("Karkhana Samuha");

  tft.setCursor (125, 200);
  tft.setTextSize (1);
  tft.setTextColor(BLACK);
  tft.println("Touch to proceed");

  // Wait touch

  waitOneTouch();
  setting();
}
void setting(){    // select sensor page
 
tft.setRotation(1);
tft.fillScreen(WHITE);
tft.fillRoundRect(30,75,84,84,10,BLUE);
tft.drawRect(40,85,63,45,GREEN);
tft.fillRect(45,90,53,35,GREEN);
tft.fillCircle(45, 90+35, 8, RED);
tft.fillRect(40,90+47,10,13,RED);
tft.drawLine(50,90+50,60,90+27,RED);
tft.drawLine(50,90+51,60,90+28,RED);
 
tft.fillRoundRect(200,75,84,84,10,BLUE);
//tft.drawCircle(220,80,10,GREEN);
tft.fillCircle(243,115,25,GREEN);  // settings UI
tft.fillCircle(243,115,13,WHITE);
tft.fillCircle(243,115,9,BLUE);

tft.fillCircle(243,115+25,7,GREEN);
tft.fillCircle(243,115-25,7,GREEN);
tft.fillCircle(243-25,115,7,GREEN);
tft.fillCircle(243+25,115,7,GREEN);
tft.fillCircle(225,115+18,8,GREEN);
tft.fillCircle(225,115-18,8,GREEN);
tft.fillCircle(225+35,115+18,8,GREEN);
tft.fillCircle(225+35,115-18,8,GREEN);


}
void button(){                                      // display code 
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
  tft.fillRoundRect(10,30,35,35,5,BLACKM);        // for the training mode
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
/*
if (sensor ==1){
  tft.print("ENCODER");

}
else if(sensor==2){
  tft.print("LIGHT");
}
else {
  tft.print("ACCELERO");
}
*/
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
tft.print("Min");  // for the training mode
}
void sense(){   // select sensor display code
  tft.setRotation(1);
tft.fillScreen(WHITE);
tft.fillRoundRect(30,75,84,84,10,RED);
  tft.setCursor (45, 107);
  tft.setTextSize (2);
  tft.setTextColor(WHITE);
  tft.println("Pot");
  
  tft.fillRoundRect(200,75,84,84,10,BLUE);
  tft.setCursor (215, 107);
  tft.setTextSize (2);
  tft.setTextColor(WHITE);
  tft.println("Tilt");
  
  }
void loop() {
  digitalWrite(13,HIGH);            // touch code 
 TSPoint p= ts.getPoint();
 digitalWrite(13,LOW);


pinMode(XM,OUTPUT);
pinMode(YP,OUTPUT);
p.x = map(p.x, TS_MINX, TS_MAXX, 0,tft.height());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
 
  int y_set = map(p.x, 0, 240, 0, tft.height());
  int x_set = map(tft.width() - p.y, 0, 320, 0, tft.width());
if (p.z >MINPRESSURE && p.z< MAXPRESSURE) {
//Serial.print("X=");
//Serial.println(p.x);
//Serial.print("Y=");
//Serial.println(p.y);
if (p.x > 111 && p.x < 126 && p.y > 70 && p.y < 203){
   trainingbutt();
   graph();
}
if (p.x > 101 && p.x < 167 && p.y >25 && p.y < 83)
{
    sensorbutton();
    sense();
    //selectsensor();
}
if (p.x > 46 && p.x < 72 && p.y > 253 && p.y < 266){
  backbutton();
  //setting();
setting();
count=0;
}
if (p.x > 152 && p.x < 175 && p.y > 205 && p.y < 237){
  runbutton();
  runmode();
 algorithm();

}

if (p.x > 214 && p.x < 214 +40 && p.y > 100 && p.y < 100+40)
{
   
  drawselectbuttonpressed();

  count=count+1;
  
  if(count<13){
    
  read[count][0]=u;
  read[count][1]=q;
  read[count][2]=t;

  }
   tft.fillRect(read[count][2],read[count][1],22,15,GREEN);
  delay(100);
}


if (p.x > 214 && p.x < 233 && p.y > 180 && p.y < 194){
  drawtriangle1();
  
  run();
  u=u-1;

}
if (p.x > 214 && p.x < 214 +40 && p.y > 15 && p.y < 31){
  drawtriangle2();
  
   run();
  u=u+1;
 
 
}
}
}
void runmode(){
   tft.setRotation(1);
  tft.fillScreen(CYAN);
tft.drawLine(81,5,81,178,BLACK);
tft.drawLine(81,177,315,177,BLACK);
  button();
  drawgraph();
  runbox();
  deletebox();
  backbox();
  sensorname(); 
  }
int  algorithm(){
int mapp;
int y;
int l;
int mini=10000,
analog=analogRead(A5);
mapp=map(analog,0,1023,1,9);
y=159-19*(mapp-1);

for(int i=1; i<=count;i++){
tft.fillRect(read[i][2],read[i][1],22,15,RED);

int neardis=abs(y-read[i][1]);
/*if (neardis<mini){
   mini=neardis;
   p=read[i][0];

}
*/

if (y==read[i][1]){
  l=read[i][0];
}

servo_pin.write(l*20);
delay(100);
}
digitalWrite(13,HIGH);            // touch code 
 TSPoint p= ts.getPoint();
 digitalWrite(13,LOW);


pinMode(XM,OUTPUT);
pinMode(YP,OUTPUT);
p.x = map(p.x, TS_MINX, TS_MAXX, 0,tft.height());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
 
  int y_set = map(p.x, 0, 240, 0, tft.height());
  int x_set = map(tft.width() - p.y, 0, 320, 0, tft.width());
if (p.z >MINPRESSURE && p.z< MAXPRESSURE) {
if (p.x > 46 && p.x < 72 && p.y > 253 && p.y < 266){
  
}
}
else{
  algorithm();
}

}
void run(){
/*
 if(sensor==1){
   analogpin=A5;
 }
 else if(sensor==2){
  analogpin=A6;

 }
 else 
 {
  analogpin=A7;
 }
*/
  int z=84;
   analog=analogRead(A5);
  int value=map(analog,0,1023,1,9);
   q=159-19*(value-1);
   
   
   if(u==1){
    t=z;
    tft.fillRect(t, q, 22,15,BLACKM);
   servo_pin.write(20*u);
   
  }
  else
  {
     tft.fillRect(z, q, 22,15,WHITE);
  }
  if(u==2){
    t=z+26;
    tft.fillRect(t, q, 22,15,BLACKM);
   servo_pin.write(20*u);
  }
  else
  {
     tft.fillRect(z+26, q, 22,15,WHITE);
  }
    if(u==3){
    t=z+26*2;
    tft.fillRect(t, q, 22,15,BLACKM);
servo_pin.write(20*u);  
  }
else
  {
     tft.fillRect(z+26*2, q, 22,15,WHITE);
  }  
  if(u==4){
    t=z+26*3;
    tft.fillRect(t, q, 22,15,BLACKM);
   servo_pin.write(20*u);


  }
  else
  {
     tft.fillRect(z+26*3, q, 22,15,WHITE);
  }
    if(u==5){
      t=z+26*4;
    tft.fillRect(t, q, 22,15,BLACKM);
   
   servo_pin.write(20*u);
  }
  else
  {
     tft.fillRect(z+26*4, q, 22,15,WHITE);
  }
  if(u==6){
    t=z+26*5;
    tft.fillRect(t, q, 22,15,BLACKM);
    servo_pin.write(20*u);
  }
  else
  {
     tft.fillRect(z+26*5, q, 22,15,WHITE);
  }
  if(u==7){
    t=z+26*6;
    tft.fillRect(t, q , 22,15,BLACKM);
    servo_pin.write(20*u);

  }

  else
  {
     tft.fillRect(z+26*6, q, 22,15,WHITE);
  }
  if(u==8){
    t=z+26*7;
    tft.fillRect(t, q, 22,15,BLACKM);
    servo_pin.write(20*u);
  } 
  else
  {
     tft.fillRect(z+26*7, q, 22,15,WHITE);
  } 
    if(u==9){
      t=z+26*8;
    tft.fillRect(t, q, 22,15,BLACKM);
    servo_pin.write(20*u);
  } 
  else
  {
     tft.fillRect(z+26*8, q, 22,15,WHITE);
  } 


  if(u>9){               //bug 
    u=1;
  }
else if (u<1){
  u=9;
}
}


 
void drawselectbuttonpressed()
{
   tft.fillRoundRect(140,195 ,40,40 ,5, BLUE);
   delay(100);
    tft.fillRoundRect(140,195 ,40,40 ,5, BLACKM);
}
void drawtriangle1(){
tft.fillTriangle(10, 218,55,198 ,55, 238, BLUE);
delay(100);
tft.fillTriangle(10, 218,55,198 ,55, 238, BLACKM);

}
void drawtriangle2(){
  tft.fillTriangle(310,218,265,198,265,238,BLUE);
  delay(100);
  tft.fillTriangle(310,218,265,198,265,238,BLACKM);
}
void runbutton(){
tft.fillTriangle(40,146.5 ,20,133 ,20,160, BLUE);
delay(1000);
tft.fillTriangle(40,146.5 ,20,133 ,20,160, GREEN);
}
void backbutton(){
  tft.fillTriangle(15,45 ,35,32 ,35,58, GREEN);
  delay(100);
  tft.fillTriangle(15,45 ,35,32 ,35,58,BLUE );
}
TSPoint waitOneTouch() {

  TSPoint p;
  
  do {
    p= ts.getPoint(); 
  
    pinMode(XM, OUTPUT); //Pins configures again for TFT control
    pinMode(YP, OUTPUT);
    
  
  } while((p.z < MINPRESSURE )|| (p.z > MAXPRESSURE));
  
  return p;
  
}

void drawBorder () {        // front page display
  uint16_t width = tft.width() - 1;
  uint16_t height = tft.height() - 1;      // draw broder
  uint8_t border = 10;

  tft.fillScreen(RED);
  tft.fillRect(border, border, (width - border * 2), (height - border * 2), WHITE);
  
}
void trainingbutt(){
tft.fillRoundRect(30,75,84,84,10,BLACKM);
delay(100);
tft.fillRoundRect(30,75,84,84,10,RED);  
}
void sensorbutton(){
tft.fillRoundRect(200,75,84,84,10,BLACKM);
delay(100);
tft.fillRoundRect(200,75,84,84,10,BLUE);  
}
