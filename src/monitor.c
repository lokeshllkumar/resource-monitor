#include "monitor.h"
#include "process_stats.h"
#include "renderer.h"
#include "logger.h"
#include "utils.h"
#include "system_metrics.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static volatile int running = 1; // not to be optimised

void handle_signal(int sig) {
    running = 0;
}

void monitor_system(Config *config, int log) {
    signal(SIGINT, handle_signal);

    while(running) {
        double cpu = get_sys_cpu_usage();
        double mem = get_sys_mem_usage();

        clear_screen();
        printf("System Monitoring\n");
        printf("=================\n");
        render_bar("CPU Usage", cpu, config);
        render_bar("Memory Usage", mem, config);

        if (log) {
            log_to_file("logs/system.log", cpu, mem, config -> log_format);
        }

        sleep(1);
    }
}

void monitor_process(int pid, int log, Config *config) {
    signal(SIGINT, handle_signal);

    while (running) {  
        ProcessStats stats;
        if (fetch_process_stats(pid, &stats) == -1) {
            fprintf(stderr, "Error: Could not fetch stats for PID %i", pid);
            return;
        }

        clear_screen();
        printf("Monitoring Process (PID: %i)\n", pid);
        printf("============================\n");
        render_bar("CPU Usage", stats.cpu_usage, config);
        render_bar("Memory Usage", stats.mem_usage, config);

        if (log) {
            log_to_file("logs/process.log", stats.cpu_usage, stats.mem_usage, config -> log_format);
        }

        sleep(1);
    }
}

void monitor_process_detailed(int pid, Config *config) {
    signal(SIGINT, handle_signal)   ;

    while (running) {
        ProcessStats stats;
        if (fetch_process_stats(pid, &stats) == -1) {
            fprintf(stderr, "Error: Could not fetch stats for PID %i", pid);
            return;
        }

        clear_screen();
        printf("Detailed Monitoring (PID: %i)\n", pid);
        printf("=============================\n");
        printf("Name: %-15s\n", stats.name);
        printf("CPU Usage: %.4f%%\n", stats.cpu_usage);
        printf("Memory Usage: %.4f%%\n", stats.mem_usage);

        sleep(1);
    }
}