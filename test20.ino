#include <WiFi.h>
#include <FirebaseESP32.h>

// Replace with your Firebase project URL and API key
#define FIREBASE_HOST "test1-e87df-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "AIzaSyAMpFqXWBRDnju6IoWLFREOxk6rrxivdTg"

// Replace with your Wi-Fi SSID and password
#define WIFI_SSID "ANURAG"
#define WIFI_PASSWORD "12345678"

// Define FirebaseESP32 data object and configuration
FirebaseData firebaseData;
FirebaseJson json;
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;

// Define LED pin
const int LED_PIN = 2; // Onboard LED (GPIO2 for ESP32)

void setup()
{
    Serial.begin(115200);

    // Initialize the LED pin as output
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Ensure LED is OFF initially

    // Connect to Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    // Configure Firebase
    firebaseConfig.host = FIREBASE_HOST;
    firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;

    // Initialize Firebase
    Firebase.begin(&firebaseConfig, &firebaseAuth);
    Firebase.reconnectWiFi(true);

    Serial.println("------------------------------------");
    Serial.println("Connected to Firebase...");
}

void loop()
{
    // Generate six distinct random values
    int Temperature = random(0, 100);
    int vmax = random(125, 200);
    int vmin = random(0, 124);
    int imax = random(50, 80);
    int imin = random(0, 79);
    int value6 = random(0, 1023);

    // Print the random values
    Serial.println("Generated Random Values:");
    Serial.printf("Temperature: %d\n", Temperature);
    Serial.printf("vmax: %d\n", vmax);
    Serial.printf("vmin: %d\n", vmin);
    Serial.printf("imax: %d\n", imax);
    Serial.printf("imin: %d\n", imin);
    Serial.printf("Value 6: %d\n", value6);

    // Create JSON structure for Firebase
    json.set("/Temperature", Temperature);
    json.set("/vmax", vmax);
    json.set("/vmin", vmin);
    json.set("/imax", imax);
    json.set("/imin", imin);
    json.set("/six", value6);

    // Send data to Firebase Realtime Database
    if (Firebase.updateNode(firebaseData, "/Weight", json))
    {
        Serial.println("Data sent to Firebase successfully.");
    }
    else
    {
        Serial.print("Failed to send data: ");
        Serial.println(firebaseData.errorReason());
    }

    // Check LEDStatus in Firebase
    if (Firebase.getBool(firebaseData, "/LEDStatus"))

    {
        bool ledState = firebaseData.boolData(); // Get LED status
        digitalWrite(LED_PIN, ledState ? HIGH : LOW); // Set LED state
        Serial.println(ledState ? "LED is ON" : "LED is OFF");
    }
    else
    {
        Serial.print("Failed to read LEDStatus: ");
        Serial.println(firebaseData.errorReason());
    }

    // Wait before next cycle
    delay(5000); // Delay for 5 seconds
}
