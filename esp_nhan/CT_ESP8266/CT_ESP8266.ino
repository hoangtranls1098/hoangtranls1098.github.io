#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
FirebaseData dulieufirebase;

//========thư viện autoconfig
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
//========thư viện autoconfig

//------------------------------------
#include <Wire.h>
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27, 16, 2);

//================biến toàn cục lưu trữ giá trị nhieeyj độ  và độ ẩm
byte NhietDo, DoAm;
void setup() {
  Serial.begin(115200);
  //======
 // setupLCD();   //khoi tao lcd
  //=============
  setupesp();//khoi tao esp
  Wire.begin(D1, D2);//khoi tao giao tiep i2c
}
/*ESP là Master, uno là slave
  master gửi yêu cầu dến slave có dia chi 8
  yêu cầu trả về 2 byte du liệu*/
void loop() {

  Wire.requestFrom(8, 2);// gửi yêu cầu
  
  nhandulieu();// chuong trình nhận dữ liệu từ UNO phản hồi
  sentfirebase();// gửi dữ liệu lên database

}
