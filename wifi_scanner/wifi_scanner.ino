/*
    ESP8266 WiFi Network Scanner Example
    Hardware: NodeMCU
    Date: 2018
    https://circuits4you.com
*/
#include <ESP8266WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>


#define LED_PIN 16

#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

//=======================================================================
//                     SETUP
//=======================================================================

void setup() {
  Serial.begin(115200);
  Serial.println(""); //Remove garbage

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  // WiFi.mode(WIFI_STA);
  // WiFi.disconnect();  //ESP has  tendency to store old SSID and PASSword and tries to connect
  delay(100);
  // Serial.println("WiFi Netwoek Scan Started");
  
  dht.begin();
//   pinMode(DGTPIN, OUTPUT);
}

//=======================================================================
//                        LOOP
//=======================================================================
void loop() {
 
  // WiFi.scanNetworks will return the number of networks found
  // int n = WiFi.scanNetworks();
   
  // Serial.println("Scan done");
  
  // if (n == 0)
  //   Serial.println("No Networks Found");
  // else
  // {
  //   Serial.print(n);
  //   Serial.println(" Networks found");
  //   for (int i = 0; i < n; ++i)
  //   {
  //     // Print SSID and RSSI for each network found
  //     Serial.print(i + 1);  //Sr. No
  //     Serial.print(": ");
  //     Serial.print(WiFi.SSID(i)); //SSID
  //     Serial.print(" (");
  //     Serial.print(WiFi.RSSI(i)); //Signal Strength
  //     Serial.print(") MAC:");
  //     Serial.print(WiFi.BSSIDstr(i));
  //     Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" Unsecured":" Secured");
  //     delay(10);
  //   }
  // }
  // Serial.println("");

  // Wait a bit before starting New scanning again
  // digitalWrite(PIN_DATA, HIGH);
  // delay(3000);
  // digitalWrite(PIN_DATA, LOW);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
 float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
 float f = dht.readTemperature(true);
 if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    Serial.print(h);
    Serial.print(t);
    Serial.print(f);
   delay(2000);
   return;
 }
//  // Compute heat index in Fahrenheit (the default)
 float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
 float hic = dht.computeHeatIndex(t, h, false);
 Serial.print(F("Humidity: "));
 Serial.print(h);
 Serial.print(F("%  Temperature: "));
 Serial.print(t);
 Serial.print(F("°C "));
 Serial.print(f);
 Serial.print(F("°F  Heat index: "));
 Serial.print(hic);
 Serial.print(F("°C "));
 Serial.print(hif);
 Serial.println(F("°F"));
//  // Led blink test
//  digitalWrite(LED_PIN, HIGH);
//  delay(2000);
//  digitalWrite(LED_PIN, LOW);
//  delay(2000);

}
//=======================================================================
