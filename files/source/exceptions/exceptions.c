#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libraries/vga.h"
#include "../libraries/log.h"

void exception0() {
    panic("Division Error 0x0");
}

void exception1() {
    panic("Debug 0x1");
}

void exception2() {
    panic("Non-maskable Interrupt 0x2");
}

void exception3() {
    panic("Breakpoint 0x3");
}

void exception4() {
    panic("Overflow 0x4");
}

void exception5() {
    panic("Bound Range Overflow 0x5");
}

void exception6() {
    panic("Invalid Opcode 0x6");
}

void exception7() {
    panic("Device Not Available 0x7");
}

void exception8() {
    panic("Double Fault 0x8");
}

void exception9() {
    panic("Coprocessor Segment Overun 0x9");
}

void exception10() {
    panic("Invalid TSS 0xA");
}

void exception11() {
    panic("Segment Not Present 0xB");
}

void exception12() {
    panic("Stack-Segment Fault 0xC");
}

void exception13() {
    panic("General Protection Fault 0xD");
}

void exception14() {
    panic("Page Fault 0xE");
}

void exception15() {
    panic("Reserved 0xF");
}

void exception16() {
    panic("x87 Floating-Point Exception 0x10");
}

void exception17() {
    panic("Alignment Check 0x11");
}

void exception18() {
    panic("Machine Check 0x12");
}

void exception19() {
    panic("SIMD Floating-Point Exception 0x13");
}

void exception20() {
    panic("Virtualisation Exception 0x14");
}

void exception21() {
    panic("Control Protection Exception 0x15");
}

void exception22() {
    panic("Reserved 0x16");
}

void exception23() {
    panic("Reserved 0x17");
}

void exception24() {
    panic("Reserved 0x18");
}

void exception25() {
    panic("Reserved 0x19");
}

void exception26() {
    panic("Reserved 0x1A");
}

void exception27() {
    panic("Reserved 0x1B");
}

void exception28() {
    panic("Hypervisor Injection Exception 0x1C");
}

void exception29() {
    panic("VMM Communication Exception 0x1D");
}

void exception30() {
    panic("Reserved 0x1E");
}

void exception31() {
    panic("Reserved 0x1F");
}
