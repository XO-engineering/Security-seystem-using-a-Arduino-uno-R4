int sensor_trig =15;
int sensor_echo = 16;
int toneGen = 5;
int close =180;
void setup() {
Serial.begin(9600);
pinMode(sensor_trig, OUTPUT); //trigger pulse to sensor pin
pinMode(sensor_echo, INPUT);  // read pulse
pinMode(7, INPUT_PULLUP);
pinMode(13, OUTPUT);
pinMode(5, OUTPUT);
}
void loop() {
 


float distance;
int pulselength;
int ConnectionCheck;
//pulse code
digitalWrite(sensor_trig, LOW);
delayMicroseconds(20);
digitalWrite(sensor_trig, HIGH);
delayMicroseconds(100);
digitalWrite(sensor_trig, LOW);

pulselength = pulseIn(sensor_echo, HIGH);



distance = pulselength * 0.017;



ConnectionCheck = digitalRead(7);

  if (distance < close && 1 == ConnectionCheck){

digitalWrite(13, HIGH);
tone(toneGen, 3000);
}
else
{
  noTone(5);
  digitalWrite(13, LOW);
}

delay(50);
Serial.println(distance);
Serial.print("Concheck state");
Serial.println( ConnectionCheck);
} 
