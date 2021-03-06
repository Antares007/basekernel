/*
Copyright (C) 2015-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#include "ata.h"
#include "cdromfs.h"
#include "clock.h"
#include "console.h"
#include "device.h"
#include "diskfs.h"
#include "graphics.h"
#include "interrupt.h"
#include "kernel/ascii.h"
#include "kernel/syscall.h"
#include "kernelcore.h"
#include "keyboard.h"
#include "kmalloc.h"
#include "kshell.h"
#include "memorylayout.h"
#include "mouse.h"
#include "page.h"
#include "process.h"
#include "rtc.h"
#include "serial.h"
#include "string.h"

/*
This is the C initialization point of the kernel.
By the time we reach this point, we are in protected mode,
with interrupts disabled, a valid C stack, but no malloc heap.
Now we initialize each subsystem in the proper order:
*/

int kernel_main() {
  struct graphics *g = graphics_create_root();

  console_init(g);
  console_addref(&console_root);

  printf("video: %d x %d\n", video_xres, video_yres, video_xbytes);
  printf("kernel: %d bytes\n", kernel_size);

  page_init();
  kmalloc_init((char *)KMALLOC_START, KMALLOC_LENGTH);
  interrupt_init();
  rtc_init();
  clock_init();
  mouse_init();
  keyboard_init();
  process_init();
  ata_init();
  cdrom_init();
  diskfs_init();

  printf("\nKERNEL SHELL READY:\n");
  kshell_launch();

  while (1) {
    console_putchar(&console_root, keyboard_read(0));
  }

  return 0;
}
