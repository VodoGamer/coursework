# Makefile

# Путь к файлу, который мы хотим собрать
SRC = main.cpp

# Путь к директории, где будет создаваться исполняемый файл
BIN = bin

# Название исполняемого файла
EXECUTABLE = main

# Компилятор C++
CC = g++

# Флаги компиляции
CFLAGS = -O2

# Команда для компиляции
all: $(BIN)
	$(CC) $(CFLAGS) $(SRC) -o bin/$(EXECUTABLE)

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean