#include <SoftwareSerial.h> // 'set digital pins for serial communication'
SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as RX, pin 11 as TX'

char DAT = 0;; // ' variable to store received character'

int led1 = 6; // 'Red LED to digital pin number 2'
int led2 = 5; // 'Green LED with digital pin number 3'
int led3 = 4;
int led4 = 3;
int led5 = 2;


void allon() {
  digitalWrite (led1, HIGH);
  digitalWrite (led2, HIGH);
  digitalWrite (led3, HIGH);
  digitalWrite (led4, HIGH);
  digitalWrite (led5, HIGH);
}

void alloff() {
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
  digitalWrite (led5, LOW);
}


void setup(){
wirelessNetworkYT.begin(38400); // ' Serial communication between Arduino and the module at 38400 bps
pinMode(led1, OUTPUT); // 'pin 2 as output'
pinMode(led2, OUTPUT); // 'pin 2 as output'
pinMode(led3, OUTPUT); // 'pin 2 as output'
pinMode(led4, OUTPUT); // 'pin 2 as output'
pinMode(led5, OUTPUT); // 'pin 2 as output'

}
void loop(){
  if (wirelessNetworkYT.available()){ // ' if there is information available from module'
    DAT = wirelessNetworkYT.read(); // 'stores in DATO the character received from module'
    if(DAT=='1'){
      allon();
    } else if(DAT=='2'){
      alloff();
    }
    
    
  }
}
