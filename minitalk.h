#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
int		ft_fputchar(char c);
void  ft_fputnbr_deci(long n);
void	ft_fputstr(char *str);

#endif
