# MPLAB IDE generated this makefile for use with GNU make.
# Project: rangsons.mcp
# Date: Wed May 06 15:38:37 2015

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

output/rangsons.cof : obj/app.o obj/board.o obj/communication.o obj/digitdisplay.o obj/heartBeat.o obj/interruptvector.o obj/linearkeypad.o obj/main.o obj/MMD.o obj/timer.o obj/uart.o
	$(LD) /p18F8722 /l"C:\Program Files\Microchip\mplabc18\v3.46\lib" "18f8722_g.lkr" "obj\app.o" "obj\board.o" "obj\communication.o" "obj\digitdisplay.o" "obj\heartBeat.o" "obj\interruptvector.o" "obj\linearkeypad.o" "obj\main.o" "obj\MMD.o" "obj\timer.o" "obj\uart.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"output\rangsons.cof" /M"output\rangsons.map" /W

obj/app.o : source/app.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/digitdisplay.h include/mmd.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/string.h include/communication.h include/mmd.h include/app.h include/linearkeypad.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/eep.h source/app.c include/config.h include/typedefs.h include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/stddef.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\app.c" -fo="obj\app.o" -D__DEBUG -O-

obj/board.o : source/board.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h source/board.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\board.c" -fo="obj\board.o" -D__DEBUG -O-

obj/communication.o : source/communication.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/communication.h include/uart.h include/timer.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/usart.h source/communication.c include/config.h include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\communication.c" -fo="obj\communication.o" -D__DEBUG -O-

obj/digitdisplay.o : source/digitdisplay.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/digitdisplay.h source/digitdisplay.c include/config.h include/typedefs.h include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\digitdisplay.c" -fo="obj\digitdisplay.o" -D__DEBUG -O-

obj/heartBeat.o : source/heartBeat.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h source/heartBeat.c include/typedefs.h include/heartbeat.h include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/config.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\heartBeat.c" -fo="obj\heartBeat.o" -D__DEBUG -O-

obj/interruptvector.o : source/interruptvector.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/timer.h include/uart.h source/interruptvector.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\interruptvector.c" -fo="obj\interruptvector.o" -D__DEBUG -O-

obj/linearkeypad.o : source/linearkeypad.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/linearkeypad.h source/linearkeypad.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\linearkeypad.c" -fo="obj\linearkeypad.o" -D__DEBUG -O-

obj/main.o : source/main.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/timer.h include/uart.h include/communication.h include/mmd.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/string.h include/app.h include/mmd.h include/digitdisplay.h include/linearkeypad.h source/main.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h include/heartBeat.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/stddef.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\main.c" -fo="obj\main.o" -D__DEBUG -O-

obj/MMD.o : source/MMD.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/mmd.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/string.h source/MMD.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/stddef.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\MMD.c" -fo="obj\MMD.o" -D__DEBUG -O-

obj/timer.o : source/timer.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h include/timer.h source/timer.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\timer.c" -fo="obj\timer.o" -D__DEBUG -O-

obj/uart.o : source/uart.c ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/delays.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/timers.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/string.h include/uart.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/usart.h source/uart.c include/board.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18f8722.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/p18cxxx.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/pconfig.h include/typedefs.h include/config.h ../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.46/h/stddef.h
	$(CC) -p=18F8722 /i"include" -I"C:\Program Files\Microchip\mplabc18\v3.46\h" "source\uart.c" -fo="obj\uart.o" -D__DEBUG -O-

clean : 
	$(RM) "obj\app.o" "obj\board.o" "obj\communication.o" "obj\digitdisplay.o" "obj\heartBeat.o" "obj\interruptvector.o" "obj\linearkeypad.o" "obj\main.o" "obj\MMD.o" "obj\timer.o" "obj\uart.o" "output\rangsons.cof" "output\rangsons.hex"

