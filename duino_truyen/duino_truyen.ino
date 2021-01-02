#define NgoaHoTangLong 54321
#include <Wire.h>
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <DHT.h> // Gọi thư viện DHT22
//------DHT11
const int DHTPIN = A3; //Đọc dữ liệu từ DHT22 ở chân A3 trên mạch Arduino
const int DHTTYPE = DHT11;

DHT dht(DHTPIN, DHTTYPE);
int cobao;// cờ báo chu kỳ quét cảm biến
int cobao1;// cờ báo restart
int Reset, oldReset, Repeat,oldRepeat ;
int Tquet=100;
//=========
volatile int NhietDo , DoAm;
volatile int TocDo, Mua;
volatile int HuongGio;
volatile int Xung;
int dem;// dem so lan ngat OVF
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Wire.begin(8);// khai báo là slave có địa chỉ 8

  dht.begin(); // Khởi động cảm biế
  // setupLCD();       //set up lcd
  SetUpTimer();

  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}



void loop() {


  // nếu có cờ báo thực hiện lấy giá trị thì thực hiện chương trình tính toán ,
  if (cobao == 1)
  {
    tinhtoangiatri();
    cobao = 0;
    Serial.print(NhietDo); Serial.print("   ");  
    Serial.print(DoAm); Serial.print("   ");
    Serial.print(TocDo);Serial.print("   ");
    Serial.print(Mua);Serial.print("   ");
    Serial.print(HuongGio);Serial.println("   ");
  }

  if (cobao1 == 1) {
Serial.println("restart");//hàm restart vdk
    cobao1 = 0;
  }




  //  nếu không có bỏ qua
}
