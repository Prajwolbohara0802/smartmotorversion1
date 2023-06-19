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
int read[12][3];
void setup(void) {
pinMode(13,OUTPUT);
pinMode(A5,INPUT);
pinMode(12,OUTPUT);
servo_pin.attach(12);




  Serial.begin(9600);
  tft.reset();
  tft.begin(0x9341);
frontpage();
setting();
if(pages==2){
graph();
}
}

void graph(){
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

void frontpage(){
tft.setRotation(1); // Need for the Mega, please changed for your choice or rotation initial

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
void setting(){
 
tft.setRotation(1);
tft.fillScreen(WHITE);
tft.fillRoundRect(30,75,84,84,10,RED);
  tft.setCursor (45, 100);
  tft.setTextSize (2);
  tft.setTextColor(BLACK);
  tft.println("Train");
tft.fillRoundRect(200,75,84,84,10,BLUE);
  tft.setCursor (210, 100);
  tft.setTextSize (2);
  tft.setTextColor(BLACK);
  tft.println("Select");
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
void sense(){
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
  digitalWrite(13,HIGH);
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
<<<<<<< HEAD
 algorithm();
/*
  for(int i=1;i<count;i++){
       Serial.println(read[count][1]);
       Serial.println(read[count][2]);
    tft.fillRect(read[i][2],read[i][1],22,15,RED);
      neardis=abs(q-read[i][1]);
      if (neardis<mini){
         mini=neardis;
        p=read[i][0];
        s=read[i][1];
        y=read[i][2];

    //tft.fillRect(read[i][2],read[i][1],22,15,RED);
    
      }
      servo_pin.write(p*20);
      delay(100);
  }
     // tft.fillRect(y,s,22,15,GREEN);
  
       //delay(100);
  
       
   /*
  if button pressred
  {

  }
   trainind data - read

   sensorsvalue=sensor.read()
   min=10000
   for (int i=0:i<count;i++){
      a=sensorsvalue-read[i][1]
      if (a<min){
        min=a
        pos=read[i][0]
      }
   }
   servo.write(pos)
   graphdisplay(snsor, pos)
=======
 int p=1;
  for(int i=0;i<count;i++){
   
   Serial.println(read[count][1]);
 Serial.println(read[count][2]);
  for(int i=1;i<count;i++){

    
    p=read[i][0];
    tft.fillRect(read[i][2],read[i][1],22,15,RED);
    delay(100);
        servo_pin.write(p*20);
        delay(100);
       
   /*
>>>>>>> f18ca7e5cd6423b8edd22dad4af26d15e36a1200
   neardis=abs(159-read[i][1]);
   if (neardis<mini){
    
    mini = neardis;
     p=read[i][0];
   }
   servo_pin.write(p*20);

   */
   
<<<<<<< HEAD
 
=======
  } 
     }
>>>>>>> f18ca7e5cd6423b8edd22dad4af26d15e36a1200
  
}

if (p.x > 214 && p.x < 214 +40 && p.y > 100 && p.y < 100+40)
{
   
  drawselectbuttonpressed();

  count=count+1;
  run();
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
<<<<<<< HEAD
int  algorithm(){
int mapp;
int y;
int p;
int mini=10000,
analog=analogRead(A5);
mapp=map(analog,0,1023,0,9);
y=159-19*(mapp-1);

for(int i=1; i<=count;i++){
tft.fillRect(read[i][2],read[i][1],22,15,RED);
analog=analogRead(A5);
mapp=map(analog,0,1023,0,9);
y=159-19*(mapp-1);
int neardis=abs(y-read[i][1]);
/*if (neardis<mini){
   mini=neardis;
   p=read[i][0];

}
*/

if (y==read[i][1]){
  p=read[i][0];
}

servo_pin.write(p*20);
delay(100);
}
algorithm();
}
=======
>>>>>>> f18ca7e5cd6423b8edd22dad4af26d15e36a1200



void run(){

  int z=84;
   analog=analogRead(A5);
  int value=map(analog,0,1023,0,9);
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


  if(u>9){
    u=1;
  }
if (u<1){
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

  // wait 1 touch to exit function
  
  TSPoint p;
  
  do {
    p= ts.getPoint(); 
  
    pinMode(XM, OUTPUT); //Pins configures again for TFT control
    pinMode(YP, OUTPUT);
    
  
  } while((p.z < MINPRESSURE )|| (p.z > MAXPRESSURE));
  
  return p;
  
}


void drawBorder () {

  // Draw a border

  uint16_t width = tft.width() - 1;
  uint16_t height = tft.height() - 1;
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
