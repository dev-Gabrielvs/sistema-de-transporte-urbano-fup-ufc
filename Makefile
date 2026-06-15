CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion \
         -Wnull-dereference -Wstrict-prototypes -Wmissing-prototypes \
         -std=c11 -g

INCLUDES = -I. -I./includes -I./includes/models -I./includes/controllers \
           -I./database

SRC = src/main.c \
      database/database.c \
      src/models/empresa.c \
      src/controllers/empresas_controller.c

OUT = transporte

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

.PHONY: all clean
