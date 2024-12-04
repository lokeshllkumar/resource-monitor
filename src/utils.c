#include "utils.h"
#include <stdio.h>

void print_usage(const char *prog_name) {
    printf("Usage: %s [--real-time | --log | --detailed] [--pid <PID>]\n", prog_name);
}