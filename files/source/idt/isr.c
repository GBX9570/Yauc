#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libraries/vga.h"
#include "../libraries/log.h"

__attribute__((noreturn))
void exception_handler(uint8_t vector) {

 switch(vector) {
        case 0:
            panic("division by zero.\n");
            break;
        case 1:
            panic("debig\n");
            break;
        case 2:
            panic("non-maskable interrupt\n");
            break;
        case 3:
            panic("breakpoint\n");
            break;
        case 4:
            panic("overflow\n");
            break;
        case 5:
            panic("bound range exceeded\n");
            break;
        case 6:
            panic("invalid opcode\n");
            break;
        case 7:
            panic("device not available\n");
            break;
        case 8:
            panic("double fault\n");
            break;
        case 9:
            panic("coprocessor segment overrun\n");
            break;
        case 10:
            panic("invalid TSS\n");
            break;
        case 11:
            panic("segment not present\n");
            break;
        case 12:
            panic("stack-segment fault\n");
            break;
        case 13:
            panic("general protection fault\n");
            break;
        case 14:
            panic("page fault\n");
            break;
        case 15:
            panic("reserved\n");
            break;
        case 16:
            panic("x87 floating-point exception\n");
            break;
        case 17:
            panic("alignment check\n");
            break;
        case 18:
            panic("machine check\n");
            break;
        case 19:
            panic("SIMD floating point exception\n");
            break;
        case 20:
            panic("virtualisation exception\n");
            break;
        case 21:
            panic("control protection exception\n");
            break;
        case 22:
            panic("reserved\n");
            break;
        case 23:
            panic("reserved\n");
            break;
        case 24:
            panic("reserved\n");
            break;
        case 25:
            panic("reserved\n");
            break;
        case 26:
            panic("reserved\n");
            break;
        case 27:
            panic("reserved\n");
            break;
        case 28:
            panic("hypervisor injection exception\n");
            break;
        case 29:
            panic("VMM communication exception\n");
            break;
        case 30:
            panic("security exception\n");
            break;
        case 31:
            panic("reserved\n");
            break;
        default:
            const char* msgdefault = "unknown exception\n";
            panic(msgdefault);
            break;
    }

    __builtin_unreachable();
}