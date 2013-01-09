// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.


#include <Servo.h>
 
Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created
 
int pos = 0;    // variable to store the servo position
int led = 13;
 
void setup()
{
  // initialize serial:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
}

int max_angle = 200;

int read_data() {
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if (Serial.read() == '\n') {
      return data;
    } else {
      return -1;
    }
  }
}

int blink_time = 10;

void blink() {
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(blink_time);               // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      delay(blink_time);               // wait for a second
}

int blink_and_get_data() {
  int data = read_data();
  
  if (data > 0) {
    for (int i = 0; i < data; i++) {
      blink();
    }  
  }
  
  return data;
}
 
 
void loop()
{
  int data = blink_and_get_data();
  
  if (data > 0) {
    myservo.write(data);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position 
  }
}
