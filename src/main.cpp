#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author Riddhima Rajput
 * @date 2026-02-21
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */
#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 sensor initialized");

}

void loop() {

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from sensor!");
        delay(2000);
        return;
    }
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.println(" *C");
    delay(2000);

}
