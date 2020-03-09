/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 20:00:23 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/05 00:33:45 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_flags flag)
{
	flag.arg = va_arg(g_args, int);
	if (flag.minus != 0)
	{
		(flag.width)--;
		ft_putchar_fd(flag.arg, 1);
		ft_putspaces(flag.width);
	}
	else
	{
		(flag.width)--;
		ft_putspaces(flag.width);
		ft_putchar_fd(flag.arg, 1);
	}
}

void	ft_print_string(t_flags *flag)
{
	char	*str;

	str = va_arg(g_args, char *);
	str = (str == NULL) ? "(null)" : str;
	if (flag->prec == 0)
		ft_putspaces(flag->width);
	else
	{
		(flag->prec > ft_strlen(str)) ? flag->prec = ft_strlen(str) : 0;
		(flag->prec < 0) ? flag->prec = ft_strlen(str) : 0;
		flag->width -= flag->prec;
		if (flag->minus != 0)
		{
			ft_putstr_fd(str, 1, flag->prec);
			ft_putspaces(flag->width);
		}
		else
		{
			ft_putspaces(flag->width);
			ft_putstr_fd(str, 1, flag->prec);
		}
	}
}
