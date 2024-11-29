#include <stdio.h>
#include <string.h>
#include "monitor.h"
#include "config.h"

void print_usage(const char *prog_name) {
    printf("Usage: %s [--real-time | --log | --detailed]\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}