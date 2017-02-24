// Store LED pin values in an array
int ledPins[] = {1, 2, 3, 4}; // Must be sequential at the moment
// Hold the pin numbers of LEDs that are increasing in brightness
int brightPins[] = {ledPins[0], 0, 0, 0};
int dimPins[] ={0, 0, 0, 0};
// Hold the current brightness values of the relevant pins
int brightVal[] = {0, 0, 0, 0};
int dimVal[] ={0, 0, 0, 0};
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
  	// Loop through all the pins
	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
      	// If the current pin is in the brightPins array ...
      	if (brightPins[currentPin] != 0) {
			// ---
			// HARDWARE COMMAND = brightVal[currentPin]
			// ---
			// Increase the stored brightness value for this pin.
			brightVal[currentPin] = brightVal[currentPin]+1;
			// If this pin has reached full brightness ...
			if (brightVal[currentPin] >= 10) {
				// ... then reset value to zero ...
				brightVal[currentPin] = 0;
				// ... and move that pin to the dimPins array ...
				dimPins[currentPin] = brightPins[currentPin];
				// ... and delete it from the brightPins array ...
				brightPins[currentPin] = 0;
				// ... and add the next pin to brightPins array
				brightPins[(currentPin+1)%4] = ledPins[(currentPin+1)%4];
			}
      	}
    }
	// Debugging output
  	Serial.println("---");
	Serial.print("Bright Pins: ");Serial.print(brightPins[0]);Serial.print(brightPins[1]);Serial.print(brightPins[2]);Serial.println(brightPins[3]);
	Serial.print("Dim Pins: ");Serial.print(dimPins[0]);Serial.print(dimPins[1]);Serial.print(dimPins[2]);Serial.println(dimPins[3]);
	Serial.print("Bright Values: ");Serial.print(brightVal[0]);Serial.print(brightVal[1]);Serial.print(brightVal[2]);Serial.println(brightVal[3]);
	Serial.print("Dim Values: ");Serial.print(dimVal[0]);Serial.print(dimVal[1]);Serial.print(dimVal[2]);Serial.println(dimVal[3]);
	delay(1000);
}
