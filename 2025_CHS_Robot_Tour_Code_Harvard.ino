#include <Servo.h>


Servo rightMotor;
Servo leftMotor;


int rmPin = 10;
int lmPin = 11;
int buttonPin = 4;

bool state = true;

//USE THIS ARRAY TO CONFIRM THE ORDER OF THE PATH
//0 --> Move Forward
//1 -- > Turn Right
//2 --> Turn Left
int pathOrder[] = {1,0,2,0,0,0,0};

//MIT Path --> 0,1,0,2,0,0,2,0,1,0

int buttonState = 0;


void setup() {
  pinMode(buttonPin, INPUT);

 }


 void loop() {
  buttonState = digitalRead(4);

  //Checks if button is pressed, then runs
  if(buttonState == HIGH){

    //Gives a delay when button is clicked
    delay(1000);

    //Moves forward 25cm to the first center point of the starting box
    MoveForward_25();

    //The for loop runs until all elements are included in the path
    for(int element : pathOrder){
      //This If statement runs the path order from the array
      if(element == 0){
        delay(500);
        MoveForward();
      } else if (element == 1){
        delay(500);
        turnRight();
      } else if (element == 2){
        delay(500);
        turnLeft();
      }

    }

  }

}


void MoveForward_25(){


  rightMotor.attach(10);
  leftMotor.attach(11);

  rightMotor.write(0);
  leftMotor.write(103);

  delay(1375);

  rightMotor.write(90);
  leftMotor.write(90);


  rightMotor.detach();
  leftMotor.detach();
 
}


void MoveForward(){

  rightMotor.attach(10);
  leftMotor.attach(11);


  rightMotor.write(0);
  leftMotor.write(104);

  delay(2795);

  rightMotor.write(90);
  leftMotor.write(90);

  rightMotor.detach();
  leftMotor.detach();
 
}


void turnLeft(){

  rightMotor.attach(10);
  leftMotor.attach(11);

  rightMotor.write(0);
  leftMotor.write(103);

  delay(200);

  rightMotor.write(80);
  leftMotor.write(80);


  delay(630);
 
  rightMotor.write(180);
  leftMotor.write(87);

  delay(50);

  rightMotor.detach();
  leftMotor.detach();
}


void turnRight(){

  rightMotor.attach(10);
  leftMotor.attach(11);


  rightMotor.write(0);
  leftMotor.write(103);

  delay(200);

  rightMotor.write(100);
  leftMotor.write(100);

  delay(900);
 
  rightMotor.write(180);
  leftMotor.write(87);

  delay(150);

  rightMotor.detach();
  leftMotor.detach();
   
}
