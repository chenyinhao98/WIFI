#include <WiFi.h>

const char* ssid = "*****";
//ssid stands for service set identifier
const char* pass = "*****";
//enter WIFI name and password
void setup()
{
  Serial.begin(115200);
  
  WiFi.begin(ssid, pass);

  //while WiFi not connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  //otherwize
  Serial.println("Connected to the WiFi network");
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());
}

void loop()
{
  
}
