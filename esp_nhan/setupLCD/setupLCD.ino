void setupLCD()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Nhiet Do: ");
   lcd.setCursor(13, 0);
   lcd.print("*C");
  lcd.setCursor(0, 1);
  lcd.print("Do Am: ");
   lcd.setCursor(13, 1);
   lcd.print("%");
}
