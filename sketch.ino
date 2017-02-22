// Store LED pin values in an array
int ledPins[] = {9, 10, 11, 12};
int ledCount = sizeof(ledPins)/sizeof(int);

// Setup
void setup() {
	// Initialise all relevant LED pins as outputs
	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
		pinMode(ledPins[currentPin], OUTPUT);
	}
}

// the loop routine runs over and over again forever:
void loop() {
	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
    	digitalWrite(ledPins[currentPin], HIGH);
		delay(1000);
		digitalWrite(ledPins[currentPin], LOW);
		delay(1000);
	}
}
