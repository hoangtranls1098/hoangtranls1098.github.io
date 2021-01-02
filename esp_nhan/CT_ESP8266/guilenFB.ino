void sentfirebase() {
  Firebase.setFloat(dulieufirebase,"NhietDo", NhietDo );
  Firebase.setFloat(dulieufirebase,"DoAm", DoAm);
  delay(215);
//  if (Firebase.failed()) {
//    Serial.print("setting /number failed:");
//    Serial.println(Firebase.error());
//    return;
//  }
}
