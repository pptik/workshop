/* 
 *  PLEASE DONT DELETE AND EDIT 
 *  Develop by          : Nurman Hariyanto
 *  Email               : nurman.hariyanto13@gmail.com
 *  Project             : Workshop Relay Water Pump
 *  Version             : 1.0
 *  Description         : This code trigger water pump turn on/off from message payload rabbitmq
 *  Microcontroller     : Wemos Mini ESP8266
 *                        NodeMCU ESP8266
 *  Device              : Relay Module 1 Channel
 *                        Water pump A3 waterproof                     
 */




/*
 * YOU CAN EDIT NOW
 */

/*
 * Include library 
 */

 #include <PubSubClient.h>
 #include <ESP8266WiFi.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Connection parameter
 * -Wifi -> internet connection foor data communication
 * -RabbitMQ/MQTT -> protoocol data communication
 */
const char* wifiSsid              = "LSKKHomeAuto";
const char* wifiPassword          = "1234567890";
const char* mqttHost              = "rmq2.pptik.id";
const char* mqttUserName          = "/smkmerdekabandung:smkmerdekabandung";
const char* mqttPassword          = "qwerty";
//const char* mqttClient            = "IOT-Water-Pumpp";
const char* mqttQueueAktuator     = "Aktuator";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*7
 * Device parameter
 * -Guid -> Id Device (unique) you can generate from here (https://www.uuidgenerator.net/version1) 
 * -status device -> save last state from the pump is on or off (1 = on , 0 = off) 
 * -pin microcontroller 
 * -mac device
 * 
 */
String deviceGuid                = "3735ffa4-f729-11ea-adc1-0242ac120002"; //You can change this guid with your guid 
int devicePin                    = D1;


/*
 * Wifi setup WiFi client and mac address 
 */
WiFiClient espClient;
PubSubClient client(espClient);
byte mac[6]; //array temp mac address
String MACAddress;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Set up WiFi connection
 */
 void setup_wifi(){
  delay(10);
  //We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to :");
  Serial.println(wifiSsid);
  WiFi.begin(wifiSsid, wifiPassword);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Function for Get Mac Address from microcontroller
 */
 
String mac2String(byte ar[]) {
  String s;
  for (byte i = 0; i < 6; ++i)
  {
    char buf[3];
    sprintf(buf, "%2X", ar[i]);
    s += buf;
    if (i < 5) s += ':';
  }
  return s;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Function for Print Mac Address 
 */
 void printMACAddress() {
  WiFi.macAddress(mac);
  MACAddress = mac2String(mac);
  Serial.println(MACAddress);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
 * Function for Get message payload from MQTT rabbit mq
 */
void callback(char* topic, byte* payload, unsigned int length){
  
  Serial.println();




}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Function for Reconnecting to MQTT/RabbitMQ 
 */
void reconnect() {
  // Loop until we're reconnected
  printMACAddress();
  const char* CL;
  CL = MACAddress.c_str();
  Serial.println(CL);
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(CL, mqttUserName, mqttPassword)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      ESP.restart();
      delay(5000);

    }
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
 * Function for Setup Pin Mode,wifi,mqtt,and serial
 */
void setup()
{
  pinMode(devicePin, OUTPUT);

  digitalWrite(devicePin, HIGH);

  //pinMode(input, INPUT);
  Serial.begin(115200);
  setup_wifi();
  printMACAddress();
  client.setServer(mqttHost, 1883);
  client.setCallback(callback);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
 * This functioon for loop your program
 */
void loop() {
  //if you disconnected from wifi and mqtt
  if (!client.connected()) {
    reconnect();
  }
  digitalWrite(devicePin,HIGH); //turn the relay on
  String pumpOn                    = String(deviceGuid + "#" + "1");
  char statusPumpOn [50];
  pumpOn.toCharArray(statusPumpOn, sizeof(statusPumpOn));
  Serial.println("Device ID :");
  Serial.println(deviceGuid);
  Serial.println("Status Pompa: ON");
  client.publish(mqttQueueAktuator,statusPumpOn );
  delay(5000); //wait for 5 seconds

  
  digitalWrite(devicePin,LOW); //turn the relay off
  String pumpOff                   = String(deviceGuid + "#" + "0");
  char statusPumpOff [50];
  pumpOff.toCharArray(statusPumpOff, sizeof(statusPumpOff));
  Serial.println("Device ID :");
  Serial.println(deviceGuid);
  Serial.print("Status Pompa: OFF");
  client.publish(mqttQueueAktuator,statusPumpOff );
  delay(5000); //wait for 5 seconds
  
  client.loop();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









 
