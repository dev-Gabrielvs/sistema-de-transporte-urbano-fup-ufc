CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion \
         -Wnull-dereference -Wstrict-prototypes -Wmissing-prototypes \
         -std=c11 -g

INCLUDES = -I. -I./includes -I./includes/models -I./includes/controllers \
           -I./database

SRC = database/database.c \
      $(wildcard src/models/*.c) \
      $(wildcard src/controllers/*.c) \
      src/main.c

OUT = transporte

OBJS = $(SRC:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT) -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OUT) $(OBJS)

.PHONY: all clean
