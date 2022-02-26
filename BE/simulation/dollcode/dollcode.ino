#include<Servo.h>
Servo face;
Servo right_hand;
Servo left_hand;
int sound_level=0;
#define in1 2
#define in2 3
#define in3 7
#define in4 8
int grip_pos;
int repeat;
void fwd_s() //Forword movement
{
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
delay(2000);
stp();
}
void rvs_S() //Backword movement
{
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(2000);
stp();
}
void clk_s() //Clockwise movement
{
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
delay(2000);
stp();
}
void aclk_s() // Anticlockwise movement
{
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(2000);
stp();
}
void fwd() //Forword movement
{
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
}
void rvs() //Backword movement
{
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
void clk() //Clockwise movement
{
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
}
void aclk() //Anticlokwise movement
{
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
void stp() //Stop
{
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
delay(100);
}
void setup()
{
Serial.begin(9600);
face.attach(9);
right_hand.attach(5);
left_hand.attach(10);
face.write(0);
left_hand.write(180);
right_hand.write(30);
face.write(37);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
delay(5000);
}
void loop()
{
sound_level = analogRead(A4);
if(sound_level>400&&sound_level<=405)
pat_1();
if(sound_level>405&&sound_level<=408)
pat_2();
if(sound_level>408&&sound_level<=413)
pat_3();
if(sound_level>413&&sound_level<=418)
pat_4();
if(sound_level>418&&sound_level<=422)
pat_5();
if(sound_level>422&&sound_level<=425)
pat_6();
if(sound_level>425&&sound_level<=427)
pat_7();
if(sound_level>427)
pat_8();
}
//Patterns:
void pat_1() //both hand up down
{
for (grip_pos = 37; grip_pos < 90; grip_pos += 1)
{
face.write(grip_pos);
delay(7);
}
for(repeat = 0; repeat<2; repeat++)
{
for (grip_pos = 180; grip_pos >= 30; grip_pos -= 1)
{
left_hand.write(grip_pos);
right_hand.write(210-grip_pos);
face.write(grip_pos/2);
delay(10);
}
for (grip_pos = 30; grip_pos < 180; grip_pos += 1)
{
left_hand.write(grip_pos);
right_hand.write(210-grip_pos);
face.write(grip_pos/2);
delay(10);
}
}
for (grip_pos = 90; grip_pos >= 37; grip_pos -= 1)
{
face.write(grip_pos);
delay(7);
}
}
void pat_2() // alternate hand up down
{
for(grip_pos = 30; grip_pos < 180; grip_pos += 1)
{
right_hand.write(grip_pos);
delay(7);
}
for (grip_pos = 37; grip_pos < 90; grip_pos += 1)
{
face.write(grip_pos);
delay(7);
}
for (repeat = 0; repeat<2; repeat++)
{
for (grip_pos = 180; grip_pos >= 30; grip_pos -= 1)
{
left_hand.write(grip_pos);
right_hand.write(grip_pos);
face.write(grip_pos/2);
delay(10);
}
for (grip_pos = 30; grip_pos < 180; grip_pos += 1)
{
left_hand.write(grip_pos);
right_hand.write(grip_pos);
face.write(grip_pos/2);
delay(10);
}
}
for (grip_pos = 180; grip_pos >= 30; grip_pos -= 1)
{
right_hand.write(grip_pos);
delay(7);
}
for (grip_pos = 90; grip_pos >= 37; grip_pos -= 1)
{
face.write(grip_pos);
delay(7);
}
}
void pat_3() //Right hand only
{
for (grip_pos = 37; grip_pos > 15; grip_pos -= 1)
{
face.write(grip_pos);
delay(7);
}
for (grip_pos = 30; grip_pos < 120; grip_pos += 1)
{
right_hand.write(grip_pos);
delay(3);
}
for(repeat = 0; repeat<4; repeat++)
{
for (grip_pos = 120; grip_pos < 180; grip_pos += 1)
{
right_hand.write(grip_pos);
delay(3);
}
for (grip_pos = 180; grip_pos >= 120; grip_pos -= 1)
{
right_hand.write(grip_pos);
delay(5);
}
}
for (grip_pos = 15; grip_pos <= 37; grip_pos += 1)
{
face.write(grip_pos);
delay(7);
}
for (grip_pos = 120; grip_pos >= 30; grip_pos -= 1)
{
right_hand.write(grip_pos);
delay(5);
}
}
void pat_4() //both hand up down with forward backward motion
{
for (grip_pos = 37; grip_pos < 90; grip_pos += 1)
{
face.write(grip_pos);
delay(7);
}
for(repeat = 0; repeat<2; repeat++)
{
fwd();
for (grip_pos = 180; grip_pos >= 30; grip_pos -= 1)
{
left_hand.write(grip_pos);
right_hand.write(210-grip_pos);
face.write(grip_pos/2);
delay(10);
}
rvs();
for (grip_pos = 30; grip_pos < 180; grip_pos += 1)
{
left_hand.write(grip_pos);
right_hand.write(210-grip_pos);
face.write(grip_pos/2);
delay(10);
}
}
stp();
for (grip_pos = 90; grip_pos >= 37; grip_pos -= 1)
{
face.write(grip_pos);
delay(7);
}
}
void pat_5() // alternate hand up down with clockwise and anticlockwise motion
{
for(grip_pos = 30; grip_pos < 180; grip_pos += 1)
{
right_hand.write(grip_pos);
delay(7);
}
for (grip_pos = 37; grip_pos < 90; grip_pos += 1)
{
face.write(grip_pos);
delay(7);
}
for(repeat = 0; repeat<2; repeat++)
{
clk();
for (grip_pos = 180; grip_pos >= 30; grip_pos -= 1)
{
left_hand.write(grip_pos);
right_hand.write(grip_pos);
face.write(grip_pos/2);
delay(10);
}
aclk();
for (grip_pos = 30; grip_pos < 180; grip_pos += 1)
{
left_hand.write(grip_pos);
right_hand.write(grip_pos);
face.write(grip_pos/2);
delay(10);
}
}
stp();
for (grip_pos = 180; grip_pos >= 30; grip_pos -= 1)
{
right_hand.write(grip_pos);
delay(7);
}
for (grip_pos = 90; grip_pos >= 37; grip_pos -= 1)
{
face.write(grip_pos);
delay(7);
}
}
void pat_6() //Right hand only with forward backward motion
{
for (grip_pos = 37; grip_pos > 15; grip_pos -= 1)
{
face.write(grip_pos);
delay(7);
}
for (grip_pos = 30; grip_pos < 120; grip_pos += 1)
{
right_hand.write(grip_pos);
delay(3);
}
for(repeat = 0; repeat<4; repeat++)
{
fwd();
for (grip_pos = 120; grip_pos < 180; grip_pos += 1)
{
right_hand.write(grip_pos);
delay(3);
}
rvs();
for (grip_pos = 180; grip_pos >= 120; grip_pos -= 1)
{
right_hand.write(grip_pos);
delay(5);
}
}
stp();
for (grip_pos = 15; grip_pos <= 37; grip_pos += 1)
{
face.write(grip_pos);
delay(7);
}
for (grip_pos = 120; grip_pos >= 30; grip_pos -= 1)
{
right_hand.write(grip_pos);
delay(5);
}
}
void pat_7() //forward backward motion
{
for(repeat=0;repeat<2;repeat++)
{
fwd();
delay(900);
stp();
delay(100);
rvs();
delay(900);
stp();
delay(100);
}
}
void pat_8() //clk anti-clk motion
{
for(repeat=0;repeat<3;repeat++)
{
clk();
delay(900);
stp();
delay(100);
aclk();
delay(900);
stp();
delay(100);
} }
