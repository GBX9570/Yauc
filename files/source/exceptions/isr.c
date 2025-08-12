#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libraries/vga.h"
#include "../libraries/log.h"
#include "../libraries/exception.h"

__attribute__((noreturn))
void exception_handler(uint8_t vector) {

    exception(vector);

    __builtin_unreachable();
}