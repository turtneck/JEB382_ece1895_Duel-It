const int button = 4;//6
const int LED1 = 6;//12
const int LED2 = 7;//13
const int LED3 = 8;//14

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(button) == HIGH)
  {
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    delay(1000);

    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED2, LOW);
    delay(1000);
    
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED3, LOW);
    delay(1000);

}
