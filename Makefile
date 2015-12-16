all:main.bin
	rm *.lk *.map *.rel *.sym *.asm *.ihx *.lst *.mem *.rst *.hex

main.bin:main.hex
	hex2bin main.hex

main.hex:main.ihx
	packihx main.ihx > main.hex

main.ihx:main.c 
	sdcc main.c

#删除.bin文件
.PHONY:clean
clean:
	-rm *.bin 

#用于烧写软件，在命令使用之后在打开单片机的开关。
.PHONY:burn
burn:
	sudo python /usr/mycom/stcflash.py main.bin
