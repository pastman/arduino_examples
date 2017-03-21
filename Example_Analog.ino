
#define ANALOG 0
#define DIGITAL0 0
#define DIGITAL1 1
#define DIGITAL2 2

void setup() {

  Serial.begin(9600);

  pinMode(ANALOG, INPUT); 
  pinMode(DIGITAL0, OUTPUT); 
  pinMode(DIGITAL1, OUTPUT); 
  pinMode(DIGITAL2, OUTPUT);
   
}

void loop() {

  int light = analogRead(ANALOG);

  Serial.println(light);

  if (light < 650) {
    
    digitalWrite(DIGITAL0, HIGH);
    digitalWrite(DIGITAL1, LOW);
    digitalWrite(DIGITAL2, LOW);
    
  } else if (light < 200) {

    digitalWrite(DIGITAL0, LOW);
    digitalWrite(DIGITAL1, HIGH);
    digitalWrite(DIGITAL2, LOW);
    
  } else {

    digitalWrite(DIGITAL0, LOW);
    digitalWrite(DIGITAL1, LOW);
    digitalWrite(DIGITAL2, HIGH);
  }

  delay(1000);
  
}
