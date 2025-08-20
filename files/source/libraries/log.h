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
void halt(const char* message);

#define VERSION "Yauc 0.0.3 - August 20th 2025"

#define panic(message) _panic(message, __FILE__, __LINE__)
void _panic(const char* message, const char* file, int line);

#endif