#include <LPC214X.H>
#include "serial.h"
#include "ms_delay.h"

#define sw1 (1<<18)
#define sw2 (1<<19)
#define sw3 (1<<20)
#define sw4 (1<<21)

int main(void)
{
	int a=0;
	IO1DIR |= ((sw1)|(sw2)|(sw3)|(sw4));
	IO1SET |= ((sw1)|(sw2)|(sw3)|(sw4));≥
	uart0_init();
	//while((sw1==1)&&(sw2==1)&&(sw3==1)&&(sw4==1));
	while(1)
	{
		if(!(IO1PIN & sw4))
		{
			IO1SET |= (sw4);
			a=!a;
			ms_delay(1000);
			if(a)
			{
				uart0_putc(0x7E);	// play
				uart0_putc(0xFF);
				uart0_putc(0x06);
				uart0_putc(0x0D);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0xEF);
				ms_delay(500);
			}

			else
			{
				uart0_putc(0x7E);	// pause
				uart0_putc(0xFF);
				uart0_putc(0x06);
				uart0_putc(0x0E);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0xEF);
				ms_delay(500);
			}

		}

	  if(!(IO1PIN & sw3))
		{
			IO1SET |= (sw3);
			if(a)
			{
				uart0_putc(0x7E);
				uart0_putc(0xFF); //play next
				uart0_putc(0x06);
				uart0_putc(0x01);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0xEF);
				ms_delay(500);
			}
		}

		if(!(IO1PIN & sw2))
		{
			IO1SET |= (sw2);
			if(a)
			{
				uart0_putc(0x7E);
				uart0_putc(0xFF);
				uart0_putc(0x06); //play previous
				uart0_putc(0x02);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0x00);
				uart0_putc(0xEF);
				ms_delay(500);
			}
		}

		if(!(IO1PIN & sw1))
		{
			IO1SET |= (sw1);
			uart0_putc(0x7E);
			uart0_putc(0xFF);//stop
			uart0_putc(0x06);
			uart0_putc(0x16);
			uart0_putc(0x00);
			uart0_putc(0x00);
			uart0_putc(0x00);
			uart0_putc(0xEF);
			ms_delay(500);
		}
	}
	
}

