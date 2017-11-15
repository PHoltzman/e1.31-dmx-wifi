#include <espDMX.h>
#include <ESP8266WiFi.h>
#include <E131.h>

// define wifi credentials
const char ssid[] = "test";         /* Replace with your SSID */
const char passphrase[] = "test";   /* Replace with your WPA2 passphrase */

// define other data
const int universe = 10;

E131 e131;

// setup function runs once at beginning of program
void setup() {

    /* Choose one to begin listening for E1.31 data */
     e131.beginMulticast(ssid, passphrase, universe); /* via Multicast for Universe 10 */
//    e131.begin(ssid, passphrase);               /* via Unicast on the default port */
    
    // setup DMX
    dmxA.begin();
}


// the loop runs continuously after the setup is complete
void loop() {
    /* Parse a packet */
    uint16_t num_channels = e131.parsePacket();
    
    /* Process channel data if we have it */
    if (num_channels) {
        dmxA.setChans(e131.data, num_channels);
//        Serial.print("Universe ");
//        Serial.print(e131.universe);
//        Serial.print(" / ");
//        Serial.print(num_channels);
//        Serial.print(" Channels | Packets: ");
//        Serial.print(e131.stats.num_packets);
//        Serial.print(" / Sequence Errors: ");
//        Serial.print(e131.stats.sequence_errors);
//        Serial.print(" / CH1: ");
//        Serial.println(e131.data[0]);
    }
}
