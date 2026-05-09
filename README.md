# final-project
# ESP32 Smart Room Monitoring and Control System

## Project Description

This project is about making a Smart Room Monitoring and Control System using an ESP32 microcontroller. The main goal of the ESP32 Smart Room Monitoring and Control System is to create a system that can monitor the room temperature and humidity and allow a user to control a device from a web browser. The ESP32 Smart Room Monitoring and Control System connects to Wi-Fi. Runs a small web server. When the user types the ESP32s IP address into a browser a control page opens. The page shows temperature and humidity readings from the DHT sensor. Includes buttons to turn an LED on or off. The LED is being used as an example of a device that could later be replaced with a relay, fan or light in the ESP32 Smart Room Monitoring and Control System.

The ESP32 Smart Room Monitoring and Control System is a way to control and monitor a room. The ESP32 microcontroller is the brain of the ESP32 Smart Room Monitoring and Control System.

## Current Project Status

The ESP32 Smart Room Monitoring and Control System project is still in progress. The basic code has been started. At this stage the ESP32 can:

- Connect to Wi-Fi

- Host a web page

- Display temperature and humidity readings

- Turn an LED on and off from the browser

- Use the ESP32 IP address as the access point for the control page in the ESP32 Smart Room Monitoring and Control System.

Future improvements may include adding a relay controlling a fan automatically when the temperature gets too high improving the web page design and adding sensors to the ESP32 Smart Room Monitoring and Control System.

## Hardware Used

- ESP32 microcontroller

- DHT11 or DHT22 temperature and humidity sensor

- LED

- Resistor

- Breadboard

- Jumper wires

- USB cable for power and programming

## Wiring

| Component | ESP32 Pin |

|---|---|

DHT Sensor VCC | 3.3V |

| DHT Sensor GND | GND |

DHT Sensor Data | GPIO 4 |

| LED Positive Leg | GPIO 2 |

LED Negative Leg | GND through resistor |

## Software Used

- Arduino IDE

- ESP32 board package

- WiFi library

- WebServer library

- DHT sensor library

## How to Run the ESP32 Smart Room Monitoring and Control System Project

1. Open the Arduino IDE.

2. Install the ESP32 board package if it is not already installed.

3. Install the DHT sensor library.

4. Connect the ESP32 to the computer using a USB cable.

5. Open the `SmartRoomControl.ino` file.

6. Replace the Wi-Fi name and password in the code with your Wi-Fi information.

7. Select the ESP32 board and port in the Arduino IDE.

8. Upload the code to the ESP32.

9. Open the Serial Monitor. Set the baud rate to 115200.

10. Wait for the ESP32 to connect to Wi-Fi.

11. Copy the IP address shown in the Serial Monitor.

12. Paste the IP address into a web browser.

13. Use the web page to view sensor readings and control the LED, in the ESP32 Smart Room Monitoring and Control System.

## Challenges So Far

Some challenges we have had with the ESP32 Smart Room Monitoring and Control System include getting the ESP32 to connect to Wi-Fi correctly making sure the DHT sensor gives readings and organizing the HTML code inside the Arduino sketch. We also had to make sure the wiring was correct because loose jumper wires can cause the sensor or LED to stop working in the ESP32 Smart Room Monitoring and Control System.

## Next Steps

The next step is to keep improving the ESP32 Smart Room Monitoring and Control System project by adding control. For example the ESP32 Smart Room Monitoring and Control System could turn on a fan when the temperature goes above a level. We may also improve the web page layout. Add more hardware components to the ESP32 Smart Room Monitoring and Control System.
