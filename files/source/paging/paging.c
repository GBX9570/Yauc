#include "../libraries/paging.h"
#include <stdint.h>
#include <stddef.h>
#include "../libraries/io.h"

uint32_t page_directory[4096] __attribute__((aligned(4096)));
uint32_t page_tables[1024][1024] __attribute__((aligned(4096)));
unsigned int pageinc = 0;

void page_table_setup() {
    for (uint32_t i = 0; i < 1024; i++) {
        for (uint32_t j = 0; j < 1024; j++) {
            uint32_t addr = (i * 0x400000) + (j * 0x1000);
            page_tables[i][j] = addr | 0x3;
        }
        page_directory[i] = ((uint32_t)page_tables[i]) | 0x3;
        pageinc = 1;
    }
    prints("Paging is UP (4GB paged)\r\n");
}

// thanks past me and sun32 !!
// https://github.com/mikikichi/sun-kernel32/tree/34877a93710ca8b3390cc9a86744818e87faebf4/sun32/src/paging
// comes from here, i wrote the code but im still giving credit cause its not my project (anymore)

// this is only temporary! it maps A LOT of memory when it isn't strictly necessary, its gonna be replaced
// with something more dynamic asap (after PMM and VMM)