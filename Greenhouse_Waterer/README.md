# Greenhouse Waterer

The greenhouse watering system comprises a small submersible pump in a water butt (https://www.amazon.co.uk/dp/B0CP3J148N) as the water supply, and several 12V solenoid valves to control the water flow to the various plants.

An ESP8266 microcontroller is used to provide water on a slow pulse-width modulation cycle by opening and closing the solenoid valves, and switching the pump on and off when necessary.   The output level for each solenoid valve is set by a remote computer using MQTT so that even if the network connection is lost, the microcontroller will continue watering at the previous output level.

The 12V solenoids are controlled using an 8 way, 5V relay board.  I drive the relays by connecting the 5V output of the ESP8266 board to JD-VCC on the relay card.  The rest of the logic is working at 3.3V.

The 240V mains for the pump is controlled via a solid state relay (https://www.amazon.co.uk/dp/B0D7NY558F).   A solid state relay in a separate enclosure was used to separate the 240V mains voltage from the control voltages around the microcontroller.

The ESP8266 does not have enough GPIO pins to control all the relays, so I am using a PCF8575 extender on a pre-built module.   The module I bought has a
voltage regulator that runs teh PCF8574 at 2.4V rather than 3.3V, and this was
insufficient to drive the Relay board opto couplers. etc.  So I bypassed the regulator by shorting VCC to VDD to make it run at 3.3V, and this got the relay board working.  Reading the ebay listing again (https://www.ebay.co.uk/itm/356670269693?_trkparms=amclksrc%3DITM%26aid%3D777008%26algo%3DPERSONAL.TOPIC%26ao%3D1%26asc%3D20250324085124%26meid%3D461205b52f5640ab81bf3b1768749ec1%26pid%3D101770%26rk%3D1%26rkt%3D1%26itm%3D356670269693%26pmt%3D1%26noa%3D1%26pg%3D4375194%26algv%3DRecentlyViewedItemsV2WithMLRPboosterAndUpdatedFeatures_BP%26brand%3DUnbranded&_trksid=p4375194.c101770.m146925&_trkparms=parentrq%3Afcefb1451950a622fe887edeffffe9d4%7Cpageci%3A6688acc8-10ba-11f0-98a3-5a0f7ef6be41%7Ciid%3A1%7Cvlpname%3Avlp_homepage) it does say that it has a 3.3V regulator on-board.  Maybe I am only getting 2.4V because I am supplying it with VCC=3.3V, so shorting it is not a problem.

I am having problems with two of the relays on the board not working, but this seems to be an issue with the relay board, because even if I short the input pin to ground manually it still does not work and the indicator LED is dim.  But I don't need all 8 relays fortunately!.