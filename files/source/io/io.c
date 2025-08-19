#include <stdbool.h>
#include <stdint.h>
#include "../libraries/io.h"
#include "../libraries/log.h"
#include "../libraries/printf.h"

inline void outb(uint16_t port, uint8_t val) {
    __asm__ volatile ( "outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile ( "inb %w1, %b0"
                   : "=a"(ret)
                   : "Nd"(port)
                   : "memory");
    return ret;
}

inline void io_wait(void) {
    outb(0x80, 0);
}

void picdisable(void) {
    outb(PIC1_DATA, 0xff);
    outb(PIC2_DATA, 0xff);
}

void sendeoi(uint8_t irq) {
    if(irq >= 8)
        outb(PIC2_COMMAND, PIC_EOI);
    
    outb(PIC1_COMMAND, PIC_EOI);
}

void picremap(int offset1, int offset2) {
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4); // start PIC init in cascade mode
    io_wait();
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();
    outb(PIC1_DATA, offset1); // icw2: master PIC vector offset
    io_wait();
    outb(PIC2_DATA, offset2); // icw2: slave PIC vector offset
    io_wait();
    outb(PIC1_DATA, 1 << CASCADE_IRQ); // icw3: tell master PIC that there is
    // slave at IRQ2
    io_wait();
    outb(PIC2_DATA, 2); // tell slave its cascade ID (0000 0010)
    io_wait();
    outb(PIC1_DATA, ICW4_8086); // tell PICs to use 8086 mode not 8080 mode
    io_wait();
    outb(PIC2_DATA, ICW4_8086);
    io_wait();
    // unmask both PICS
    outb(PIC1_DATA, 0);
    outb(PIC2_DATA, 0);
}


void irq_set(uint8_t IRQline) {
    uint16_t port;
    uint8_t value;

    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value);
}

void irq_clear(uint8_t IRQline) {
    uint16_t port;
    uint8_t value;

    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) & ~(1 << IRQline);
    outb(port, value);
}

uint16_t pic_get_irq_reg(int ocw3) {
    outb(PIC1_COMMAND, ocw3);
    outb(PIC2_COMMAND, ocw3);
    return(inb(PIC2_COMMAND) << 8) | inb(PIC1_COMMAND);
}

uint16_t pic_get_isr(void) {
    return pic_get_irq_reg(PIC_READ_ISR);
}

uint16_t pic_get_irr(void) {
    return pic_get_irq_reg(PIC_READ_IRR);
}

int init_serial() {
    outb(PORT + 1, 0x00);   // disable interrupts
    outb(PORT + 3, 0x80);   // enable DLAB (set baud divisor)
    outb(PORT + 0, 0x03);   // set divisor to 3 (low byte), 38400 baud
    outb(PORT + 1, 0x00);   // high byte
    outb(PORT + 3, 0x03);   // 8 bits, no parity, one stop bit
    outb(PORT + 2, 0xC7);   // enable FIFO, clear and set 14 byte threshold
    outb(PORT + 4, 0x0B);   // IRQs enabled, RTS/DSR set
    outb(PORT + 4, 0x1E);   // set in loopback mode for testing
    outb(PORT + 0, 0xAE);   // test serial

    if(inb(PORT + 0) != 0xAE) {
        error("The serial port failed to be initialised.");
        return 1;
    }

    outb(PORT + 4, 0x0F);
    success("Serial is up!");
    return 0;
}

int serialrec() {
    return inb(PORT + 5) & 1;
}

char read_serial() {
    while(serialrec() == 0);
    return inb(PORT);
}

int check_transmit() {
    return inb(PORT + 5) & 0x20;
}

void write_serial(char a) {
    while(check_transmit() == 0) ;

    outb(PORT, a);
}

void prints(const char* str) {
    while(*str) {
        write_serial(*str++);
    }
}

void serial_listen() {
    while (1) {
        char buf[100];
        int i = 0;

        while (1) {
            char c = read_serial();

            if (c == '\n' || c == '\0' || i >= sizeof(buf) - 1) {
                buf[i] = '\0';
                break;
            }

            buf[i++] = c;
        }

        printf(buf);
        printf("\n");
    }
}