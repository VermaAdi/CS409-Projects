# Dropbox Link for the Team's Linux Virtual Machine

   https://www.dropbox.com/scl/fo/qzh04ic8qq91cxjkgq7g4/h?rlkey=gy191r7q76aufvj2kbfvcnxjv&dl=0

   **Root Password:** bu1234
   The directories for the files are `Downloads/ch2/jiffies`, `Downloads/ch2/seconds` and `Downloads/ch2/pid_module`

# TASK 1: Linux Kernel Modules for Jiffies and Seconds

## Project Overview

This project involves the development and utilization of two Linux kernel modules: one that exposes the current value of jiffies (`jiffies.c`) and another that shows the elapsed time in seconds since it was loaded (`seconds.c`). Both modules make use of the `/proc` filesystem to communicate these values to user space. This README provides a detailed overview of each module's functionality, along with instructions for installation, usage, and testing. This is a joint effort by [Your Name], [Team Member's Name], and [Team Member's Name].

## Features

- **Jiffies Display:** Allows users to read the current value of jiffies from `/proc/jiffies`, offering insight into system ticks since boot.
- **Seconds Elapsed Display:** Enables users to determine the number of seconds elapsed since the `seconds` module was loaded, accessible through `/proc/seconds`.
- **Efficient Kernel Interaction:** Demonstrates efficient interaction with the Linux kernel and the `/proc` filesystem.

## Installation

### Prerequisites

Ensure your Linux system has the necessary kernel development tools (`build-essential`, `linux-headers-$(uname -r)`).

### Steps for jiffies.c and seconds.c

#### jiffies.c

1. **Prepare the Environment:** Navigate to the directory containing `jiffies.c` and the makefile.
2. **Compile:** Ensure the makefile is prepared to compile `jiffies.o` and execute `make`.
3. **Load the Module:** Use `sudo insmod jiffies.ko` to load the module.
4. **Verify Creation:** Check the creation of `/proc/jiffies` file with `sudo dmesg -c`.
5. **Read Jiffies Value:** Obtain the current jiffies value via `cat /proc/jiffies`.
6. **Unload:** Remove the kernel module using `sudo rmmod jiffies`.
7. **Confirm Removal:** Ensure `/proc/jiffies` is removed with `sudo dmesg -c`.

#### seconds.c

1. **Prepare the Environment:** Navigate to the directory containing `seconds.c` and the makefile.
2. **Compile:** Verify the makefile targets `seconds.o` and run `make`.
3. **Load the Module:** Insert the module with `sudo insmod seconds.ko`.
4. **Verify Creation:** Ensure the `/proc/seconds` file is created with `sudo dmesg -c`.
5. **Read Elapsed Time:** Access the elapsed time since module load via `cat /proc/seconds`.
6. **Unload:** Remove the module with `sudo rmmod seconds`.
7. **Confirm Removal:** Check removal confirmation with `sudo dmesg -c`.

## Usage

To interact with these modules, follow the installation and verification steps detailed above for each. The primary commands involve loading the module (`sudo insmod [module_name].ko`), reading the file created in `/proc` (`cat /proc/[filename]`), and unloading the module (`sudo rmmod [module_name]`).

## Test Cases and Expected Output

![MicrosoftTeams-image (3)](https://github.com/VermaAdi/CS409-Projects/assets/97848600/eae810be-e6be-45ef-8c26-ec73eed0c557)
![MicrosoftTeams-image (4)](https://github.com/VermaAdi/CS409-Projects/assets/97848600/1d3d4995-4266-48d1-9979-b9736614d57f)
![MicrosoftTeams-image (5)](https://github.com/VermaAdi/CS409-Projects/assets/97848600/9603a8b0-48ed-4e35-9d7c-417e4d4bbbc4)


# TASK 2: Linux Kernel Module for Task Information

## Project Overview

This project involves the development of a Linux kernel module that enables the display of task information through the `/proc` filesystem based on a given process identifier (`PID`). The module allows users to write a `PID` to a file named `/proc/pid` and then read back the task's command name, `PID`, and current state. This document provides a comprehensive overview of the module's functionality, installation, usage instructions and test cases. The module is a collaborative effort by Aditya Verma, Liam Buck T., and Junwen Hu.

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

## Test Cases and Expected Output

![MicrosoftTeams-image](https://github.com/VermaAdi/CS409-Projects/assets/97848600/80fa4bdf-fa8b-4ccb-b287-6a6301d6ed7f)
![MicrosoftTeams-image (1)](https://github.com/VermaAdi/CS409-Projects/assets/97848600/a0df938a-5140-481b-9782-fa790f7b3068)
![MicrosoftTeams-image (2)](https://github.com/VermaAdi/CS409-Projects/assets/97848600/1d9cd473-44a3-4cbc-97d8-37908ef0cd7f)

## Contributors

- Aditya Verma
- Liam Buck T.
- Junwen Hu
