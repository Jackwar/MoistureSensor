int AO = 0; 
int nums;

void setup() {
  Serial.begin(9600);
  Serial.println("Soil moisture sensor");
  pinMode(AO, INPUT);
}

void loop() {
  nums = analogRead(AO);
  Serial.print(nums);
  Serial.println();
  delay(1000);
}
