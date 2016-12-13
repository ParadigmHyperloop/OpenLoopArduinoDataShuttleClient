/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */
struct sensor {
  // The pin
  int pin;
  // Used to calibrate input with the map(a,b,c,d) func.
  int min_in;
  int max_in;
  int min_out;
  int max_out;
};
const struct sensor inputs[] = { 
  { A0, 0, 1023, 0, 255 },
  { A1, 0, 1023, 0, 255 },
  { A2, 0, 1023, 0, 255 },
  { A3, 0, 1023, 0, 255 },
  { A4, 0, 1023, 0, 255 },
  { A5, 0, 1023, 0, 255 },
  { A6, 0, 1023, 0, 255 },
  { A7, 0, 1023, 0, 255 },
  { A8, 0, 1023, 0, 255 },
  { A9, 0, 1023, 0, 255 },
  { A10, 0, 1023, 0, 255 },
  { A11, 0, 1023, 0, 255 },
  { A12, 0, 1023, 0, 255 },
  { A13, 0, 1023, 0, 255 },
  { A14, 0, 1023, 0, 255 },
  { A15, 0, 1023, 0, 255 }
};  // Analog input pins


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  // map it to the range of the analog out:
  int raw, calibrated, i;
  for (i=0;i<sizeof(inputs)/sizeof(struct sensor);i++) {
     raw = analogRead(inputs[i].pin);
     
     calibrated = map(raw, inputs[i].min_in, inputs[i].max_in, 
                           inputs[i].min_out, inputs[i].max_out);
    
    // print the results to the serial monitor:
    Serial.print(calibrated);
    if (i + 1  < sizeof(inputs) / sizeof(struct sensor)) {
      Serial.print("\t");
    }    
    // wait 2 milliseconds before the next loop
    // for the analog-to-digital converter to settle
    // after the last reading:
    delay(2);
  }
  Serial.println();
}
