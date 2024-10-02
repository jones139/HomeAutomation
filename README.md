# HomeAutomation
Details and Source Code for my Home Automation system.   See https://github.com/jones139/CaravanCtrl for the equivalent for our static caravan.

# Overview


# Components

## Server
The main server is a second hand mini-PC, running Ubuntu Linux with the following main software components in Docker containers
  - Zigbee2Mqtt (using a Sonoff USB Zigbee Dongle)
  - Mosquitto Mqtt Broker
  - HomeAssistant

## Heating Controller
The zone valves for the central heating are controlled using a 4 channel ESP32 based relay board, running ESPHome firmware

## Lighting Controller
  - The hall light is switched using a Sonoff Zigbee switch

## Temperature Monitoring (Internal)

## Weather Station (External Monitor)
An ESP8266 based external temperature/humidity monitor, housed in a mini Stevenson Screen.  Sends data to MQTT broker.
[Details Here](./WeatherStation/README.md)

## Electricity Consumption Monitor

## CatoZap

## Greenhouse Controller


