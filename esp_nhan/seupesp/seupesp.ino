void setupesp(){
//WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//  Serial.print("connecting");
//  while (WiFi.status() != WL_CONNECTED) {
//    Serial.print(".");
//    delay(500);
//  }
//  Serial.println();
//  Serial.print("connected: ");
//  Serial.println(WiFi.localIP());
//========setup autoconfig
    WiFiManager wifiManager;
     wifiManager.autoConnect("AutoConnectAP");
      Serial.println("Đã kết nối");
//===========setup autoconfig
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
