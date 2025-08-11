# YAUC
Yet Another Unix Clone
* Pronounced Y-ow-k

### What is this?
Yauc is an operating system made alone by me (GBX9570) as a hobbyist project. I can't dedicate too much time to this, because I am still in school - however I will add features and fix bugs as much as possible. It is planned to be a Unix-like operating system with no standout features (at the time of writing).

**This is a *HOBBYIST* project! Do not expect professional quality in code, or frequent updates.**

### Required Tools
* nasm
* qemu
* x86 GCC cross compiler
* x86 binutils cross compiler
- (for above of the above, reference this document: https://wiki.osdev.org/GCC_Cross-Compiler)
* xorriso
* grub-mkrescue (grub/grub2 package)

### Building
To build Yauc, run `make all`. All files will be compiled to files/source/compiled, and then made into a kernel.bin that is moved into files/isofiles/boot/kernel.bin.
**FEDORA/REDHAT USERS!** edit all references to grub-mkrescue in the makefile to grub2-mkrescue!!
Credit to *https://github.com/mikikichi* for letting me use her makefile from *https://github.com/GBX9570/sun-kernel* (my repo for now but she's the lead)!!
