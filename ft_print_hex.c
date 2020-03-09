/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:29:03 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/04 23:55:32 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_adresse(t_flags *flag)
{
	unsigned long long arg;

	flag->zero = 0;
	arg = (unsigned long long)va_arg(g_args, void *);
	ft_print_hex(*flag, -1, arg);
}

int		ft_hexa_size(unsigned long long nb)
{
	int index;

	index = 1;
	if (nb <= 15)
		return (1);
	while (nb > 15)
	{
		nb /= 16;
		index++;
	}
	return (index);
}

void	ft_put_hexa(unsigned long long arg, int index, int ox)
{
	int j;

	if (index == -1 && ox == 1)
	{
		ft_putstr_fd("0x", 1, 2);
		ox++;
	}
	j = (index == 1 || index == -1) ? 87 : 55;
	if (arg <= 15)
		(arg <= 9) ? ft_putchar_fd(arg + '0', 1) : ft_putchar_fd(arg + j, 1);
	else
	{
		ft_put_hexa(arg / 16, index, 0);
		arg = arg % 16;
		(arg <= 9) ? ft_putchar_fd(arg + '0', 1) : ft_putchar_fd(arg + j, 1);
	}
}

void	ft_hel(t_flags flag, int printed_spaces, int printed_zeros, int index)
{
	int arg_size;

	arg_size = ft_hexa_size(flag.agm);
	flag.width = (index == -1) ? flag.width -= 2 : flag.width;
	if (flag.agm == 0 && flag.prec == 0)
	{
		if (index == -1 && flag.minus != 0)
			ft_putstr_fd("0x", 1, 2);
		ft_putspaces(printed_spaces + 1);
		if (index == -1 && flag.minus == 0)
			ft_putstr_fd("0x", 1, 2);
	}
	else
	{
		ft_putzeros(printed_zeros);
		if (index == -1 && flag.agm == 0 && flag.prec == 0)
		{
			arg_size = 0;
			ft_putstr_fd("0x", 1, 2);
		}
		else
			ft_put_hexa(flag.agm, index, 1);
		ft_putspaces(flag.width - printed_zeros - arg_size);
	}
}

void	ft_print_hex(t_flags flag, int index, unsigned long long p)
{
	int	arg_size;
	int	pd_zeros;

	flag.agm = (index != -1) ? va_arg(g_args, unsigned int) : p;
	arg_size = ft_hexa_size(flag.agm);
	arg_size = (index == -1) ? arg_size += 2 : arg_size;
	pd_zeros = 0;
	if (flag.prec != -1 && flag.prec >= 0)
		pd_zeros = (flag.prec >= arg_size) ? flag.prec - arg_size : 0;
	else if (flag.zero != 0 && flag.minus == 0)
		pd_zeros = (flag.width > arg_size) ? flag.width - arg_size : 0;
	if (flag.minus != 0 || (flag.prec == 0 && flag.agm == 0))
		ft_hel(flag, flag.width - pd_zeros - arg_size, pd_zeros, index);
	else
	{
		ft_putspaces(flag.width - pd_zeros - arg_size);
		ft_putzeros(pd_zeros);
		ft_put_hexa(flag.agm, index, 1);
	}
}
