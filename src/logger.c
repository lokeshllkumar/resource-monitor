#include "logger.h"
#include <stdio.h>
#include <time.h>

void log_to_file(const char *filename, double cpu, double mem, LogFormat format) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Error opening log file!");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H-%M:%S", tm_info);

    if (format == LOG_FORMAT_JSON) {
        fprintf(file, "{ \"timestamp\": \"%s\", \"cpu\": %.2f, \"memory\": %.2f }\n", time_str, cpu, mem);
    }
    else if (format == LOG_FORMAT_CSV) {
        fprintf(file, "%s,%.2f,%.2f\n", time_str, cpu, mem);
    }

    fclose(file);
}