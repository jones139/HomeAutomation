# Electricity Usage Monitor

# Hardware

  - ESP32 Cam board (without the camera installed) - I just used this because I had a few of the boards - I am only using it as a WiFi enabled microcontroller.
  - [Open Energy Monitor LED Pulse Sensor](https://shop.openenergymonitor.com/optical-utility-meter-led-pulse-sensor/), connected to Pin 14 of the ESP32 Cam board.

# Firmware
It uses the EspHome firmware, configured using [powermeter.yaml](powermeter.yaml).
Copy [secrets.yaml.template](secrets.yaml.template) to secrets.yaml, and modify for your network settings.

It can then be built using 'esphome compile powermeter.yaml'

# Images
![Microcontroller Board](images/microcontroller_board.jpg)

![Signal Conditioning Board](images/signal_conditioning.jpg)

![Assembly](images/assembly.jpg)

![Installation](images/installation.jpg)



