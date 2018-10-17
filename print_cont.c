/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:51:00 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/23 10:51:02 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printwd_no_minus(char *s, t_prin *p, intmax_t n)
{
	if (n == 0 && p->precs == 0 && !p->p_wd)
	{
		p->res += 2;
		return ;
	}
	if (n == 0 && p->precs == -42 && p->width >= 3
		&& p->fl_zero && (p->fl_plus || p->fl_space))
		p->p_wd++;
	if (p->fl_space-- && ++p->res)
		ft_putchar(' ');
	if (p->fl_zero && p->fl_plus && ++p->res)
		ft_putchar('+');
	if (n == 0 && p->precs == 0 && p->p_wd)
		p->p_wd++;
	while (p->p_wd-- && ++p->res)
		(p->fl_zero && p->precs != 0 && (p->p_pr > 0 || p->precs == -42))
		? ft_putchar('0') : ft_putchar(' ');
	if (p->fl_plus && !(p->fl_zero))
		if (p->fl_plus && ++p->res)
			ft_putchar('+');
	if (n != 0 && p->precs != 0)
		ft_putstr(s);
	if (n != 0 && p->precs != 0 && p->p_wd)
		p->res += ft_strlen(s);
}

void	printwd_w_minus(char *s, t_prin *p)
{
	if (p->fl_plus && ++p->res)
		ft_putchar('+');
	if (p->fl_space && ++p->res)
		ft_putchar(' ');
	ft_putstr(s);
	p->res += ft_strlen(s);
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
}

void	print_wdt(char *s, t_prin *p)
{
	if (p->fl_space-- && ++p->res)
		ft_putchar(' ');
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
	if (p->fl_plus && ++p->res)
		ft_putchar('+');
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_d_i(char *s, t_prin *p)
{
	if (p->fl_plus && ++p->res)
		ft_putchar('+');
	if (p->fl_space && ++p->res)
		ft_putchar(' ');
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
}

void	print_pr_m(char *s, t_prin *p)
{
	p->p_wd++;
	if (!(p->fl_plus) || !(p->fl_space))
		p->p_wd--;
	if (p->fl_space && ++p->res)
		ft_putchar(' ');
	if ((p->fl_zero) && (p->fl_plus))
		p->p_wd++;
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
	ft_putchar('-');
	p->res++;
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}
