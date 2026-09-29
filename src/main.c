#include "terminal.h"

#include <unistd.h>

int main(void)
{
    terminal_init();
    terminal_enable_raw_mode();

    terminal_clear();
    terminal_hide_cursor();

    sleep(5);

    terminal_show_cursor();
    terminal_cleanup();

    return 0;
}