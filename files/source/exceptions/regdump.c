#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libraries/vga.h"
#include "../libraries/log.h"
#include "../libraries/exception.h"
#include "../libraries/printf.h"

    extern unsigned int eaxv, ebxv, ecxv, edxv;
    extern unsigned int esiv, ediv, ebpv, espv;
    extern unsigned int eflagsv;

extern void capture(void);

void regdump(void) {
    capture();
    printf("EAX: 0x%08x (%u)                EBX: 0x%08x (%u)\nECX: 0x%08x (%u)           EDX: 0x%08x (%u)\n", 
           eaxv, eaxv, ebxv, ebxv, ecxv, ecxv, edxv, edxv);
    printf("ESI: 0x%08x (%u)                EDI: 0x%08x (%u)\nEBP: 0x%08x (%u)          ESP: 0x%08x (%u)\n",
           esiv, esiv, ediv, ediv, ebpv, ebpv, espv, espv);
    printf("EFLAGS: 0x%08x\n", eflagsv);
}