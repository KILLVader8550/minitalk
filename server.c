#include "minitalk.h"
#include <stdio.h>

void  handler_signal(int signal)
{
    static unsigned char  character = 0;
    static int            bit = 0;

    bit++;
    character |= (signal == SIGUSR1);
    if (bit == 8)
    {
        if (character == '\0')
            ft_fputchar('\n');
        else
            ft_fputchar(character);
        bit = 0;
        character = 0;
    }
    else
        character <<= 1;
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
