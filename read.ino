void readGPS()

{ Serial2.begin(9600);
  statusread = true;
  String dataS; bool recognizing = false;
  while (statusread) {
    while (Serial2.available() > 0) {
      byte gpsData = Serial2.read();
      char gpschar = char(gpsData);
      if (gpschar == '$')  recognizing = true;
      if (gpschar == '*') recognizing = false;//Serial.println(gpschar);
      if (recognizing)dataS = dataS + gpschar;
      else
      {
        if (dataS[1] == 'G' && dataS[2] == 'P' && dataS[3] == 'R' && dataS[4] == 'M' && dataS[5] == 'C') {

          data = dataS;
          Serial.println("reading....");
          statusread = false;
          record = true;
        }
        dataS = "";
      }
    }
  }
}
void loc()
{
  String data0, data2, data4, data6, data9;
  //---------------------------
  String d1, d2;
  int  j = 0;
  d1 = data;
  for (int i = 0; i <= d1.length(); i++) {
    if (d1.charAt(i) == ',')
    {
      j++;
      d2 = d1;
      d2.remove(i);
      d1.remove(0, i + 1);
      i = 0;
    }

    if (j == 1) data0 = d2;
    //   if (data0 == "$GPRMC")
    {
      if (j == 2) data2 = d2;// time
      else if (j == 3) data3 = d2;// A =good, V= warrning.
      else if (j == 4) data4 = d2;// latitude
      else if (j == 5) data5 = d2; //latitude+
      else if (j == 6) data6 = d2;//longtitude
      else if (j == 7) data7 = d2;//longtitude+
      else if (j == 8) data8 = d2;// speed Knots
      else if (j == 9) data9 = d2;//date
      else if (j == 10) data10 = d2;//Course Made Good, True
      else if (j == 11) data11 = d2; // Magnetic variation 20.3 deg East
      else if (j == 12) data12 = d2;//20.3 deg East


    }
  }

  //          Serial.print(data2 + "|");  Serial.print(data3 + "|"); Serial.print(data4 + "|"); Serial.print(data6 + "|");
  //          Serial.println(data9 + "|");
  //----------- lati, lon
  char buf[32];
  data6.toCharArray(buf, sizeof(buf));
  lon = (atof(buf)) / 100;
  data4.toCharArray(buf, sizeof(buf));
  lati = (atof(buf)) / 100;
  // -------------- hour munite secons h:m:s
  String a = data2; //h
  m = data2;
  s = data2;
  a.remove(2);
  h = a.toInt() ;
  m.remove(4);
  m.remove(0, 2);
  s.remove(0, 4);
  s.remove(2);
  //------------date time dd/mm/yy
  data9.remove(0, 1); //////// loi tach mang
  String y = data9;
  mm = data9;
  dd = data9;
  dd.remove(2);
  mm.remove(4);
  mm.remove(0, 2);
  y.remove(0, 4);
  yy = ("20" + y);


  if ( data2 == "" || data4 == "" || data6 == "" || data9 == "" || data8 == "" || data3 == "V"    )  record = false;
}
