
# TryOS: A simple x86-OS

TryOS is a built-from-scratch x86 operating system, created with the intention of learning
and understanding the basics of OS development. The technical expertise that comes with the development
of this project will aid in future endeavours in the field of computer architecture and system design.




## Features

![App Screenshot](https://i.ibb.co/GCVwr9x/cap.png)

1) Boot sector with customized GDT to use protected mode (32-bit) ✔️
2) Simple kernel with VGA screen drivers ✔️
3) Complete emulation in QEMU/Bochs ✔️

## To-do
1) Create a PS/2 device driver, allowing inputs from keyboards and mice
2) Activate VESA BIOS extensions in QEMU and reformat screen drivers
3) Work on extended features: processes, filesystem etc.




## Installation

Currently, the makefile pertains purely to Windows. A makefile for Unix-based OS will be added in the near future.

It is essential that we have these following softwares installed, and are added to the path. 
1) [mingw32](https://sourceforge.net/projects/mingw/) - A minimalistic GNU port
2) [nasm](https://www.nasm.us/) - An x86 assembler
3) [QEMU](https://www.qemu.org/) - A open-source machine emulator
For instructions on how to add the installed locations to path, click [here](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/).

To create the OS image and run it on QEMU
```bash
mingw32-make 
```
To clean previosuly created binary files and other intermediate formats
```bash
mingw32-make clean
```
    