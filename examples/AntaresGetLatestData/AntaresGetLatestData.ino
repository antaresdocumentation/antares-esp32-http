#include <AntaresESP32HTTP.h>

#define ACCESSKEY "your-access-key"
#define WIFISSID "your-wifi-ssid"
#define PASSWORD "your-wifi-password"

#define projectName "your-project-name"
#define deviceName "your-project-name"

AntaresESP32HTTP antares(ACCESSKEY);

void setup() {
    Serial.begin(115200);
    antares.setDebug(true);
    antares.wifiConnection(WIFISSID, PASSWORD);
}

void loop() {
  // Get the latest data from your Antares device
  antares.get(projectName, deviceName);

  // Check if we're actually getting data
  if(antares.getSuccess()) {
    int temp = antares.getInt("temperature");
    int hum = antares.getInt("humidity");
    float windsp = antares.getFloat("wind_speed");
    float rainlv = antares.getFloat("rain_level");
    String lat = antares.getString("latitude");
    String lon = antares.getString("longitude");

    Serial.println("Temperature: " + String(temp));
    Serial.println("Humidity: " + String(hum));
    Serial.println("Wind speed: " + String(windsp));
    Serial.println("Rain level: " + String(rainlv));
    Serial.println("Latitude: " + lat);
    Serial.println("Longitude: " + lon);
  }
  delay(5000);
}
