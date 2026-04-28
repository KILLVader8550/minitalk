#include "minitalk.h"
#include <stdio.h>
#include <signal.h>

int g_status = 0;

static void ack(int signal)
{
    if (signal == SIGUSR2)
        ft_fputstr("SEND SIGUSR2: SUCCESS\n");
    else
        ft_fputstr("SEND SIGUSR1: SUCCESS\n");
    g_status = 1;
}

void  send_signal(pid_t server_pid, const unsigned char character)
{
   unsigned char  buf;
   int            mask;
   int            i;

   buf = character;
   mask = 0b10000000;
   i = 0;
   while (i++ < 8)
   {
       g_status = 0;

       if (buf & mask)
       {
           if (kill(server_pid, SIGUSR1) == -1)
               ft_fputstr("Errow while sending\n");
       }
       else
       {
           if (kill(server_pid, SIGUSR2) == -1)
               ft_fputstr("Error while sending\n");
       }
       mask >>= 1;
       while (g_status != 1)
           pause();
   }
}

int main(int argc, char **argv)
{
    int server_pid;
    int i;

    if (argc != 3)
    {
        ft_fputstr("Format: ./client <server_pid> <text>");
        exit(0);
    }
    i = 0;
    server_pid = ft_atoi(argv[1]);
    signal(SIGUSR1, ack);
    signal(SIGUSR2, ack);
    while (argv[2][i])
        send_signal(server_pid, argv[2][i++]);
    send_signal(server_pid, '\0');
    return (0);
}
