/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:08:56 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/03 05:21:45 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flag)
{
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
	flag->minus = 0;
	flag->arg = 0;
}

void	ft_find_conversion(char *frm, int *i, t_flags *flag)
{
	if (frm[*i] == 'd' || frm[*i] == 'i')
		ft_print_decimal(flag, 0);
	else if (frm[*i] == 'u')
		ft_print_unsigned(flag);
	else if (frm[*i] == 'c')
		ft_print_char(*flag);
	else if (frm[*i] == 's')
		ft_print_string(flag);
	else if (frm[*i] == 'x')
		ft_print_hex(*flag, 1, 0);
	else if (frm[*i] == 'X')
		ft_print_hex(*flag, 0, 0);
	else if (frm[*i] == 'p')
		ft_print_adresse(flag);
	else if (frm[*i] == '%')
		ft_double_percent(*flag);
	if (frm[*i] != '\0')
		(*i)++;
}

int		ft_printf(const char *frm, ...)
{
	int		i;
	t_flags	flag;

	g_printed_char = 0;
	i = 0;
	va_start(g_args, frm);
	while (frm[i] != '\0')
	{
		if (frm[i] == '%')
		{
			if (frm[i++ + 1] == '%')
				ft_putchar_fd(frm[i++], 1);
			else
			{
				ft_init_flags(&flag);
				ft_find_flags((char *)frm, &i, &flag);
				ft_find_conversion((char *)frm, &i, &flag);
			}
		}
		else
			ft_putchar_fd(frm[i++], 1);
	}
	va_end(g_args);
	return (g_printed_char);
}
