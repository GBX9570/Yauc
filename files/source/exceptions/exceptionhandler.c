#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../libraries/vga.h"
#include "../libraries/log.h"
#include "exceptions.h"
#include "../libraries/exception.h"

void exception(int x) {
    switch(x) {
        case 1:
            exception0();
            break;
        case 2:
            exception1();
            break;
        case 3:
            exception2();
            break;
        case 4:
            exception3();
            break;
        case 5:
            exception4();
            break;
        case 6:
            exception5();
            break;
        case 7:
            exception6();
            break;
        case 8:
            exception7();
            break;
        case 9:
            exception8();
            break;
        case 10:
            exception9();
            break;
        case 11:
            exception10();
            break;
        case 12:
            exception11();
            break;
        case 13:
            exception12();
            break;
        case 14:
            exception13();
            break;
        case 15:
            exception14();
            break;
        case 16:
            exception15();
            break;
        case 17:
            exception16();
            break;    
        case 18:
            exception17();
            break;
        case 19:
            exception18();
            break;
        case 20:
            exception19();
            break;
        case 21:
            exception20();
            break;
        case 22:
            exception21();
            break;
        case 23:
            exception22();
            break;
        case 24:
            exception23();
            break;
        case 25:
            exception24();
            break;
        case 26:
            exception25();
            break;
        case 27:
            exception26();
            break;
        case 28:
            exception27();
            break;
        case 29:
            exception28();
            break;
        case 30:
            exception29();
            break;
        case 31:
            exception30();
            break;
        case 32:
            exception31();
            break;
        default:
            dne();
            break;
    }
}