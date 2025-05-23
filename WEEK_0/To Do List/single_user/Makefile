CC = gcc
CFLAGS = -Wall

TARGET = app

SRC = main.c src/utils.c src/task_handler.c


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)