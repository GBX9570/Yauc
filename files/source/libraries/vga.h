#ifndef VGA_H
#define VGA_H

#include <stddef.h>
#include <stdint.h>

enum vga_colour {
    VGA_COLOUR_BLACK = 0,
    VGA_COLOUR_BLUE = 1,
    VGA_COLOUR_GREEN = 2,
    VGA_COLOUR_CYAN = 3,
    VGA_COLOUR_RED = 4,
    VGA_COLOUR_MAGENTA = 5,
    VGA_COLOUR_BROWN = 6,
    VGA_COLOUR_LIGHT_GRAY = 7,
    VGA_COLOUR_DARK_GRAY = 8,
    VGA_COLOUR_LIGHT_BLUE = 9,
    VGA_COLOUR_LIGHT_GREEN = 10,
    VGA_COLOUR_LIGHT_CYAN = 11,
    VGA_COLOUR_LIGHT_RED = 12,
    VGA_COLOUR_LIGHT_MAGENTA = 13,
    VGA_COLOUR_LIGHT_BROWN = 14,
    VGA_COLOUR_WHITE = 15,
};

uint8_t vga_entry_colour(enum vga_colour fg, enum vga_colour bg);
uint16_t vga_entry(unsigned char uc, uint8_t colour);
size_t strlen(const char* str);
void clear(void);
void printcolour(uint8_t colour);
void terminal_putentryat(char c, uint8_t colour, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);

extern const size_t VGA_WIDTH;
extern const size_t VGA_HEIGHT;

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_colour;
extern uint16_t* terminal_buffer;

#endif