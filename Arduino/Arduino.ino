/* SevSeg Counter Example
 
 Copyright 2014 Dean Reading
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */




#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

const int top_left = 12;
const int middle_top = 11;
const int top_right = 10;
const int middle_middle = 13;

const int bottom_left = 9;
const int middle_bottom = 8;
const int bottom_right = 7;
const int dp = 6;





void setup() {
  byte numDigits = 4;   
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {dp, middle_middle, top_left, bottom_left, middle_bottom, bottom_right, top_right, middle_top};
  
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(70);
  Serial.begin(9600);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  
  if (millis() >= timer) {
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    timer += 100; 
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
    Serial.println(deciSeconds);
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}

/// END ///
