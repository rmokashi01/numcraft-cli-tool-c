CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/quiz.c src/twos_complement.c src/visualizer.c src/bit_byte_ops.c
OUT = build/number_system_app

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
