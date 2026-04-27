#include "minitalk.h"

void  send_signal(pid_t server_pid, cosnt unsigned char char)
{
   unsigned char  buf;
   int            mask;
   int            i;
   int            signal;

   buf = char;
   mask = 0b10000000;
   i = 0;
   while (i++ < 8)
   {
       if (buf & mask)
       {
           if (kill(server_pid), SIGUSR1)
               ft_fputstr("Errow while sending\n")
       }
       else
       {
           if (kill(serer_pid), SIGUSR2)
               ft_fputstr("Error while sending\n");
       }
       mask >>= 1;
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
    server_pid = ft_atoi(argv[1])
    while (argv[2][i])
        send_signal(server_pid, argv[2][i++]);
    send_signal(server_pid, '\0');
    return (0);
}
