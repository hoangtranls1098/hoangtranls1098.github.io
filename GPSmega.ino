#include <SoftwareSerial.h>
#include "LowPower.h"
////---------------------------------
//////__________SD
#include "SdFat.h"
#include <SPI.h>
#include <EthernetV2_0.h>
#define W5200_CS  10
#define SDCARD_CS 4
SdFat SD;
File myFile;


EthernetClient ethClient;
const char*  server  = "183.91.4.95";
const byte  mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xED };
IPAddress ip(192, 168, 11, 224);

SoftwareSerial ss(7, 6);



String LineString   = "";
String   data3, data5 , data7, data8, data10, data11, data12;
String data;
String mref = "REP";
String seqno = "a";
String id = "031098";
String Dir = "WE";
// The serial connection to the GPS module
String dd, mm, yy, m, s; //day/month/year/miunite/secons
int h;// hour
float lon, lati;
boolean First = false;
boolean record = false;
bool statusread = true;




void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(W5200_CS, OUTPUT);
  pinMode(SDCARD_CS, OUTPUT);
   pinMode(A7, OUTPUT);//led xanh
    pinMode(A8, OUTPUT);// led do
    pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH);
  digitalWrite(W5200_CS, LOW);
  Ethernet.begin(mac, ip);
  //  delay(1000);
  Serial.println(Ethernet.localIP());
  //  delay(2000);

}
void loop() {


  if (ethClient.connect(server, 18081))
  {
    digitalWrite(A7,0);
     digitalWrite(A8,1);
    ethClient.stop();
    delay(10);
    Serial.println("connected");
    if (First == true)
 {
      sentData();
      First = false;//delay(5000);
    }
       else
       {
          SD.remove("test.txt"); Sleep();
       }
  }
    else
    {
      digitalWrite(A7,1);
     digitalWrite(A8,0);
      First = true;
     readGPS();
    loc();
    if (record == true) recordData();
    Sleep();
    }







}
//---------------mode sleep------------------------
void Sleep()
{
  Serial2.end();
  delay(15);
  for (int i = 0; i < 450; i++)
    LowPower. powerDown ( SLEEP_8S, ADC_OFF, BOD_OFF ) ;
  delay(10);
}

//------------sentdata to sever---------------------
void sentData()
{
  if (!SD.begin(SDCARD_CS)) {
    Serial.println("SD failed!");
    while (1);
  }
  myFile = SD.open("test.txt");
  if (myFile) {
    delay(3);

    while (myFile.available()) {
      LineString = myFile.readStringUntil('\n');
      Serial.println(LineString);
      if (ethClient.connect(server, 18081))
      {
        ethClient.print("GET /gps/data.php?");
        ethClient.print(LineString);
        ethClient.print(" HTTP/1.1");
        ethClient.println();
        ethClient.println("Host: 183.91.4.95");
        ethClient.println("Connection: close");
        ethClient.println();
        ethClient.println();
        ethClient.stop();
      }
    }
    myFile.close();
    Serial.println("sent....");
  }
  //  else {
  //    // if the file didn't open, print an error:
  //    Serial.println("error opening GPS.csv");
  //  }
}
