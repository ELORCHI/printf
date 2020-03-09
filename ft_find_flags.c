/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <eel-orch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:18:48 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/03 05:20:38 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_len(long number)
{
	int len;

	len = 1;
	number = (number < 0) ? -1 * number : number;
	if (number <= 9)
		return (len);
	while (number >= 10)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

void	degit(char *frm, int *i, t_flags *flag, int wid_prec)
{
	if (wid_prec)
	{
		flag->width = ft_atoi(frm + *i);
		*i += ft_nb_len(flag->width);
	}
	else
	{
		flag->prec = ft_atoi(frm + *i);
		*i += ft_nb_len(flag->prec);
		while (ft_isdigit(frm[*i]))
			(*i)++;
	}
}

void	asterisk_digit(char *frm, int *i, t_flags *flag, int wid_prec)
{
	if (!wid_prec)
		(*i)++;
	if (ft_isdigit(frm[*i]))
		degit(frm, i, flag, wid_prec);
	else if (frm[(*i)] == '*')
	{
		if (wid_prec)
			flag->width = va_arg(g_args, int);
		else
			flag->prec = va_arg(g_args, int);
		(*i)++;
	}
	else if (wid_prec == 0)
		flag->prec = 0;
}

void	help(char *frm, int *i, t_flags *flag)
{
	if (flag->width < 0)
	{
		flag->width *= -1;
		flag->minus = 1;
	}
	if (frm[(*i)] == '.')
		asterisk_digit(frm, i, flag, 0);
}

void	ft_find_flags(char *frm, int *i, t_flags *flag)
{
	int j;

	j = -1;
	while (frm[*i] == '0' || frm[*i] == ' ' || frm[*i] == '-')
	{
		while (frm[*i] == '-')
		{
			flag->minus = 1;
			(*i)++;
		}
		while (frm[*i] == ' ')
		{
			if (j++ == -1)
				ft_putchar_fd(' ', 1);
			(*i)++;
		}
		while (frm[*i] == '0')
		{
			flag->zero = 1;
			(*i)++;
		}
	}
	asterisk_digit(frm, i, flag, 1);
	help(frm, i, flag);
}
