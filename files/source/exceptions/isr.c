#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libraries/vga.h"
#include "../libraries/log.h"
#include "../libraries/exception.h"
#include "../libraries/printf.h"

__attribute__((noreturn))
void exception_handler(uint8_t vector) {
    clear();
    printf("Exception Number as reported by ISR: %d", vector);
    exception(vector);

    __builtin_unreachable();
}