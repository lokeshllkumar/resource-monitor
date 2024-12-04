#ifndef PROCESS_STATS.H
#define PROCESS_STATS.H

typedef struct {
    char name[256];
    double cpu_usage;
    double mem_usage;
} ProcessStats;

int fetch_process_stats(int pid, ProcessStats *stats);

#endif