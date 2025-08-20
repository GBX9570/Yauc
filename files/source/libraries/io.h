#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stdint.h>
#include "../libraries/log.h"

void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);
void io_wait(void);
void picdisable(void);
void picdisable(void);
void sendeoi(uint8_t irq);
void picremap(int offset1, int offset2);
void picdisable(void);
void irq_set(uint8_t IRQline);
void irq_clear(uint8_t IRQline);
uint16_t pic_get_irq_reg(int ocw3);
uint16_t pic_get_isr(void);
uint16_t pic_get_irr(void);
int init_serial(void);
int serialrec(void);
char read_serial(void);
int check_transmit(void);
void write_serial(char a);
void prints(const char* str);

#define PIC1		0x20 // io for master pic
#define PIC2		0xA0 // io for slave pic
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)
#define PIC_EOI     0x20 // end of interrupt
#define ICW1_ICW4	0x01		/* Indicates that ICW4 will be present */
#define ICW1_SINGLE	0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	0x10		/* Initialization - required! */

#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */

# define CASCADE_IRQ 2

#define PIC_READ_IRR    0x0a    // 0xw3 irq ready next cmd read
#define PIC_READ_ISR    0x0b    // ocw3 irq service next cmd read

/* all credit to the OSDev wiki for this (and most things)
    http://wiki.osdev.org/8259_PIC, http://wiki.osdev.org/
*/

// serial time

#define PORT 0x3f8

#endif