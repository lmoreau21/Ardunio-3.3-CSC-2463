// pins for the LEDs:
const int redPin = 7;
const int greenPin = 6;
const int bluePin = 5;
const int potPin = A0; 

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT); 
}

void loop() {
  // if there's any serial available, read it:

  while (Serial.available() > 0) {
    int value = analogRead(potPin);
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    Serial.println(value);
    if (Serial.read() == '\n') {
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
    }
    
  }
}
