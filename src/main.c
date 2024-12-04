#include <stdio.h>
#include <string.h>
#include "monitor.h"
#include "config.h"
#include "utils.h"

void print_usage(const char *prog_name) {
    printf("Usage: %s [--real-time | --log | --detailed] [--pid <PID>]\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        print_usage(argv[0]);
        return 1;
    }

    Config config = load_config("config/monitor.conf");

    int pid = -1;
    int mode = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--real-time") == 0) {
            mode = 0;
        }
        else if (strcmp(argv[i], "--log") == 0) {
            mode = 1;
        }
        else if (strcmp(argv[i], "--detailed") == 0) {
            mode = 2;
        }
        else if (strcmp(argv[i], "--pid") == 0 && i + 1 < argc) {
            pid = atoi(argv[++i]);
        }
        else {
            print_usage(argv[0]);
            return 1;
        }
    }

    if (mode == -1) {
        print_usage(argv[0]);
        return 1;
    }

    if (mode == 2 && pid != -1) {
        monitor_process_detailed(pid, &config);
    }
    else if (pid != -1) {
        monitor_process(pid, mode, &config);
    }
    else if (mode == 0 || mode == 1) {
        monitor_system(&config, mode);
    }

    return 0;
}