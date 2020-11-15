# ======================================================================

# 여기에는 link.ld, 
FRDM_K64F_DIR=/home/mp/frdm_k64f
CMSIS_DIR=/home/joono/study/C/dshin/MicroProcessor/CMSIS

# ======================================================================

CROSS_COMPILE=arm-none-eabi-

AS=$(CROSS_COMPILE)as
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AR=$(CROSS_COMPILE)ar
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump

# ======================================================================

ASFLAGS=-g -mcpu=cortex-m4 -mthumb
CFLAGS=-g -O3 -Wall -mcpu=cortex-m4 -mthumb -fno-builtin -I$(FRDM_K64F_DIR) -I$(CMSIS_DIR)/CMSIS/Include -I$(CMSIS_DIR)/Device/ARM/ARMCM3/Include -I$(CMSIS_DIR)/Device/ARM/ARMCM4/Include
LDFLAGS=-T $(FRDM_K64F_DIR)/link.ld -L $(FRDM_K64F_DIR)

# ======================================================================
# rule 정의 할건데 apsr-print부터 apsr-ge라는 rule까지 모두 실행해 
# 그리고 그 rule들은 아래와 같이 정의 돼 있다.

all:	myMake

# ======================================================================
# PROG 라는 변수에 "apsr-print", OBJS 라는 변수에 "apsr-print.o" 와 같이 할당 후
# make one 이라는 명령 수행 one은 아래와 같이 정의 돼 있다.

myMake:
	export PROG="myMake"; export OBJS="myMake.o"; make one

# ======================================================================
# one은 다음과 같이 정의 돼 있고, 모두를 실행할거야

one:	$(PROG).elf $(PROG).bin

# apsr-print.elf 라는 rule은 $(OBJS)라는 dependent rule에 의존한다.
$(PROG).elf:	$(OBJS)
	$(LD) $(LDFLAGS) $(FRDM_K64F_DIR)/crt0.o $(OBJS) -lfrdm_k64f -o $(PROG).elf

$(PROG).bin:	$(PROG).elf
	$(OBJCOPY) -O binary $(PROG).elf $(PROG).bin

# ======================================================================

send:	all
	kermit -s *.bin

# ======================================================================

cp:	all
	cp *.bin ~/win/Desktop/

# ======================================================================

indent:
	@indent -i2 -kr -nfca *.c
	@rm -f *.c~

# ======================================================================

clean:
	@rm -f *~ *.o *.elf *.dis1 *.dis2 *.bin

# ======================================================================