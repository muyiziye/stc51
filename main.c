#include "8051.h"
void delay();
int main()
{
    while(1)
    {
        P1_0=0;
        delay();
        P1_0=1;
        delay();
    }
}

void delay()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++){}
    }
}
