#include "common.h"
#include "draw.h"

bool running;
char input;
struct termios old_ter;
struct termios new_ter;
int frame;

void init()
{
    //manage terminal input settings
    tcgetattr(STDIN_FILENO, &old_ter); // // Save current terminal settings
    new_ter = old_ter; // Create new settings
    new_ter.c_lflag &= ~(ICANON | ECHO); // Disable terminals canonical mode + echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_ter); // Apply new settings
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // Make keyboard input non-blocking (changes file descriptor properties)

    clear_screen();
    running = true;
    draw_frame();
    frame = 1; // contador da frame
}

void shutdown()
{
    clear_screen();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_ter); // recupera definições iniciais do terminal que foram alteradas
    printf("Exit Tetris!\n");
    printf("\033[?25h"); fflush(stdout); // brings back cursor
    running = false;
}

int main (int argc, char* argv[])
{
    init();
    while(running)
    {
        draw_frame();
        printf("\033[25;0H"); // mete estes textos por debaixo de tudo
        printf("Frame: %d\n", frame);
        if (read(STDIN_FILENO, &input, 1) > 0) // lê keyboard
        {
            if (input == 'q')
            {
                shutdown();
                break;
            }
            else
            {
                switch (input)
                {
                case 'w':
                    printf("Input: %c (UP)          \n", input);  
                    posy--;
                    if (posy < 1) posy = 1;     
                    break;
                
                case 's':
                    printf("Input: %c (DOWN)        \n", input);
                    posy++;
                    if (posy > 20) posy = 20;  
                    break;

                case 'a':
                    printf("Input: %c (LEFT)        \n", input);
                    posx--;
                    if (posx < 1) posx = 1;
                    break;

                case 'd':
                    printf("Input: %c (RIGHT)        \n", input);
                    posx++;
                    if (posx > 10) posx = 10;
                    break;

                default:
                    printf("Input: %c                \n", input);
                    break;
                }
            }
        }
        tcflush(STDIN_FILENO, TCIFLUSH); // throw away pending terminal input

        usleep(50000); frame++; 
    }
}