#include<reg51.h>
#include"lcd.h"

sbit sw1=P1^4;
sbit sw2=P1^5;
sbit sw3=P1^6;
sbit sw4=P1^7;

void call_relay(void);
void serial_init(void);
void serial_send(unsigned char a);


unsigned char buff=0;
int a,b,c,d,i;

void main(void)
{
	serial_init();
	LCD_INIT();
	sw1=1;
	sw2=1;
	sw3=1;
	sw4=1;

	LCD_CMD(0x01);
	LCD_STRING("LI-FI DEVICE");
	LCD_CMD(0xc0);
	LCD_STRING("SWITCHING SYSTEM");
	LCD_CMD(0x80);
	//ms_delay(1000);
	while(1)
	{
		serial_send('X');
		ms_delay(5);
		serial_send('Y');
		ms_delay(5);
		
		if(sw1==0)
		{
			a=!a;
			if(a)
			{
				sw1=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 1 ON");
				for(i=0;i<50;i++)
				{
					serial_send('a');
					ms_delay(5);
				}

			}
			
			else
			{
				sw1=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 1 OFF");
				for(i=0;i<50;i++)
				{
					serial_send('b');
					ms_delay(5);
				}
				
			}	
		}

		if(sw2==0)
		{
			b=!b;
			if(b)
			{
				sw2=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 2 ON");
				for(i=0;i<50;i++)
				{
					serial_send('c');
					ms_delay(5);
				}
			}
			
			else
			{
				sw2=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 2 OFF");
				for(i=0;i<50;i++)
				{
					serial_send('d');
					ms_delay(5);
				}
			}	
		}

		if(sw3==0)
		{
			c=!c;
			if(c)
			{
				sw3=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 3 ON");
				for(i=0;i<50;i++)
				{
					serial_send('e');
					ms_delay(5);
				}
			}
			
			else
			{
				sw3=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 3 OFF");
				for(i=0;i<50;i++)
				{
					serial_send('f');
					ms_delay(5);
				}
			}	
		}

		if(sw4==0)
		{
			d=!d;
			if(d)
			{
				sw4=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 4 ON");
				for(i=0;i<50;i++)
				{
					serial_send('g');
					ms_delay(5);
				}
			}
			
			else
			{
				sw4=1;
				LCD_CMD(0x01);
				LCD_STRING("DEVICE 4 OFF");
				for(i=0;i<50;i++)
				{
					serial_send('h');
					ms_delay(5);
				}
			}	
		}

	

	}
}


void serial_init(void)
{
	TMOD = 0X20; // timer 1 and 8 bit auto raload
	IE = 0X90;// serila interrupt
	SCON = 0X50; // 8 bit uart
	TH1 = TL1 = 0Xfa; // 4800 baud rate
	TR1 = 1;
}

void serial_rec(void)interrupt 4
{
	if(TI == 1)
	{
	 	TI = 0;
	}
	else
	{
		buff = SBUF;	
		RI = 0;
	}
}

void serial_send(unsigned char a)
{
 SBUF=a;
}