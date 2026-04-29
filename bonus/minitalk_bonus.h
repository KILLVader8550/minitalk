#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define  SENDING_ERROR "signal error!\n" 

int		ft_atoi(const char *nptr);
int		ft_fputchar(char c, int fd);
void	ft_fputnbr_deci(long n);
void	ft_fputstr(char *str, int fd);
void	error_exit(char *s);

#endif
