#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int sensorPin = 32; // Piezoelectric sensor connected to GPIO 32 (Analog)
const int numReadings = SCREEN_WIDTH; // Number of readings to display on the graph
int readings[numReadings]; // the readings from the analog input
int readIndex = 0; // the index of the current reading

// Replace with your network credentials
#define WIFI_SSID "Airtel_CheatMansion"
#define WIFI_PASSWORD "Cheatcoders@727"

// Replace with your Firebase project credentials
#define API_KEY "AIzaSyBewNHuhdCoDnlPqWANmcBasZhovK6oZUs"
#define DATABASE_URL "https://railway-acoustic-default-rtdb.firebaseio.com/"

// Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  analogReadResolution(12); 

  // Initialize readings array
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Configure Firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  auth.user.email = "esp32@gmail.com";
  auth.user.password = "123321@";

  Firebase.begin(&config, &auth);
  
  if (Firebase.ready()) {
    Serial.println("Firebase is ready");
  } else {
    Serial.println("Firebase not ready");
  }
}

void loop() {
  int piezoValue = analogRead(sensorPin); // Read piezo data
  readings[readIndex] = piezoValue;
  readIndex = (readIndex + 1) % numReadings; // Move index circularly

  // Send piezo value to Firebase
  if (Firebase.setInt(fbdo, "/piezo", piezoValue)) {
    Serial.println("Data sent to Firebase");
  } else {
    Serial.println("Failed to send data to Firebase");
    Serial.println(fbdo.errorReason());
  }

  displayGraph();
  delay(50); // Reduced delay for smoother graph updates
}

void displayGraph() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Vibration Graph");

  // Draw graph from right to left (ensuring scrolling effect)
  for (int i = 0; i < numReadings; i++) {
    int valueIndex = (readIndex + i) % numReadings; // Correct index calculation
    int height = map(readings[valueIndex], 0, 4095, 0, SCREEN_HEIGHT);
    display.drawFastVLine(SCREEN_WIDTH - i, SCREEN_HEIGHT - height, height, SSD1306_WHITE);
  }

  display.display();
}
