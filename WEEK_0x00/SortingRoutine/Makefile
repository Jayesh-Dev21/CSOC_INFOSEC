CC = gcc
CFLAGS = -Wall 

TARGET = sort_app

SRC = main.c sortFunctions/bubbleSort.c sortFunctions/insertionSort.c
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
	
