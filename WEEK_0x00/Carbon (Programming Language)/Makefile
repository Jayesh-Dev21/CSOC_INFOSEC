CC = gcc
CFLAGS = -Wall

TARGET = carbon_run

SRC = main.c src/lexer.c src/transpiler.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)