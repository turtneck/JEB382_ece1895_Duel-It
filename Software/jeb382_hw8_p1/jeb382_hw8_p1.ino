const int button = 4;
const int LED1 = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  delay(1000);

}
