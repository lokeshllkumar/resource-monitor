CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/main.c src/config.c src/logger.c src/monitor.c src/process_stats.c src/renderer.c src/system_metrics.c src/utils.c
OBJ = $(SRC:.c=.o)
BIN = reource-monitor

all = $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

clean:
	rm -f $(OBJ) ($BIN)