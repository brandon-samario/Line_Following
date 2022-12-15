/*
The purpose of this program is to be able to use line tracking to control the robot car.
Using the line tracking sensor and the value being presented from it will determine if it detects the black tape or not.
Each movement is set based on a value and if that value is reached it will use the appropriate function.
*/

#define LT_R analogRead(A0) //Right line tracking sensor 
#define LT_M analogRead(A1) //Middle line tracking sensor 
#define LT_L analogRead(A2) //Left line tracking sensor 

//movement 1
void forward(){
digitalWrite(7,HIGH); //Left motors ON
digitalWrite(8,HIGH); //Right motors ON

analogWrite(5,55); //Set Speed for left motors
analogWrite(6,55); //Set Speed for right motors
Serial.println("forward!"); //Text printed when forward function is in use
}

//movement 2
void back(){
digitalWrite(7,LOW); //Left motors OFF
digitalWrite(8,LOW); //Right motors OFF

analogWrite(5,55); //Set Speed for left motors
analogWrite(6,55); //Set Speed for right motors
Serial.println("back!"); //Text printed when back function is in use
}

//movement 3
void left(){
digitalWrite(7,HIGH); //Left motors ON
digitalWrite(8,LOW); //Right motors OFF

analogWrite(5,55); //Set Speed for left motors
analogWrite(6,55); //Set Speed for right motors
Serial.println("left!"); //Text printed when left function is in use
}

//movement 4
void right(){
digitalWrite(7,LOW); //Left motors OFF
digitalWrite(8,HIGH); //Right motors ON

analogWrite(5,55); //Set Speed for left motors
analogWrite(6,55); //Set Speed for right motors
Serial.println("right!"); //Text printed when right function is in use
}

//movement 5
void stop(){
digitalWrite(7,LOW); 
digitalWrite(8,LOW);

analogWrite(5,0); //Set Speed for left motors
analogWrite(6,0); //Set Speed for right motors
Serial.println("stop!"); //Text printed when stop function is in use
}

void setup(){
Serial.begin(9600); //Initilize serial monitor
pinMode(LT_R,INPUT); //A0 set as an input
pinMode(LT_M,INPUT); //A1 set as an input
pinMode(LT_L,INPUT); //A2 set as an input
digitalWrite(3,1); //Standby
}

void loop() {
   if(LT_M > 200 && LT_M < 850) { //Value between 200 and 850 will go forward
    forward();
  }
   else if(LT_R > 400 ) { //Value over 400 will turn right
    right();                         
  }   
  else if(LT_L > 50) { //Value over 50 will turn right
    left();
  }
  else if(LT_M < 851 && LT_L < 851 && LT_R < 851) { //If value of all sensors is above 850 it will turn right (Turn around if not back line is detected)
    right();
  }
}
