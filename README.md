# hackse
alternate vision
// pin numbers for the components connected to the Arduino board
int t1=0;
int e1=1;
int t2=2;
int e2=3;
int t3=4;
int e3=5;
int t4=6;
int e4=7;
void setup()
{
Serial.begin (9600);
//assigning trigger(transmitter) and echo(receiver) pins for the ultrasonic proximity sensors
pinMode(t1, OUTPUT);
pinMode(e1, INPUT);
pinMode(t2, OUTPUT);
pinMode(e2, INPUT);
pinMode(t3, OUTPUT);
pinMode(e3, INPUT);
pinMode(t4, OUTPUT);
pinMode(e4, INPUT);
//assigning pins to actuators
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
long r_sen, l_sen, f_sen, b_sen;
void loop() {
// calling us function to return back the distance
r_sen=us(t1, e1);
l_sen=us(t2, e2);
f_sen=us(t3, e3);
b_sen=us(t4, e4);
//using the distance to buzz the actuators. The actuators have different modes of vibration which depends upon the distance between the obstacle and the
//subject.
if(r_sen<15){
tone(8,1000,500); //tone(actuator pin,frequency, duration)
}
else if(r_sen<30){
tone(8,1000,100);
}
if(l_sen<15){
tone(9,1000,500); //tone(actuator pin,frequency, duration)
}
else if(l_sen<30){
tone(9,1000,100);
}
if(b_sen<15){
tone(10,1000,500); //tone(actuator pin,frequency, duration)
}
else if(b_sen<30){
tone(10,1000,100);
}
if(f_sen<15){
tone(11,1000,500); //tone(actuator pin,frequency, duration)
}
else if(f_sen<30){
tone(11,1000,100);
}
}
//the us function which does the distance calculation and returns back the value when called.
float us(int t_Pin,int e_Pin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
float duration = pulseIn(echoPin, HIGH);
float distance_cm;
return distance_cm = (duration/2) / 29.1;
}
/* requirements to run the code: Arduino board, appropriate sensors and actuators (in this case ultrasonic proximity sensor and vibration motor)
The above code receives distance in cm from the proximity sensors and activates the respective actuators to vibrate according to the proximity of the obstacle
with respect to the subject.*/
