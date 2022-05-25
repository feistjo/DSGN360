#include <Servo.h>

#define ENC1A
#define ENC1B
#define ENC2A
#define ENC2B
//h-bridge defines

#define DROPPER_PIN 23

long enc1_pos = 0;
long enc2_pos = 0;
//Use interrupts to keep track of encoder position

Servo dropper;

void setup() {
  /*pinMode(ENC1A, INPUT);
  pinMode(ENC1B, INPUT);
  pinMode(ENC2A, INPUT);
  pinMode(ENC2B, INPUT);*/
  //h-bridge pin modes


  dropper.attach(DROPPER_PIN);
  dropper.write(90);
  delay(1000);
  
}

void loop() {
  //turn on both motors

  //if one motor has higher pos, slow it down

  dropToken();
  delay(2000);
}

int servoPos = 90;
bool servoDir = 0;
void dropToken() {
  while(1) {
    dropper.write(servoPos);
    servoPos += servoDir?-1:1;
    if (servoPos >= 180 || servoPos <= 0) {
      servoDir = !servoDir;
      return;
    }
    if (servoPos == 90) {
      return;
    }
    delay(5);
  }
}
