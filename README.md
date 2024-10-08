# International Space Station (ISS) Tracker using ESP8266

## Overview
The **International Space Station (ISS) Tracker** project tracks the real-time location of the ISS using the NASA Open Notify API. The tracker retrieves the current latitude and longitude of the ISS, along with its velocity and altitude, and calculates the distance between the ISS and your specified location using the Haversine formula. This information is displayed on an OLED screen connected to the ESP8266 via the I2C protocol.

## Key Components
- **ESP8266 NodeMCU**: A Wi-Fi-enabled microcontroller that facilitates wireless communication.
- **SSD1306 OLED Display**: Used for displaying the current location of the ISS and the distance from the user's location.
- **ArduinoJson Library**: For parsing JSON data from the NASA API.
- **ESP8266WiFi Library**: To enable Wi-Fi connectivity.
- **Wire Library**: For I2C communication with the OLED display.
- **Adafruit_SSD1306 Library**: To control the SSD1306 OLED display.

## Features
- **Real-Time ISS Tracking**: Displays the current position of the ISS in real-time.
- **Distance Calculation**: Calculates the distance from the user's location to the ISS using the Haversine formula.
- **OLED Display**: Shows information clearly and interactively.
- **Wi-Fi Connectivity**: Connects to available Wi-Fi networks automatically.

## Schematic and Design
The project involves a simple hardware setup with connections made between the ESP8266 and the OLED display. A schematic can be provided in the `schematics` directory.

## Getting Started
1. **Hardware Setup**: Connect the ESP8266 NodeMCU to the SSD1306 OLED display as per the provided schematic.
2. **Programming the ESP8266**: Upload the code to the ESP8266, ensuring to set your desired latitude and longitude.
3. **Testing**: Power on the ESP8266 and connect to Wi-Fi. The ISS's current position and distance will be displayed on the OLED screen.

## Contributing
Contributions are welcome! Feel free to submit issues or pull requests to enhance this project.


![Hardware](https://github.com/pratz222/International-Space-Station-ISS-Tracker-using-ESP8266/assets/53640877/41904faf-906d-4600-8c1e-0ff6352e59cd)

