const int sensorPin = A0;
// Romtemperaturen, kan skrive med komma pga float.
const float room_temp = 23;

void setup(){
  // Åpner en serial tilkobling for å vise verdier.
  Serial.begin(9600);
  // Setter LED lysene som output.
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  // Henter verdien fra sensoren og lagrer den som variabel.
  int sensorVal = analogRead(sensorPin);

  // Sender 10-bit sensor verdien ut gjennom serial port.
  Serial.println("sensor Value: ");
  Serial.println(sensorVal); 

  // Koverterer verdiene fra sensoren til volt format.
  float voltage = (sensorVal/1024.0) * 5.0;

  // Sender volt nivået ut til serial port.
  Serial.println(", Volts: ");
  Serial.println(voltage);

  // Gjør om volt til temperatur i celsius.
  Serial.println(", degrees C: "); 
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  // Hvis temperaturen er lavere enn rom temperaturen. Skru av alle lysene.
  if(temperature < room_temp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  
  // Hvis temperaturen øker med 1-2 grader, skru på et lys.
  else if(temperature >= room_temp+1 && temperature < room_temp+2){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  
  // Hvis temperaturen øker med 3-4 grader, skru på det andre lyset. 
  else if(temperature >= room_temp+3 && temperature < room_temp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  
  // Hvis temperaturen øker mer enn 5 grader, skru på alle lysene.
  else if(temperature >= room_temp+5){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(50);
}
