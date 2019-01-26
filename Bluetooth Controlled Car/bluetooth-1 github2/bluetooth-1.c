#include<avr/io.h>
#include<util/delay.h>
void send(char send);
void ini();
char rec(void);
void main()
{
int x=0;
DDRC=0Xff;
while(1)
{
char a[11]={'R','B','F','L','S'};
ini();
a[x]=rec();
if(a[x]=='F')
{
PORTC=0B00000101;
_delay_ms(1000);
}
else if(a[x]=='B')
{
PORTC=0B00001010;
_delay_ms(1000);
}
else if(a[x]=='L')
{
PORTC=0B00001001;
_delay_ms(1000);
}
else if(a[x]=='R')
{
PORTC=0B00000110;
_delay_ms(1000);
}
else if(a[x]=='S')
{
PORTC=0x00;
_delay_ms(1000);
}
x++;
}
}



void ini()
{
  UBRRL=51;
 UBRRH=0;
 UCSRB=0x18;
 UCSRC=0x8e;
}
  void send(char send)
  {
    while((UCSRA & 0x20)==0);
	UDR=send;
	}

	char rec(void)
	{
	 while ((UCSRA & 0x80)==0);
	 return UDR;
	 }
