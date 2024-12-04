#include "renderer.h"
#include <stdio.h>
#include <string.h>

void render_bar(const char *label, double value, Config *config) {
    int width = (int)(value * config -> graph_width);
    printf("%-20s | ", label);

    for (int i = 0; i < width; i++) {
        printf("█");
    }

    for (int i = width; i < config -> graph_width; i++) {
        printf(" ");
    }

    printf(" | %.2f%%\n", value);
}

void render_sparkline(double *data, int len, Config *config) {
    int max_val = 0;
    for (int i = 0; i < len; i++) {
        if (data[i] > max_val) {
            max_val = (int)data[i];
        }
    }

    for (int i = 0; i < len; i++) {
        int bar_length = (int)((data[i] / max_val) * config -> graph_width);
        for (int j = 0; j < bar_length; j++) {
            printf("█");
        }
        printf(" ");
    }
    printf("\n");
}

void clear_screen() {
    printf("\033[H\033[J]");
}