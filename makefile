CC=gcc
DEPS = macros.h mine.h text.h file.h bank.h

bitbotmake: main.c file.c mine.c text.c bank.c
	$(CC) -o bitbot main.c file.c mine.c text.c bank.c
