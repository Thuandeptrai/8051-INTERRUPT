#include<reg51.h>
sbit led1= P2^0;
sbit led2= P2^1;
sbit led3= P2^2;
sbit led4= P2^3;
void ISR_ex0(void);
void Delay();
void main()
{
        P0 = 0x00;    // Make all pins zero
        P1 = 0x00;    // Make all pins zero
        P2 = 0x00;    // Make all pins zero
        P3 = 0x04;    // making Port3 pin 2 high
        IE=0x81;             // Enable INT0
        IT0=1;                 // Set Falling Edge Trigger for INT0
 while(1)
    {             
         led1= 1;
         led2= 0;
         led3= 1;
         led4= 0;
    }

}

//  Interrupt service routine function
void ISR_ex0(void) interrupt 0     // ISR for external interrupt INT0
      {

           led1=~led1;
           led2=~led2;
           led3=~led3;
           led4=~led4;
           Delay();              
     }

//  Initialize delay with timer0 
void Delay()
   {

     int i;
     TMOD = 0x01;      // Timer0 mode1

                for(i=0;i<200;i++)
                {

               TH0=0xF8;              //initial values for 1sec delay
                TL0=0xCC;
                TR0 = 1;               // timer0 start
            while (TF0 == 0);   // check overflow condition
                TR0 = 0;               // Stop Timer
                TF0 = 0;               // Clear flag
              }

}