all:snake.bin
	rm *.lk *.map *.rel *.sym *.asm *.ihx *.lst *.mem *.rst *.hex

snake.bin:snake.hex
	hex2bin snake.ihx

snake.hex:snake.ihx
	packihx snake.ihx > snake.hex

snake.ihx:snake.c
	sdcc snake.c

#删除.bin文件
.PHONY:clean
clean:
	-rm -f *.bin

#用于烧写软件，在命令使用之后再打开单片机的开关
.PHONY:burn
burn:
	sudo python /usr/mycom/stcflash.py snake.bin
