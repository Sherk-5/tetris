#include "terminal.h"

#include <unistd.h> // funções POSIX relacionadas ao SO: write(); STDOUT_FILENO; ssize_t?
#include <termios.h> // API POSIX para configurar atributos e comportamentos do terminal
#include <sys/ioctl.h>
//#include <signal.h> // permite lidar com Cntrl+C / SIGINT 




/* struct termios:
    - input settings
    - output settings
    - controll settings
    - local settings
*/
static struct termios og_terminal; // "struct termios" gerida só por terminal.c

void terminal_init(void)
{
    /* gurda estado/configurações originais do terminal em "og_terminal" */
    tcgetattr(STDIN_FILENO, &og_terminal);
}

void terminal_enable_raw_mode(void)
{
    struct termios raw_terminal = og_terminal; // novo estado de terminal (raw mode)

    /* c_lflag: 
        - ICANON -> modo de input canónico (terminal trabalha por linhas -> programa recebe depois de um enter)
        - ECHO -> terminal faz echo/mostra o que o user escreve
    */
    raw_terminal.c_lflag &= ~(ECHO | ICANON); // operação bitwise com AND, OR e inversão de bits -> anula ICANON e ECHO
    /* c_cc
        - VMIN -> indica se é necessário esperar por um charecter do teclado para dar input (congela o terminal)
        - VTIME -> temporizador para o bloqueio 
    */
    raw_terminal.c_cc[VMIN] = 0;
    raw_terminal.c_cc[VTIME] = 0;
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_terminal); // atualização terminal para raw mode
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

int terminal_get_size(int *width, int *height)
{
    struct winsize size; // estrutura do linux -> representar o tamanho do terminal (.ws_col e .ws_row)

    // TIOCGWINSZ ->operação que obtem
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == -1)
    {
        return -1;
    }

    *width = size.ws_col;
    *heigth = size.WS_row;

    return 0;
}

