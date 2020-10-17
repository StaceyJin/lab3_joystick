#referenced code at https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0

const int VRx = A0;
const int VRy = A1;
const int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

const int led1 = 12;
const int led2 = 8;
const int led3 = 7;
const int led4 = 4;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
    pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
    pinMode(led3, OUTPUT);
  digitalWrite(led3, LOW);
    pinMode(led4, OUTPUT);
  digitalWrite(led4, LOW);
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  //Serial.print(" | Button: ");
  Serial.println(SW_state);

  digitalWrite(led1, LOW);
if (xPosition > 216){
   if (yPosition < 575){
digitalWrite(led1, HIGH);
    }
}
  
  digitalWrite(led2, LOW);
  if (xPosition > 216){
if (yPosition > 425){
 digitalWrite(led2, HIGH);
  }
  }
  
 digitalWrite(led3, LOW);
if (xPosition < 296){
  if(yPosition > 472){
    digitalWrite(led3, HIGH);
  }
 }

 digitalWrite(led4, LOW);
 if (xPosition < 296){
  if(yPosition < 552){
    digitalWrite(led4, HIGH);
  }
 }
 
  delay(500);  
}
