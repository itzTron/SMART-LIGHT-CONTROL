# SMART-LIGHT-CONTROL

*COMPANY* : CODTECH IT SOLUTIONS
*NAME* : TANMOY NASKAR
INTERN ID : CT04DR1389
*DOMAIN* : INTERNET OF THINGS
*DURATION* : 4 WEEKS
*MENTOR* : NEELA SANTOSH

🏠 IoT Smart Home Automation System (ESP32 + MQTT)
==================================================

A real-time home automation prototype that allows users to control household devices (lights and fans) remotely using a web-based dashboard. This project utilizes the **ESP32** microcontroller and **MQTT** protocol for low-latency communication between the hardware and the web interface.

The project is designed to be easily simulated on [Wokwi](https://wokwi.com/) but can be deployed on physical hardware with minimal changes.

🚀 Features
-----------

*   **Real-time Control:** Toggle devices ON/OFF instantly via the web dashboard.
    
*   **Multi-Device Support:** Independent control for a Light (LED) and a Fan (LED).
    
*   **Master Switch:** "Turn Everything Off" button for global control.
    
*   **Visual Feedback:** Interactive UI with animations (spinning fan icon, glowing lightbulb).
    
*   **Responsive Design:** Works on desktop and mobile browsers.
    
*   **Protocol:** Uses MQTT (Message Queuing Telemetry Transport) over WebSockets for lightweight, fast messaging.
    

🛠️ Tech Stack
--------------

### Hardware (Simulated)

*   **Microcontroller:** ESP32 DevKit V1
    
*   **Actuators:**
    
    *   Red LED (Simulates Living Room Light) - GPIO 15
        
    *   Blue LED (Simulates Ceiling Fan) - GPIO 2
        
*   **Resistors:** 2x 220Ω
    

### Software

*   **Firmware:** C++ (Arduino Framework)
    
*   **Communication:** MQTT (via PubSubClient library)
    
*   **Web Interface:** HTML5, JavaScript (ES6)
    
*   **Styling:** Tailwind CSS (CDN)
    
*   **MQTT Client (Web):** Paho MQTT JS Library
    

🔌 Circuit Diagram
------------------

**ComponentPinESP32 Pin**

**Light (Red LED)**

Anode (+)

GPIO 15

Cathode (-)

GND

**Fan (Blue LED)**

Anode (+)

GPIO 2

Cathode (-)

GND

_Note: Use 220Ω resistors in series with the LED anodes to prevent burnout._

⚙️ Setup & Installation
-----------------------

### 1\. Hardware Simulation (Wokwi)

1.  Go to [Wokwi.com](https://wokwi.com/) and create a new **ESP32** project.
    
2.  **Library Manager:** Add PubSubClient to libraries.txt.
    
3.  **Code:** Copy the content of sketch.ino into the main editor.
    
4.  **Wiring:** Use the diagram.json to automatically wire the components.
    
5.  **Run:** Click the **Green Play Button** to connect to the virtual WiFi and MQTT broker.
    

### 2\. Web Dashboard

1.  Download index.html.
    
2.  Open the file directly in any modern web browser (Chrome, Firefox, Edge).
    
3.  The dashboard will automatically connect to the public HiveMQ broker.
    
4.  **Note:** Ensure the mqtt\_port in the HTML is set to 8884 (WSS) to avoid security errors on HTTPS browsers.
    

📡 MQTT Configuration
---------------------

*   **Broker:** broker.hivemq.com (Public)
    
*   **Port:** 1883 (ESP32 TCP) / 8884 (Web WSS)
    
*   **Topics:**
    
    *   Light: wokwi-demo/home/light
        
    *   Fan: wokwi-demo/home/fan
        

🔮 Future Improvements
----------------------

*   **Two-way Sync:** Update the UI if the physical button on the device is pressed.
    
*   **Sensors:** Add DHT22 for temperature and humidity monitoring.
    
*   **Voice Control:** Integrate with Alexa or Google Assistant via Node-RED.
    
*   **Security:** Implement private MQTT broker (e.g., Mosquitto) with username/password authentication.
    

📄 License
----------

This project is open-source and available under the MIT License.
