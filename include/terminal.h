#ifndef TERMINAL_H
#define TERMINAL_H

void terminal_init(void);
void terminal_enable_raw_mode(void);
void terminal_cleanup(void);

void terminal_clear(void);
void terminal_hide_cursor(void);
void terminal_show_cursor(void);

int terminal_get_size(int *width, int *height);

#endif