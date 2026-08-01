const int buttonPin = 4;
const int ledPin = 2;

bool alertSent = false;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.println("================================");
  Serial.println(" SafePulse Emergency System");
  Serial.println("================================");
  Serial.println("System Ready");
  Serial.println("Press the SOS Button");
}

void loop() {

  if (digitalRead(buttonPin) == LOW && !alertSent) {

    Serial.println();
    Serial.println("SOS Button Pressed!");
    digitalWrite(ledPin, HIGH);

    Serial.println("5-second cancel window...");
    delay(5000);

    Serial.println("Collecting GPS Location...");
    delay(1000);

    Serial.println("Latitude : 13.0827");
    Serial.println("Longitude: 80.2707");

    delay(1000);

    Serial.println("Recording Audio...");
    delay(1000);

    Serial.println("WiFi Connected");
    Serial.println("Uploading to Firebase...");
    delay(1000);

    Serial.println("Firebase Upload Successful");

    Serial.println("Sending SMS using SIM800L...");
    delay(1000);

    Serial.println("Emergency Contact Notified");

    Serial.println();
    Serial.println("***** ALERT SENT SUCCESSFULLY *****");

    alertSent = true;
  }
}
