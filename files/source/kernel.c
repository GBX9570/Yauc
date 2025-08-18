#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "libraries/log.h"
#include "libraries/idt.h"
#include "libraries/printf.h"
#include "libraries/gdt.h"

void cmain(void) {
    clear();
    printcolour(vga_entry_colour(VGA_COLOUR_LIGHT_BLUE, VGA_COLOUR_BLACK));
    printf("dP    dP                            \n");
    printf("Y8.  .8P                            \n");
    printf(" Y8aa8P  .d8888b. dP    dP .d8888b. \n");
    printf("   88    88'  `88 88    88 88'  `"" \n");
    printf("   88    88.  .88 88.  .88 88.  ... \n");
    printf("   dP    `88888P8 `88888P' `88888P' \n");
    printf("oooooooooooooooooooooooooooooooooooo\n");
    printf("     YET ANOTHER UNIX CLONE\n");
    printf("                 ^^^^^^^^^^ eventually\n");
    printcolour(vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLACK));
    gdt_setup();
    success("GDT Loaded!");
    idt_init();
    success("IDT Loaded!");
    
}