void nhandulieu() {
  while (Wire.available()) {
    NhietDo = Wire.read();
    DoAm = Wire.read();
        Serial.print (NhietDo); Serial.print ("   ");
    Serial.println (DoAm);
//    lcd.setCursor(10, 0);
//    lcd.print(NhietDo);
//
//    lcd.setCursor(10, 1);
//    lcd.print(DoAm);
  }
 
}
