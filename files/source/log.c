#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "libraries/printf.h"
#include "libraries/vga.h"
#include "libraries/log.h"

void success(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_GREEN, VGA_COLOUR_BLACK));
    printf("[  GOOD  ] ");
    printf(message);
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("\n");
}

void info(const char* message) {
    printcolour(vga_entry_colour(VGA_COLOUR_BLUE, VGA_COLOUR_BLACK));
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

void panic(const char* message) {
    
    __asm__ __volatile__("cli");
    printcolour(vga_entry_colour(VGA_COLOUR_RED, VGA_COLOUR_BLACK));
    printf("\n");
    printf("dP    dP                            \n");
    printf("Y8.  .8P                            \n");
    printf(" Y8aa8P  .d8888b. dP    dP .d8888b. \n");
    printf("   88    88'  `88 88    88 88'  `"" \n");
    printf("   88    88.  .88 88.  .88 88.  ... \n");
    printf("   dP    `88888P8 `88888P' `88888P' \n");
    printf("oooooooooooooooooooooooooooooooooooo\n");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    printf("Yauc has ran into an unexpected problem.\n");
    printf("Exception: %s", message);
    printf("\n");
    printf(VERSION);
    printf("\n");
    printf("Please report this on the GitHub.\n");
    printf("https://github.com/GBX9570/yauc\n");
    info("It is now safe to turn off the computer.");
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