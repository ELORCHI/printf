/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:55:18 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/03 01:01:28 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(t_flags *flag)
{
	flag->arg = va_arg(g_args, unsigned int);
	ft_print_decimal(flag, 1);
}

void	ft_help2(t_flags *flag, int printed_spaces, int printed_zeros)
{
	if (flag->prec == 0 && flag->arg == 0)
		ft_putspaces(printed_spaces + 1);
	else if (flag->minus > 0)
	{
		ft_putnbr_fd((long)flag->arg, printed_zeros, 1);
		ft_putspaces(printed_spaces);
	}
	else
	{
		ft_putspaces(printed_spaces);
		ft_putnbr_fd((long)flag->arg, printed_zeros, 1);
	}
}

void	ft_help(t_flags *flag, int printed_spaces, int printed_zeros, int index)
{
	if (flag->arg < 0)
		printed_spaces--;
	if (index == 1)
		ft_help2(flag, printed_spaces, printed_zeros);
	else if (index == 0)
	{
		if (flag->arg < 0)
			printed_zeros--;
		if (flag->minus > 0)
		{
			ft_putnbr_fd((long)flag->arg, 0, index);
			ft_putspaces(printed_spaces);
		}
		else
		{
			ft_putspaces(printed_spaces);
			ft_putnbr_fd((long)flag->arg, printed_zeros, index);
		}
	}
}

void	ft_print_decimal(t_flags *flag, int sign)
{
	int printed_zeros;
	int	printed_spaces;
	int index;

	printed_spaces = 0;
	printed_zeros = 0;
	index = -1;
	flag->arg = (sign == 0) ? (long)va_arg(g_args, int) : flag->arg;
	if (flag->prec >= 0)
	{
		if (flag->prec - ft_nb_len(flag->arg) > 0)
			printed_zeros = flag->prec - ft_nb_len(flag->arg);
		printed_spaces = flag->width - printed_zeros - ft_nb_len(flag->arg);
		index = 1;
	}
	else if (flag->width > 0)
	{
		if (flag->minus == 0 && flag->zero != 0)
			printed_zeros = flag->width - ft_nb_len(flag->arg);
		else
			printed_spaces = flag->width - ft_nb_len(flag->arg);
		index = 0;
	}
	ft_help(flag, printed_spaces, printed_zeros, index);
	(index == -1) ? ft_putnbr_fd(flag->arg, 0, -1) : 0;
}
