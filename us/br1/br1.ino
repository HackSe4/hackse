long duration;
int distance;
int tp1=6;
int ec1=7;
int tp2=4;
int ec2=5;
int tp3=3;
int ec3=2;

//right shoe analog to detect the up stairs and down stairs
const int ProxSensor1=A0;
const int ProxSensor2=A1;
int inputVal1 = 0;
int inputVal2 = 0;

void setup() {
pinMode(tp1, OUTPUT); // Sets the trigPin as an Output
pinMode(ec1, INPUT);
pinMode(tp2, OUTPUT); // Sets the trigPin as an Output
pinMode(ec2, INPUT);
pinMode(tp3, OUTPUT); // Sets the trigPin as an Output
pinMode(ec3, INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);// Sets the echoPin as an Input

 pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  
  pinMode(ProxSensor1,INPUT);
  pinMode(ProxSensor2,INPUT);//Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
float f1=us(tp1,ec1);
float f2=us(tp2,ec2);
float l=us(tp3,ec3);
if((f1<30)||(f2<30))
      tone(9,1000,1000);
else if((f1<60)||(f2<60)){
        tone(9,1000,500);
        delay(500);    
}



if(l<30)
      tone(8,1000,1000);
else if(l<60){
        tone(8,1000,500);
        delay(500);    
}

// Prints the distance on the Serial Monitor
Serial.print("Distance 1: ");
Serial.println(f1);
Serial.print("Distance 2: ");
Serial.println(f2);
Serial.print("Distance 3: ");
Serial.println(l);
//delay(500);
 inputVal1 = analogRead(ProxSensor1);
  Serial.print("Op1 = ");
  Serial.println(inputVal1);
  Serial.print("Op2 = ");
  inputVal2 = analogRead(ProxSensor2);
  Serial.println(inputVal2);
  delay(500);              // wait for a second
  if(inputVal1<120)      //Check the sensor output
  {
      tone(7,1000,500);
  }
  if(inputVal1<120)      //Check the sensor output
  {
       tone(8,1000,500);
  }
}

float us(int tp,int ec)
{
  digitalWrite(tp, LOW);
  delayMicroseconds(2);
  digitalWrite(tp, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp, LOW);
  duration = pulseIn(ec, HIGH);
  distance= duration*0.034/2;
  return (distance);
}
