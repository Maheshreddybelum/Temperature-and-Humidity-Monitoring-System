#include <DHT.h>
#include <LiquidCrystal.h>

// Define pin numbers
#define DHTPIN 2    // Pin connected to the Data pin of DHT11
#define DHTTYPE DHT11  // DHT 11 sensor

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Start the DHT sensor
  dht.begin();

  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Print a message to the LCD
  lcd.print("Temp & Humidity");
  delay(2000);  // Wait for 2 seconds
}

void loop() {
  // Read humidity
  float humidity = dht.readHumidity();

  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("from sensor!");
    return;
  }

  // Print the temperature and humidity on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Wait a few seconds between measurements
  delay(2000);
}
