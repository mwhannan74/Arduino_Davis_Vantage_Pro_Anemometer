// This code is specific design for an Adafruit Metro M4 board that has a built in NeoPixel.
// Other than the NeoPixel, this code should easily be adaptable to any other Adruino board.
#include <Adafruit_NeoPixel.h>


//============================================================================================
// GLOBALS
//============================================================================================
static const int _analogPin = A0;

static const int _pulsePin = 0;
volatile unsigned long _pulseCount = 0;

static const int _ledPin = 13; // red LED next to USB jack
bool _ledOn = false;

static const int _neoPixPin = 40;
static const int _neoPixCnt = 1;
Adafruit_NeoPixel _strip(_neoPixCnt, _neoPixPin, NEO_GRB + NEO_KHZ800);


//============================================================================================
// INTERUPTS
//============================================================================================
void countPulseInt() 
{
  _pulseCount++;

  _ledOn = !_ledOn;
  digitalWrite(_ledPin, _ledOn);
}

//============================================================================================
// SETUP
//============================================================================================
void setup() 
{
  Serial.begin (115200);
  
  pinMode(_pulsePin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_pulsePin), countPulseInt, RISING);
  
  pinMode(_ledPin, OUTPUT);
}


//============================================================================================
// LOOP
//============================================================================================
uint32_t _loop_time_ms = 2000;
uint32_t _time_ms = millis();

void loop() 
{  
  Serial.println("---------------------");
  
  // get the current time in msec for this loop
  float time_ms = millis();
  float etime_ms = time_ms - _time_ms;
  _time_ms = time_ms;

  //------------------------------------------------------------
  // Safely retrieve the pulseCount
  noInterrupts(); // Disable interrupts
  unsigned long pulseCount = _pulseCount; // read
  _pulseCount = 0; // reset
  interrupts(); // Enable interrupts  

  float etime_sec = etime_ms / 1000.0;
  float speed_mph = pulseCount*(2.25/etime_sec);
  
  Serial.print("speed_mph:"); Serial.print(speed_mph); Serial.print(", ");
  Serial.print("etime_sec:"); Serial.print(etime_sec); Serial.print(", ");
  Serial.print("pulseCount:"); Serial.print(pulseCount); Serial.print("\n");


  //------------------------------------------------------------
  // Read potentiometer to determine range
  int potVal_bits = analogRead(_analogPin); // 10 bit = 1024
  float heading = ((float)potVal_bits / 1024.0) * 360.0; // (1023/1024)*360 = 0.999*360 = 359.648 deg (ensures 0 is due North)
  
  Serial.print("heading:"); Serial.print(heading); Serial.print(", ");
  Serial.print("potVal_bits:"); Serial.print(potVal_bits); Serial.print("\n");



  //------------------------------------------------------------
  // loop rate
  delay(_loop_time_ms);
} 
