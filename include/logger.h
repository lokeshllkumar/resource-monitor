#ifndef LOGGER_H
#define LOGGER_H

#include "config.h"

void log_to_file(const char *filename, double cpu, double mem, LogFormat format);

#endif