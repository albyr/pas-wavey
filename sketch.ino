// Store LED pin values in an array
int ledPins[] = {9, 10, 11, 12};
int ledCount = sizeof(ledPins)/sizeof(int);

// Setup
void setup() {
	// Open serial port for debugging
	Serial.begin(9600);
	// Initialise all relevant LED pins as outputs
	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
		pinMode(ledPins[currentPin], OUTPUT);
	}
	Serial.println("Program Start");
}

// the loop routine runs over and over again forever:
void loop() {
	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
		for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
			analogWrite(ledPins[currentPin], fadeValue);
			delay(30);
  		}
		for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
			analogWrite(ledPins[currentPin], fadeValue);
			delay(30);
  		}
	}
}
