#include "../include/8051.h"
void delay();
void showLamp();
int main()
{
    while(1)
    {
        showLamp();
    }
}

void delay()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<300;j++){}
    }
}

void showLamp()
{
    int i;
    P1 = 0xfe;
    for(i=0; i<8; i++)
    {
        delay();
        P1 = P1<<1;
        P1 += 1;
    }
    P1 = 0x7f;
    for(i=0; i<8; i++)
    {
        delay();
        P1 = P1>>1;
        P1 += 0x80;
    }
}

void T1_time() __interrupt 3
{
    

}
