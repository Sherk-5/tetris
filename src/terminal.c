#include "terminal.h"

#include <unistd.h> // funções POSIX relacionadas ao SO: write(); STDOUT_FILENO; ssize_t?
#include <termios.h> // API POSIX para configurar atributos e comportamentos do terminal





static struct termios og_terminal; // "struct termios" gerida só por terminal.c

void terminal_init(void)
{
    /* gurda estado/configurações originais do terminal em "og_terminal" */
    tcgetattr(STDIN_FILENO, &og_terminal);
}

void terminal_cleanup(void)
{
    /* restaura configuração original do terminal
        TCSAFLUSH -> determina quando a alteração é aplicada + como lidar com input pendete
    */
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &og_terminal);
}



void terminal_clear(void)
{
    /*
    1º Limpa o ecra
    2º cursor no inicio -> (0,0)
    */
    write(STDOUT_FILENO, "\033[2J\033[H", 7);
}

void terminal_hide_cursor(void)
{
    /* esconde o cursor */
    write(STDOUT_FILENO, "\033[?25l", 6);
}

void terminal_show_cursor(void)
{
    /*mostra o cursor*/
    write(STDOUT_FILENO, "\033[?25h", 6);
}

