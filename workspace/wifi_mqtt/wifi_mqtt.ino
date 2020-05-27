/*  !!! --- wifi & mqtt --- !!!
 *   
 *  phase:
 *    1. connect to wifi
 *    2. send data to mqtt
 *    3. connect ir sensor
 *    
 *  wifi settings:
 *    
 *    
 *  guide:
 *    - https://www.hackster.io/uncle-yong/wemos-r32-with-arduino-startup-guide-7bc841
 */



// -------------------------------- //
//    !!! DEPENDENCIES here !!!

#include "WiFi.h"
#include "ESP32Ping.h"

//     !!! end of DEPENCIES !!!
// -------------------------------- //



// -------------------------------- //
//    !!! PINS here !!!



//     !!! end of PINS !!!
// -------------------------------- //



// --------------------------------
//    !!! CONSTANTS here !!!

const char* ssid = "SINGTEL-2A1A";
const char* password =  "ikeequaiph";

//     !!! end of CONSTANTS !!!
// -------------------------------- //



// -------------------------------- //
//    !!! FUNCTIONS here !!!

void connectWifi()
{
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

//     !!! end of FUNCTIONS !!!
// -------------------------------- //



// -------------------------------- //
//    !!! EXECUTION here !!!

void setup()
{
  // setup wifi
  Serial.begin(115200);
  delay(10);

  connectWifi();
  delay(100);
}

void loop()
{
  bool success = Ping.ping("www.google.com", 3);
 
  if(!success)
  {
    Serial.println("Ping failed");
    return;
  }
 
  Serial.println("Ping succesful!!!");
  delay(1000);
}

//     !!! end of EXECUTION !!!
// -------------------------------- //
