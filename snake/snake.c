/*************************************************************************
	> File Name: snake.c
	> Author: muyiziye
	> Mail: ahfyly@foxmail.com
	> Created Time: 2016年12月01日 星期四 20时31分09秒
 ************************************************************************/

#include "../include/8051.h"

unsigned char segout[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned __code char tab[] = {0x00, 0x6c, 0x92, 0x82, 0x44, 0x28, 0x10, 0x00};

__sbit __at (0x90) LATCH;
__sbit __at (0x91) SRCLK;
__sbit __at (0x92) SER ;

__sbit __at (0xA0) LATCH_B;
__sbit __at (0xA1) SRCLK_B;
__sbit __at (0xA2) SER_B ;

void DelayUs2x(unsigned char t)
{
    while(--t);
}

void DelayMs(unsigned char t)
{
    while(t--)
    {
        DelayUs2x(245);
        DelayUs2x(245);
    }
}

void SendByte(unsigned char dat)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
    {
        SRCLK = 0;
        SER = dat&0x80;
        dat <<= 1;
        SRCLK = 1;
    }
}

void Send2Byte(unsigned char dat1, unsigned char dat2)
{
    SendByte(dat1);
    SendByte(dat2);
}

void Out595(void)
{
    LATCH = 0;
    DelayUs2x(1);
    LATCH = 1;
}

void SendSeg(unsigned char dat)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        SRCLK_B = 0;
        SER_B = dat & 0x80;
        dat <<= 1;
        SRCLK_B = 1;
    }
    LATCH_B = 0;
    DelayUs2x(1);
    LATCH_B = 1;
}

int main()
{
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            SendSeg(segout[i]);
            Send2Byte(~tab[i], 0xff);
            Out595();
            DelayMs(1);

            Send2Byte(0xff, 0xff);
            Out595();
        }
    }
}

