#include<reg51.h>
#include"lcd.h"

sbit relay1=P1^4;
sbit relay2=P1^5;
sbit relay3=P1^6;
sbit relay4=P1^7;

void call_relay(void);
void serial_init(void);

unsigned char buff=0;

void main(void)
{
	serial_init();
	LCD_INIT();

	relay1=0;
	relay2=0;
	relay3=0;
	relay4=0;

	LCD_CMD(0x01);
	LCD_STRING("LI-FI DEVICE ");
	LCD_CMD(0xc0);
	LCD_STRING("SWITCHING SYSTEM");
	ms_delay(500);
	LCD_CMD(0x01);
	
	while(1)
	{
		LCD_CMD(0xC0);
		LCD_DISPLAY(buff);
		call_relay();
	}
}

void call_relay(void)
{
	if(buff =='a')
	{
		buff=0;
		LCD_CMD(0x80);
		relay1=1;
		LCD_STRING("DEVICE 1 ON ");		
	}
	
	if(buff =='b')
	{
		buff=0;
		LCD_CMD(0x80);
		relay1=0;
		LCD_STRING("DEVICE 1 OFF");
	}

	if(buff =='c')
	{
		buff=0;
		LCD_CMD(0x80);
		relay2=1;
		LCD_STRING("DEVICE 2 ON ");		
	}
	
	if(buff =='d')
	{
		buff=0;
		LCD_CMD(0x80);
		relay2=0;
		LCD_STRING("DEVICE 2 OFF");
	}
	if(buff =='e')
	{
		buff=0;
		LCD_CMD(0x80);
		relay3=1;
		LCD_STRING("DEVICE 3 ON ");		
	}
	
	if(buff =='f')
	{
		buff=0;
		LCD_CMD(0x80);
		relay3=0;
		LCD_STRING("DEVICE 3 OFF");
	}
	if(buff =='g')
	{
		buff=0;
		LCD_CMD(0x80);
		relay4=1;
		LCD_STRING("DEVICE 4 ON ");		
	}
	
	if(buff =='h')
	{
		buff=0;
		LCD_CMD(0x80);
		relay4=0;
		LCD_STRING("DEVICE 4 OFF");
	}
		
}

void serial_init(void)
{
	TMOD = 0X20;
	IE = 0X90;
	SCON = 0X50;
	TH1 = TL1 = 0Xfa;
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