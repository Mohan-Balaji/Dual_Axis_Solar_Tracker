#include <Servo.h>

#define LDR_TL A0  
#define LDR_TR A1  
#define LDR_BL A2  
#define LDR_BR A3  

Servo horizontalServo;
Servo verticalServo;

int horzServoPin = 9;
int vertServoPin = 10;

void setup() {
  horizontalServo.attach(horzServoPin);
  verticalServo.attach(vertServoPin);
  
  horizontalServo.write(90);
  verticalServo.write(90);
}

void loop() {
  int topLeft = analogRead(LDR_TL);
  int topRight = analogRead(LDR_TR);
  int bottomLeft = analogRead(LDR_BL);
  int bottomRight = analogRead(LDR_BR);

  int horizontalDifference = (topLeft + bottomLeft) - (topRight + bottomRight);
  if (abs(horizontalDifference) > threshold) {
    if (horizontalDifference > 0) {
      horizontalServo.write(horizontalServo.read() - 1);
    } else {
      horizontalServo.write(horizontalServo.read() + 1);
    }
  }

  int verticalDifference = (topLeft + topRight) - (bottomLeft + bottomRight);
  if (abs(verticalDifference) > threshold) {
    if (verticalDifference > 0) {
      verticalServo.write(verticalServo.read() - 1);
    } else {
      verticalServo.write(verticalServo.read() + 1);
    }
  }

  delay(50);
}
