#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
#include <WiFi.h>
String apiKey = "*****";                  //  Enter your Write API key from ThingSpeak
const char *ssid =  "*****";                                    // replace with your wifi ssid and wpa2 key
const char *pass =  "*****";
const char* server = "api.thingspeak.com";
WiFiClient client;
void setup() 
{
    Serial.begin(115200);
    delay(10);
    Serial.println("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
 
}
void loop() 
{
  
int h = 0;
float t =0;

h = hallRead();
t = ((temprature_sens_read()-32)/1.8);                //changing temperature parameter to celsius
 if (client.connect(server,80))                                 //   "184.106.153.149" or api.thingspeak.com
    {  
String data_to_send = apiKey;
    data_to_send += "&field1=";
    data_to_send += String(h);
    data_to_send += "&field2=";
    data_to_send += String(t);
    data_to_send += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data_to_send.length());
    client.print("\n\n");
    client.print(data_to_send);
    delay(1000);
    
}
    client.stop();
   
}
