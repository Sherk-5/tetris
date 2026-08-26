#ifndef COMMON_H
#define COMMON_H

#include <stdio.h> // Standard input/output: printf, fflush
#include <unistd.h> // POSIX/Unix system calls: write, read, sleep, usleep, STDIN_FILENO
#include <stdlib.h> // General utilities: system,
#include <string.h> // manage strings: strlen
#include <stdbool.h> // bools
#include <termios.h> // mange terminal settings: tcgetattr, tcsetattr, tcflush, TCSANOW, TCIFLUSH, ICANON, ECHO
#include <fcntl.h> // File control / file opening: F_SETFL, O_NONBLOCK

#endif