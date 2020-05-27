/*  !!! --- simple ir sensor --- !!!
 *   
 *  implementation:
 *    - digital
 *    
 *   ir sensor:
 *    - 2 pin
 *    
 *   output settings:
 */

// -------------------------------- //
//    !!! DEPENDENCIES here !!!



//     !!! end of DEPENCIES !!!
// -------------------------------- //



// -------------------------------- //
//    !!! PINS here !!!

#define irSensor A1
#define testLED 3

//     !!! end of PINS !!!
// -------------------------------- //



// --------------------------------
//    !!! CONSTANTS here !!!



//     !!! end of CONSTANTS !!!
// -------------------------------- //



// -------------------------------- //
//    !!! FUNCTIONS here !!!



//     !!! end of FUNCTIONS !!!
// -------------------------------- //



// -------------------------------- //
//    !!! EXECUTION here !!!

void setup()
{
  pinMode(irSensor, INPUT);
  pinMode(testLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // extract sensor value
  int irA = analogRead(irSensor);
  int irD = digitalRead(irSensor);

  String printString = "Digital: " + String(irD) + ". Analog: " + String(irA);
  Serial.println(printString);
  delay(1000);
}

//     !!! end of EXECUTION !!!
// -------------------------------- //
