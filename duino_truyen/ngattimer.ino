/* chuong trình ngắt timer tinh toan va luu 
   các giá trị vào NhietDo , DoAm*/



ISR (TIMER2_OVF_vect)
{
  

  Xung = TCNT1; //Serial.print(Xung);
 
  
  dem=dem+1;
  if (dem==Tquet) //Td*50   0.01*100=1s
  {
  cobao=1;// thực hiện báo tính toán
    dem=0;
  }

 
}
//------------------------------------
ISR (TIMER1_COMPA_vect)
{

  }
