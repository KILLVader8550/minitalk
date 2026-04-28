#include "minitalk.h"
#include <stdio.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	const unsigned char	chr = c;
	unsigned char		*p;

	p = s;
	while (n-- > 0)
		*p++ = chr;
	return (s);
}

void  handler_signal(int signal, siginfo_t *info, void *context)
{
    static unsigned char  character = 0;
    static int            bit = 0;

    (void)context;
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
    if (kill(info->si_pid, signal) == -1)
        ft_fputstr("Can't acknowledge\n");
}

int main()
{
    struct sigaction sa;

    ft_memset(&sa, 0, sizeof(sa));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = &handler_signal;
    sa.sa_flags = SA_SIGINFO;
    ft_fputstr("PID: ");
    ft_fputnbr_deci(getpid());
    ft_fputchar('\n');
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
        pause();
    return (0);
}
