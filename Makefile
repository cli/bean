SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)

# Arduino Duemilanove ATmega328P
CFLAGS_AVR=-mmcu=atmega328 -Os -std=c11 -Wall
CFLAGS_AMD64=-O2 -std=c11 -Wall

all: micro pc java

pc:
	$(CC) -DPC -DDEBUG -g $(CFLAGS_AMD64) -I src/include/ $(SRCS) -o bean

java:
	cd java; mvn compile ; cd ..

micro:
	avr-gcc -DATMEGA $(CFLAGS_AVR) -I src/include/ $(SRCS) -o bean.avr

program:
	avrdude -p ATmega328p -P /dev/ttyUSB0 -c arduino -b 57600 -U flash:w:./bean.avr:e

run:
	./bean -cp ./java/target/classes/ Hello
