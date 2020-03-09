/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:42:42 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/03 01:16:02 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	g_printed_char++;
}

void	ft_putnbr_fd(long agm, int printed_zeros, int index)
{
	int		help;

	if (agm < 0)
	{
		ft_putchar_fd('-', 1);
		agm *= -1;
	}
	if ((index == 1 || index == 0) && printed_zeros)
		ft_putzeros(printed_zeros);
	(agm <= 9) ? ft_putchar_fd(agm + 48, 1) : 0;
	if (agm > 9)
	{
		help = (int)(agm % 10);
		ft_putnbr_fd(agm / 10, 0, -1);
		ft_putchar_fd(help + 48, 1);
	}
}

void	ft_putstr_fd(char *s, int fd, int i)
{
	while (*s && i--)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
