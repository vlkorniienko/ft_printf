/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:07:20 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/24 16:07:23 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_wd_oux(char *s, t_prin *p)
{
	if (p->width)
	{
		p->p_wd = p->width - ft_strlen(s) - p->p_pr - p->fl_plus -
		p->fl_space;
		if (p->p_wd < 0)
			p->p_wd = 0;
	}
}

void	print_uox(t_prin *p, char *str, uintmax_t n, char *s)
{
	if (p->fl_hash && n != 0 && (str[p->t_i] == 'o' || str[p->t_i] == 'O'))
		p->p_wd--;
	if (n == 0 && p->precs == 0 && !p->fl_hash)
	{
		p->res += p->p_wd + 1;
		if (p->width)
			while (p->width--)
				ft_putchar(' ');
		return ;
	}
	if (p->fl_hash && n != 0 && str[p->t_i] != 'o' && str[p->t_i] != 'O')
		p->p_wd -= 2;
	if (p->fl_hash && n != 0 && p->fl_zero && str[p->t_i] != 'o'
		&& str[p->t_i] != 'O')
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	if (p->p_wd > 0)
		while (p->p_wd-- && ++p->res)
			(p->fl_zero && p->precs == -42) ? ft_putchar('0') : ft_putchar(' ');
	if (n == 0 && p->fl_hash && p->precs == 0
		&& str[p->t_i] != 'o' && str[p->t_i] != 'O' && ++p->res)
		return ;
	print_uox_a(p, str, n, s);
}

void	print_uox_a(t_prin *p, char *str, uintmax_t n, char *s)
{
	if (n == 0 && p->fl_zero && p->precs == 0 && ++p->res)
		return ;
	if (p->fl_hash && n != 0 && (str[p->t_i] == 'o' || str[p->t_i] == 'O'))
	{
		ft_putchar('0');
		p->res++;
	}
	if (p->fl_hash && n != 0 && !(p->fl_zero)
		&& str[p->t_i] != 'o' && str[p->t_i] != 'O')
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_uox_b(t_prin *p, char *str, uintmax_t n, char *s)
{
	if (p->fl_hash && n != 0 && str[p->t_i] != 'o' && str[p->t_i] != 'O')
		p->p_wd -= 2;
	if (p->p_wd > 0)
		while (p->p_wd-- && ++p->res)
			(p->fl_zero && p->precs == -42) ? ft_putchar('0') : ft_putchar(' ');
	if (p->fl_hash && n != 0 && str[p->t_i] != 'o' && str[p->t_i] != 'O')
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_uox_c(t_prin *p, char *str, uintmax_t n, char *s)
{
	if (p->fl_hash && n != 0 && str[p->t_i] != 'o' && str[p->t_i] != 'O')
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}
