#include "minitalk.h"

void  handler_signal(int signal)
{
    static unsigned char  character;
    static int            bit;

    if (bit < 8)
    {
        character |= (signal == SIGUSR1);
        character <<= 1;
        bit++;
    }
    else 
    {
        ft_fputchar(character);
        bit = 0;
        character = 0;
    }
}

int main()
{
    ft_fputstr("PID: ");
    ft_fputnbr_deci(getpid());
    ft_fputchar('\n');
    signal(SIGUSR1, handler_signal);
    signal(SIGUSR2, handler_signal);
    while(1)
        pause();
    return (0);
}
