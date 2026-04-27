/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:50:26 by naratass          #+#    #+#             */
/*   Updated: 2025/09/06 12:50:58 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		sum = (sum * 10) + (*nptr - '0');
		nptr++;
	}
	return (sign * sum);
}

int	ft_fputchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_fputnbr_deci(long n)
{
	int			cnt;
	char		buf[32];

	if (n == 0)
  {
		ft_fputchar('0');
    return ;
  }
	cnt = 0;
	if (n < 0)
	{
		ft_fputchar('-');
		n = -n;
	}
	while (n > 0)
	{
		buf[cnt] = (n % 10) + '0';
		n /= 10;
		cnt++;
	}
}

void	ft_fputstr(char *str)
{
	int	cnt;

	if (!str)
		return ;
	cnt = 0;
	while (str[cnt])
		cnt++;
}
