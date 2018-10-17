/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_oux_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:05:41 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/26 15:05:44 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uox_d(t_prin *p, char *s, uintmax_t n, char *str)
{
	if (n == 0 && p->precs == 0 && p->width == 1 && p->pr_o != 1 && ++p->res)
		return ;
	if (n == 0 && p->precs == 0 && str[p->t_i] != 'o' && str[p->t_i] != 'O')
		return ;
	if (n == 0 && p->fl_hash && p->precs == 0 &&
		(str[p->t_i] == 'o' || str[p->t_i] == 'O'))
	{
		p->res++;
		ft_putchar('0');
		return ;
	}
	if (n == 0 && p->precs == 0 && p->fl_hash && ++p->res)
	{
		ft_putchar('0');
		return ;
	}
	print_uox_ddt(p, s, n, str);
}

void	print_uox_ddt(t_prin *p, char *s, uintmax_t n, char *str)
{
	if (p->fl_hash && n != 0 && (str[p->t_i] == 'o' || str[p->t_i] == 'O')
		&& ++p->res)
		ft_putchar('0');
	if (p->fl_hash && n != 0 && str[p->t_i] != 'o'
		&& str[p->t_i] != 'O')
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	if (n == 0 && p->precs == 0)
		return ;
	if (n == 0 && p->precs == -42 && ++p->res)
	{
		ft_putchar('0');
		return ;
	}
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_uox_e(t_prin *p, char *s, uintmax_t n, char *str)
{
	if (p->fl_hash && n != 0 && (str[p->t_i] == 'x' || str[p->t_i] == 'X'))
	{
		p->p_wd -= 2;
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	if (p->fl_hash && n != 0 && (str[p->t_i] == 'o' || str[p->t_i] == 'O'))
	{
		p->p_wd--;
		ft_putchar('0');
		p->res++;
	}
	if (n == 0 && p->fl_hash && p->p_pr == 0 && p->precs != 1
		&& (str[p->t_i] == 'o' || str[p->t_i] == 'O'))
	{
		p->p_wd--;
		ft_putchar('0');
		p->res++;
	}
	write_oux_ff(n, s, p);
}

void	print_uox_f(t_prin *p, char *s, uintmax_t n, char *str)
{
	if (p->fl_hash && str[p->t_i] != 'o' && str[p->t_i] != 'O' && n != 0)
		p->p_wd -= 2;
	if (p->fl_hash && str[p->t_i] != 'o' && str[p->t_i] != 'O' && n != 0)
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
	if (p->p_wd > 0)
		while (p->p_wd-- && ++p->res)
			ft_putchar(' ');
}

void	print_uox_g(t_prin *p, char *s, char *str, uintmax_t n)
{
	if (p->fl_hash && str[p->t_i] != 'o' && str[p->t_i] != 'O' && n != 0)
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}
