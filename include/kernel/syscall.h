/*
Copyright (C) 2017 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef KERNEL_SYSCALL_H
#define KERNEL_SYSCALL_H

#include "kernel/types.h"

typedef enum {
	SYSCALL_DEBUG,
	SYSCALL_PROCESS_YIELD,
	SYSCALL_PROCESS_EXIT,
	SYSCALL_PROCESS_RUN,
	SYSCALL_PROCESS_FORK,
	SYSCALL_PROCESS_EXEC,
	SYSCALL_PROCESS_KILL,
	SYSCALL_PROCESS_WAIT,
	SYSCALL_PROCESS_REAP,
	SYSCALL_PROCESS_SELF,
	SYSCALL_PROCESS_PARENT,
	SYSCALL_PROCESS_SLEEP,
	SYSCALL_OPEN,
	SYSCALL_DUP,
	SYSCALL_READ,
	SYSCALL_WRITE,
	SYSCALL_LSEEK,
	SYSCALL_CLOSE,
	SYSCALL_KEYBOARD_READ_CHAR,
	SYSCALL_OPEN_CONSOLE,
	SYSCALL_OPEN_PIPE,
	SYSCALL_SET_BLOCKING,
	SYSCALL_OPEN_WINDOW,
	SYSCALL_GETTIMEOFDAY,
	SYSCALL_CHDIR,
	SYSCALL_SBRK,
	SYSCALL_MKDIR,
	SYSCALL_RMDIR,
	SYSCALL_READDIR,
	SYSCALL_PWD,
	SYSCALL_SYS_STAT,
	SYSCALL_PROCESS_STAT
} syscall_t;

typedef enum {
	KERROR_NOT_FOUND = -1,
	KERROR_INVALID_REQUEST = -2,
	KERROR_PERMISSION_DENIED = -3,
	KERROR_NOT_IMPLEMENTED = -4,
	KERROR_NOT_EXECUTABLE = -5,
	KERROR_EXECUTION_FAILED = -6,
	KERROR_NOT_SUPPORTED = -7,
	KERROR_NOT_A_DIRECTORY = -8
} syscall_error_t;

uint32_t syscall(syscall_t s, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);

#endif
