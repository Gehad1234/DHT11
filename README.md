
## Environmental Monitoring with ThingSpeak Integration
one of semicolon startup IOT projects (my startup)

### Description

This Arduino project is an environmental monitoring system that measures temperature, humidity, and air quality. It utilizes a DHT11 sensor to measure temperature and humidity and an MQ135 gas sensor to measure air quality. The collected data is sent to the ThingSpeak IoT platform, allowing you to monitor and analyze environmental data over time.

### Components

- **DHT11 Sensor**: The DHT11 sensor is used to measure temperature and humidity.

- **MQ135 Gas Sensor**: The MQ135 gas sensor is used to measure air quality, particularly the concentration of certain gases.

- **Wi-Fi Module (ESP8266)**: The ESP8266 Wi-Fi module is used to connect to Wi-Fi and send data to the ThingSpeak platform.

- **OLED Display**: An OLED display is used to visualize the air quality data.

### Setup

1. Connect the DHT11 sensor to the Arduino board:
   - Connect the sensor's data pin to D5 on the Arduino.

2. Connect the MQ135 gas sensor to the Arduino board:
   - Connect the sensor's analog output pin to A0 on the Arduino.

3. Connect the OLED display to the Arduino using I2C:
   - Connect the display's SDA pin to the SDA (data) pin on the Arduino.
   - Connect the display's SCL pin to the SCL (clock) pin on the Arduino.

4. Ensure you have the required libraries installed in your Arduino IDE:
   - Adafruit GFX Library
   - Adafruit SSD1306 Library
   - DHT Sensor Library
   - MQ135 Library

5. Replace the placeholders in the code with your specific configuration:
   - `apiKey`: Replace it with your ThingSpeak Write API key.
   - `ssid`: Replace it with your Wi-Fi SSID.
   - `pass`: Replace it with your Wi-Fi password.

6. Upload the code to your Arduino board.

### Usage

Once the project is set up and the Arduino is powered on, it will continuously read temperature, humidity, and air quality measurements from the sensors. The environmental data is then displayed on the OLED display and sent to the ThingSpeak platform, allowing you to monitor and analyze environmental data over time.

### ThingSpeak Configuration

Make sure you have set up a ThingSpeak channel with the appropriate fields to receive and display the environmental data. The channel should match the fields used in the code for data upload.

### Additional Note

- The code calculates the air quality in parts per million (PPM) based on the MQ135 sensor readings.
- It uses a delay of 2000 milliseconds (2 seconds) between data updates to ThingSpeak, but ThingSpeak typically requires a minimum of 15 seconds between updates.

### Contributing

Feel free to modify and extend this project to suit your specific needs. You can enhance it by adding additional sensors, data logging features, or integrating it with other IoT platforms. Contributions and improvements are welcome!

### Author

Gehad Abdellah 

### Acknowledgments

Special thanks to the authors and contributors of the libraries used in this project for their work in making this project possible.
