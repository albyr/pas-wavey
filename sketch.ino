// Store LED pin values in an array
int ledPins[] = {9, 10, 11, 12};
// Hold the pin numbers of LEDs that are increasing in brightness
int brightPins[] = {0, 0, 0, 0};
int dimPins[] ={0, 0, 0, 0};
// Count how many LEDs we have in total
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

void loop() {
}
