#ifndef MONITOR_H
#define MONITOR_H

#include "config.h"

void monitor_system(Config *config, int log);

void monitor_process(int pid, int log, Config *config);

void monitor_process_detailed(int pid, Config *config);

#endif