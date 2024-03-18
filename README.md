# TASK 2: Linux Kernel Module for Task Information

## Project Overview

This project involves the development of a Linux kernel module that enables the display of task information through the `/proc` filesystem based on a given process identifier (`PID`). The module allows users to write a `PID` to a file named `/proc/pid` and then read back the task's command name, `PID`, and current state. This document provides a comprehensive overview of the module's functionality, installation, and usage instructions. The module is a collaborative effort by Aditya Verma, Liam Buck T., and Junwen Hu.

## Features

- **PID Input:** Users can write a `PID` to `/proc/pid` to specify the process for which they wish to retrieve information.
- **Task Information Display:** Upon reading from `/proc/pid`, users are presented with the command name, `PID`, and current state of the specified task.
- **Memory Management:** The module demonstrates careful memory management by allocating and freeing kernel memory as required.

## Installation

### Prerequisites

- A Linux system with kernel development tools installed (`build-essential`, `linux-headers-$(uname -r)`)

### Steps

1. **Download the Module Source Code:** Download `pid_module.c` from the provided source repository or attachment.

2. **Compile the Module:**
   Navigate to the directory containing `pid_module.c` and run the following commands to compile the module.

3. **Download the Makefile:** Download `Makefile` from the provided source repository or attachment.

4. **Run `make` to compile `pid_module.c`**

5. **Insert the Module:** Load the compiled module into the kernel with:
   `sudo insmod pid_module.ko`

## Usage

### Writing a PID to `/proc/pid`

Write a process ID to `/proc/pid` using the echo command:
   `echo "1395" > /proc/pid`

Replace `1395` with the `PID` of the task you wish to inquire about.

### Reading Task Information from `/proc/pid`

To display the task information, use the cat command:
   `cat /proc/pid`

This will output the command name, `PID`, and state of the task, similar to:
`command = [bash]`
`pid = [1395]`
`state = [1]`

## Unloading the Module

When finished, unload the module from the kernel with:
   `sudo rmmod pid_module`


![Screenshot (1)](https://github.com/VermaAdi/CS409-Projects/assets/97848600/ec6fee2e-a991-413d-aa61-a0887981bc56)

## Contributors

- Aditya Verma
- Liam Buck T.
- Junwen Hu
