#include<reg51.h>
#include"lcd.h"
#define DATA_BUS P0

sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;

//void main(void)
//{
//	LCD_INIT();
//	LCD_STRING("E_rachit.... ");
//	while(1);
//}


void LCD_INIT(void)
{
	LCD_CMD(0x38);//8bit operation
	LCD_CMD(0x0c);//disp On cursor off
	LCD_CMD(0x01);//clear screen
	LCD_CMD(0x80);//select DDRAM
} 

void LCD_CMD(unsigned char c)
{
	RS=0;RW=0;
	DATA_BUS=c;
	EN=1;
	ms_delay(2);
	EN=0;
}

void LCD_DISPLAY(unsigned char c)
{
	RS=1;RW=0;
	DATA_BUS=c;
	EN=1;
	ms_delay(2);
	EN=0;
}

void LCD_STRING(unsigned char *s)
{
	while(*s)
	LCD_DISPLAY(*s++);
}

void ms_delay(int i)
{
	int j,k;

	for(j=0;j<i;j++)
	for(k=0;k<1275;k++);
}