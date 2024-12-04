#include "process_stats.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fetch_process_stats(int pid, ProcessStats *stats) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    FILE *file = fopen(path, "r");
    if (!file) {
        return -1;
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    sscanf(buffer, "%*d (%[^)]%) %*c %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d %lf %lf",
            stats -> name, &stats -> cpu_usage, &stats -> mem_usage);

    return 0;
}