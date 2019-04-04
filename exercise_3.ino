#include <SoftwareSerial.h> // 'set digital pins for serial communication'
SoftwareSerial wirelessNetworkYT(10, 11); // 'pin 10 as RX, pin 11 as TX'
char DAT = 0; // ' variable to store received character'
int REDLED = 2; // 'Red LED to digital pin number 2'
int GREENLED = 3; // 'Green LED with digital pin number 3'
int toggle1=0;
int toggle2=0;

void setup(){
wirelessNetworkYT.begin(38400); // ' Serial communication between Arduino and the module at 38400 bps
pinMode(REDLED, OUTPUT); // 'pin 2 as output'
pinMode(GREENLED, OUTPUT); // 'pin 3 as output'
}
void loop(){
if (wirelessNetworkYT.available()){ // ' if there is information available from module'
DAT = wirelessNetworkYT.read(); // 'stores in DATO the character received from module'

if ( DAT == '1' && toggle1==1 ){ // ' if the character received is number 1'
digitalWrite(REDLED, HIGH); toggle1=0; // turn on red LED
}
else{
  digitalWrite(REDLED, LOW); toggle1=1; // turn on red LED
}

if ( DAT == '2' && toggle2==1){ // ' if the character received is number 2'
digitalWrite(GREENLED, HIGH);toggle2=0; // turn off red LED
}
else {
  digitalWrite(GREENLED, LOW); toggle2=1; // turn on red LED
  
}
}
}
