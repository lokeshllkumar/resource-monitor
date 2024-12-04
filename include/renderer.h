#ifndef RENDERER_H
#define RENDERER_H

#include "config.h"

void render_bar(const char *label, double value, Config *config);

void render_sparkline(double *data, int len, Config *config);

void clear_screen();

#endif