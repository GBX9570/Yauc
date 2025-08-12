#ifndef LOG_H
#define LOG_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "vga.h"

void success(const char* message);
void info(const char* message);
void warn(const char* message);
void error(const char* message);
void panic(const char* message);
void halt(const char* message);

#define VERSION "Yauc 0.0.2 - August 12th 2025"

#endif