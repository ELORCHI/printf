/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ulils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:16:30 by eel-orch          #+#    #+#             */
/*   Updated: 2020/02/28 01:32:34 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putzeros(int nb_zeros)
{
	while (nb_zeros > 0)
	{
		ft_putchar_fd(48, 1);
		nb_zeros--;
	}
}

void	ft_putspaces(int nb_spaces)
{
	while (nb_spaces > 0)
	{
		ft_putchar_fd(32, 1);
		nb_spaces--;
	}
}

int		retur(unsigned long j, int sin)
{
	if (j > 2147483647 && sin == 1)
		return (-1);
	if (j > 2147483648 && sin == -1)
		return (0);
	return (j * sin);
}

int		ft_atoi(const char *str)
{
	int				i;
	int				sin;
	unsigned long	j;

	i = 0;
	j = 0;
	sin = 1;
	while ((str[i] != '\0' && (str[i] >= 9 && str[i] <= 13)) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (retur(j, sin));
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
