# Makefile

# 設定編譯器，通常使用 gcc
CC = gcc

# 設定編譯選項
CFLAGS = -Wall -Wextra

# 目標執行檔名稱
TARGET = hello

# 規則：生成目標執行檔
$(TARGET): main.o sub_function.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o sub_function.o

# 規則：編譯源文件
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sub_function.o: sub_function.c
	$(CC) $(CFLAGS) -c sub_function.c

# 規則：清除生成的文件
clean:
	rm -f *.o $(TARGET)