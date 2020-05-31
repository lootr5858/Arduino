/*  !!! --- integration of multiple ir sensor --- !!!
 *   
 *  implementation:
 *    - digital
 *    
 *   ir sensor:
 *    - 3 pin
 *      - 5V
 *      - GND
 *      - data
 *    
 *   arduino board:
 *    - WeMos D1 R32 (ESP32 wifi & bt)
 *      - pinout: http://esprtk.wap.sh/tt/create_esprtk_from_any_board.html
 */

// -------------------------------- //
//    !!! DEPENDENCIES here !!!





// -------------------------------- //
//    !!! PINS here !!!

const int sensors[5] = {5, 13, 12, 14, 27};  // ir sensors pin
#define testLED 18 // test indicator pin for presence of luggage



// --------------------------------
//    !!! CONSTANTS here !!!





// -------------------------------- //
//    !!! FUNCTIONS here !!!





// -------------------------------- //
//    !!! EXECUTION here !!!

void setup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(sensors[i], INPUT);
  }
  pinMode(testLED, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  bool inUse = checkLuggage();
  sendData(inUse);
  delay(1000);
}



// -------------------------------- //
//    !!! FUNCTIONS here !!!

bool checkLuggage()
{
  int count = 0;
  
  for (int i = 0; i < 5; i++)
  {
    int detected = digitalRead(sensors[i]);
    
    if (detected) {count++;}
  }

  // Serial.println(detected, count);

  if (count > 0) {return 1;}
  else {return 0;}
}

void sendData(bool inUse)
{
  if (inUse) {digitalWrite(testLED, HIGH);}
  else {digitalWrite(testLED, LOW);}
}
