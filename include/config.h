#ifndef CONFIG_H
#define CONFIG_H

typedef enum {
    LOG_FORMAT_JSON,
    LOG_FORMAT_CSV
} LogFormat;

typedef struct {
    int graph_width;
    LogFormat log_format;
} Config;

Config load_config(const char *filename);

#endif