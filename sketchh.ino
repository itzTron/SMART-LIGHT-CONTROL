#include <WiFi.h>
#include <PubSubClient.h>

// --- CONFIGURATION ---
const char* ssid = "Wokwi-GUEST"; // Wokwi virtual WiFi
const char* password = "";
const char* mqtt_server = "broker.hivemq.com"; // Public MQTT Broker
const char* topic = "wokwi-demo/led/control"; // The "channel" we listen to

// Pin definitions
const int LED_PIN = 15; // Connect LED to GPIO 15

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Start OFF

  setup_wifi();
  client.setServer(mqtt_server, 1883); // Standard MQTT port
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// This function runs when a message is received
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  
  Serial.print("Message arrived: ");
  Serial.println(message);

  if (message == "ON") {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Turned LED ON");
  } else if (message == "OFF") {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Turned LED OFF");
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe(topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}