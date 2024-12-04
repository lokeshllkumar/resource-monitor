#include "system_metrics.h"
#include <stdio.h>
#include <stdlib.h>

double get_sys_cpu_usage() {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        return -1;
    }

    long user, nice, sys, idle;
    fscanf(file, "cpu %ld %ld %ld %ld", &user, &nice, &sys, &idle);
    fclose(file);

    long total = user + nice + sys + idle;
    long active = user + nice + sys;
    return (double)active / total * 100;
}

double get_sys_mem_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        return -1;
    }

    long total_mem, free_mem;
    fscanf(file, "MemTotal: %ld kB\nMemFree: %ld kB", &total_mem, &free_mem);
    fclose(file);

    return (1.0 - (double)free_mem / total_mem * 100);
}