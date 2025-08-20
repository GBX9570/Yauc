#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "libraries/printf.h"
#include "libraries/vga.h"
#include "libraries/log.h"
#include "libraries/regdump.h"
#include "libraries/io.h"

void success(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_GREEN, VGA_COLOUR_BLACK));
    printf("[  GOOD  ] ");
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("\n");
}

void info(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BLUE, VGA_COLOUR_BLACK));
    printf("[  INFO  ] ");
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("\n");
}

void warn(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_BROWN, VGA_COLOUR_BLACK));
    printf("[  WARN  ] ");
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("\n");
}

void error(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_RED, VGA_COLOUR_BLACK));
    printf("[  WARN  ] ");
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("\n");
}

void _panic(const char* message, const char* file, int line) {
    clear();
    __asm__ __volatile__("cli");
    printcolour(vga_entry_colour(VGA_COLOUR_RED, VGA_COLOUR_BLACK));
    printf("Yauc has ran into an unexpected problem.\n");
    prints("Yauc has ran into an unexpected problem.\r\n");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    prints("Exception: ");
    prints(message);
    prints("\r\n");
    printf("Exception: %s", message);
    printf("\n%s", VERSION);
    prints(VERSION);
    prints("\r\n");
    printf("\n");
    printf("Occured at %s at line %d\n", file, line);
    prints("Occurred in: ");
    prints(file);
    prints("\r\n");
    printf("Please report this on the GitHub.\n");
    printf("https://github.com/GBX9570/yauc\n");
    info("It is now safe to turn off the computer.");
    warn("Info for nerds:");
    regdump();
    __asm__ __volatile("hlt");
}

void halt(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_RED, VGA_COLOUR_BLACK));
    printf("[  HALT  ] ");
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("\n");
    __asm__ __volatile("cli");
    __asm__ __volatile("hlt");
}