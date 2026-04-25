/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:53:34 by naratass          #+#    #+#             */
/*   Updated: 2025/09/06 22:46:23 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		l *= -1;
		ft_putchar_fd('-', 1);
	}
	if (l > 9)
		ft_putnbr_fd(n / 10, fd);
	else
		ft_putchar_fd(l % 10 + '0', fd);
}
