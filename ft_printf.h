/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:13:16 by eel-orch          #+#    #+#             */
/*   Updated: 2020/03/04 21:31:54 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int					zero;
	int					width;
	int					prec;
	int					minus;
	long long			arg;
	unsigned long long	agm;
}				t_flags;

int				g_printed_char;
va_list			g_args;

int				ft_printf(const char *frm, ...);
void			ft_print_string(t_flags *flag);
void			ft_print_hex(t_flags flag, int index, unsigned long long p);
void			ft_print_adresse(t_flags *flag);
void			ft_print_decimal(t_flags *flag, int sign);
void			ft_print_unsigned(t_flags *flag);
void			ft_print_char(t_flags flag);
void			ft_double_percent(t_flags flag);
void			ft_putchar(char c, int fd);
void			ft_find_flags(char *frm, int *i, t_flags *flag);
void			ft_putnbr(t_flags *flag, int printed_zeros);
void			ft_putnbr_fd(long agm, int printed_zeros, int index);
int				ft_nb_len(long number);
void			ft_putchar_fd(char c, int fd);
void			ft_putzeros(int nb_zeros);
void			ft_putspaces(int nb_spaecs);
void			ft_putstr_fd(char *s, int fd, int i);
int				ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				retur(unsigned long j, int sin);

#endif
