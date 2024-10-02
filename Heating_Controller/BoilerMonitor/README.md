Boiler Monior
=============

This folder contains an ESPHome configuration for my house boiler monitor.

It uses a string of DS18D20 thermometers connected to pin 14, which are used
to log various water temperatures (boiler outlet, boiler inlet, individual zone inlet and domestic hot water cylinder temperature).

It also expects GPIO pins 15, 13 and 12 to be connected to 12V zone demand
signals via potential dividers (10k0 and 22k0 resistors) to provide 3.3V logic
inputs so we know when the different heating zones demand heating.

I will draw a nice schematic at some point......

For this I used an ESP32-CAM module because I had one available - an ESP8266
would be fine for this application.

Configure it by copying secrets.yaml.template to secrets.yaml, and entering
the wifi SSID and passwords etc. which are appropriate for your installation.

build it and run it with:
  esphome run boilermonitor.yaml.