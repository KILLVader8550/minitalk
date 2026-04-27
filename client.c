#include "minitalk.h"
#include <stdio.h>

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
       if (buf & mask)
       {
           printf("1 ");
           if (kill(server_pid, SIGUSR1) == -1)
               ft_fputstr("Errow while sending\n");
       }
       else
       {
           printf("0 ");
           if (kill(server_pid, SIGUSR2) == -1)
               ft_fputstr("Error while sending\n");
       }
       mask >>= 1;
       usleep(42);
   }
   printf("\n");
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
    while (argv[2][i])
        send_signal(server_pid, argv[2][i++]);
    send_signal(server_pid, '\0');
    return (0);
}
