#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <Wire.h>
FirebaseData dulieufirebase;
#define FIREBASE_HOST "control-pump.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "nfeOBrK70Uxrja6vBDcgtvtehIZbEgTUey5tZ00l"
#define WIFI_SSID "Nokia"
#define WIFI_PASSWORD "33669999"
//========
int Reset,Repeat;
//------------------------------------
#include <Wire.h>
int DoAm;

String state;
char p[10]="";
void setup() {
  Serial.begin(9600);
  Wire.begin(D1, D2);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
    Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}
void loop(){
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write(p);  /* sends hello slave string */
 Wire.endTransmission();    /* stop transmitting */
 
 Wire.requestFrom(8, 1); /* request & read data of size 13 from slave */
 while(Wire.available()){
    DoAm = Wire.read();
    Serial.println(DoAm);
 }
 Serial.println();
 delay(1000);
Firebase.setInt(dulieufirebase,"DoAm",DoAm);
Firebase.getString(dulieufirebase, "hihaa",state);
Serial.println(state);
for (int i=0;i<=10;i++) p[i]=state[i];
}
