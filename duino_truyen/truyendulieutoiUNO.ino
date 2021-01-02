void requestEvent() {

  Wire.write(NhietDo);
  Wire.write(DoAm);
  Wire.write(TocDo);
  Wire.write(Mua);
  Wire.write(HuongGio);

}
void receiveEvent(int howMany) {
  while (0 < Wire.available()) {
    byte a  = Wire.read();
    byte  b = Wire.read();/* receive byte as a character */
    Reset = a; Repeat = b;
    // Serial.print(Reset);Serial.print("   ");   Serial.print(oldReset);         /* print the character */
  }
  //************* nếu tab reset thay đổi, dựng cờ báo 1 báo restart hệ thống
  if (Reset != oldReset)  {
    cobao1 = 1;
  }
  oldReset = Reset ;
  if (( Repeat != oldRepeat)) {
   Tquet = Repeat*100;// giay
  }
  oldRepeat = Repeat ;
  //Serial.print(Reset);Serial.print("   ");   Serial.print(oldReset);         /* print the character */

}
