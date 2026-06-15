CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion \
         -Wnull-dereference -Wstrict-prototypes -Wmissing-prototypes \
         -std=c11 -g

INCLUDES = -I. -I./includes -I./includes/models -I./includes/controllers \
           -I./database

SRC = database/database.c \
      $(wildcard src/models/*.c) \
      $(wildcard src/controllers/*.c)

OUT = transporte

OBJS = $(SRC:.c=.o)

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

link: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) $(OBJS)

.PHONY: all clean
