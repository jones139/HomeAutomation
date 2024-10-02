/*
  CatozapMqtt - based on SimpleMQTTClient.ino
*/

#include "EspMQTTClient.h"
#include "credentials.h"

#define ZAP_MS 200
const int pinIds[] = { 5, 4, 0, 2 };

EspMQTTClient client(
  SSID,
  SSID_PASSWD,
  MQTT_BROKER_IP,    // MQTT Broker server ip
  "", //MQTT_UNAME,        // Can be omitted if not needed
  "", // MQTT_PASSWD,       // Can be omitted if not needed
  MQTT_CLIENT_NAME,  // Client name that uniquely identify your device
  1883               // The MQTT port, default to 1883. this line can be omitted
);

boolean zap(int i) {
  if (i < sizeof pinIds / sizeof pinIds[0]) {
    Serial.printf("Zapping output %d (GPIO %d)\n", i, pinIds[i]);
    digitalWrite(pinIds[i], 0);
    delay(ZAP_MS);
    digitalWrite(pinIds[i], 1);
    delay(ZAP_MS);
    return (1);
  } else {
    Serial.printf("Zapping pin %d out of range", i);
    return (0);
  }
}

void zapAll() {
  String message;
  Serial.println("Zap All Nozzles");
  client.publish(MQTT_MSG_TOPIC, "Zap All Nozzles");


  for (int i = 0; i < sizeof pinIds / sizeof pinIds[0]; i++) {
    zap(i);
  }
}

void initOutput() {
  Serial.println("Initialising output pins...");
  for (int i = 0; i < sizeof pinIds / sizeof pinIds[0]; i++) {
    Serial.printf("Initialising output %d (GPIO %d)\n", i, pinIds[i]);
    pinMode(pinIds[i], OUTPUT);
    digitalWrite(pinIds[i], 1);
  }
}


void setup() {
  Serial.begin(115200);
  initOutput();
  // Optional functionalities of EspMQTTClient
  client.enableDebuggingMessages();                                    // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater();                                       // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA();                                                  // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage(MQTT_LWT_TOPIC, "I am going offline");  // You can activate the retain flag by setting the third parameter to true
}

void onConnectionEstablished() {
  Serial.print("Connected - led pin=");
  Serial.println(LED_BUILTIN);
  client.subscribe(MQTT_ZAP_TOPIC, [](const String& payload) {
    Serial.println(payload);
    if (payload.equals("0")) {
      client.publish(MQTT_MSG_TOPIC, "Zap 0");
      zap(0);
    } else if (payload.equals("1")) {
      client.publish(MQTT_MSG_TOPIC, "Zap 1");
      zap(1);
    } else if (payload.equals("2")) {
      client.publish(MQTT_MSG_TOPIC, "Zap 2");
      zap(2);
    } else if (payload.equals("3")) {
      client.publish(MQTT_MSG_TOPIC, "Zap 3");
      zap(3);
    } else if (payload.equals("ALL")) {
      client.publish(MQTT_MSG_TOPIC, "Zap ALL");
      zapAll();
    }
  });


  // Publish a message to "mytopic/test"
  client.publish(MQTT_MSG_TOPIC, "Catozap Controller alive");
}

void loop() {
  client.loop();
}
