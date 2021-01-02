void sentfirebase() {
  Firebase.setFloat("NhietDo", NhietDo );
  Firebase.setFloat("DoAm", DoAm);
  delay(215);
  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
}
