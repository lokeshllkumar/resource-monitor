#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Config load_config(const char *filename) {
    Config config = {50,
                    LOG_FORMAT_JSON}; // JSON by default
    FILE *file = fopen(filename, "r")    ;
    if (!file) {
        perror("Error opening config file!");
        return config;
    }

    char line[256];
    while (gets(line, sizeof(line), file)) {
        if (strncmp(line, "GRAPH_WIDTH=", 12) == 0) {
            config.graph_width = atoi(line + 12);
        }
        else if (strncmp(line, "LOG_FORMAT=", 11) == 0) {
            if(strncmp(line, "LOG_FORMAT=", 11) == 0) {
                if(strstr(line, "JSON")) {
                    config.log_format = LOG_FORMAT_JSON;
                }
                else if (strstr(line, "CSV")) {
                    config.log_format = LOG_FORMAT_CSV;
                }
            }
        }
    }

    fclose(file);
    return config;
}