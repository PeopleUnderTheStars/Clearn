#CC = gcc
#export STAGING_DIR=`pwd`
#CC=/home/yun/bnsd/Q9/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mipsel-openwrt-linux-gcc
CC=/opt/toolchain/OpenWrt-Toolchain-ramips-for-mipsel_24kec+dsp-gcc-4.8-linaro_uClibc-0.9.33.2/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mipsel-openwrt-linux-gcc

SOURCE = $(wildcard *.c)

CFLAGS = 
LFLAGS = 
TARGET = redirect
LDFLAGS = 

OBJECT = $(SOURCE:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECT)
	$(CC) $(OBJECT) -o $(TARGET) $(LFLAGS) $(LDFLAGS)

%.o : %.c
	$(CC) -c $(@D)/$(<F) -o $(@D)/$(@F) $(CFLAGS)

clean :
	rm $(TARGET) $(OBJECT) -f

