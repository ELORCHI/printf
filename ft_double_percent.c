/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:51:16 by eel-orch          #+#    #+#             */
/*   Updated: 2020/02/28 21:03:37 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_double_percent(t_flags flag)
{
	int printed_spaces;
	int printed_zeros;

	printed_spaces = flag.width - 1;
	printed_zeros = flag.width - 1;
	if (flag.minus > 0)
	{
		ft_putchar_fd('%', 1);
		ft_putspaces(printed_spaces);
	}
	else
	{
		if (flag.zero > 0)
			ft_putzeros(printed_zeros);
		else
			ft_putspaces(printed_spaces);
		ft_putchar_fd('%', 1);
	}
}
