void SetUpTimer()
{
//cấm ngắt 
cli();
// reset timer 1 trên ATMEGA 328p
TCCR2A=0;
TCCR2B=0;
TIMSK2=0;
TCCR1A=0;
TCCR1B=0;
TIMSK1=0;
// prescaler =1024. tần số hoạt động của timer 1 là 16MHz/1024 = 62.50kHz. ,
//nếu để mặc định là 64
TCCR2B |= (1<<CS22)|(1<<CS21)|(1<<CS20);
// thời gian set cho timer2 OVF là 0.1 s
TCNT2=100;
// cho phép ngắt tràn
TIMSK2=(1<<TOIE2);

//   timer 1
TCCR1B |= (1<<CS12)|(1<<CS11);
//TIMSK1 |=(1<<TOIE1);

//cho phep ngắt
sei(); 
}
