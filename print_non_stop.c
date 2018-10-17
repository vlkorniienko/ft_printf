/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non_stop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:30:47 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/23 11:30:49 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_flminus(char *s, t_prin *p)
{
	if (p->fl_zero && p->precs != 0 && ++p->res)
	{
		ft_putchar('-');
		p->fl_zero = 2;
	}
	if (p->fl_plus)
		p->p_wd++;
	if (p->fl_space && !(p->fl_zero) && ++p->res)
		ft_putchar(' ');
	while (p->p_wd-- && ++p->res)
		(p->fl_zero && p->precs != 0) ? ft_putchar('0') : ft_putchar(' ');
	if (p->fl_zero != 2 && ++p->res)
		ft_putchar('-');
	if ((p->fl_zero) && (p->fl_space) && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_w_flmin(char *s, t_prin *p)
{
	ft_putchar('-');
	p->res++;
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
}

void	print_pr_nm(char *s, t_prin *p)
{
	if (p->fl_space || p->fl_plus)
		p->p_wd++;
	ft_putchar('-');
	p->res++;
	ft_putstr(s);
	p->res += ft_strlen(s);
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
}

void	print_posit_wd(char *s, t_prin *p, intmax_t n)
{
	if (!p->p_pr)
	{
		if (!(p->fl_minus))
			printwd_no_minus(s, p, n);
		else
			printwd_w_minus(s, p);
	}
	else
	{
		if (!(p->fl_minus))
			print_wdt(s, p);
		else
			print_d_i(s, p);
	}
}

void	print_negat_w(char *s, t_prin *p)
{
	if (p->p_pr)
	{
		if (!(p->fl_minus))
			print_pr_m(s, p);
		else
			print_w_flmin(s, p);
	}
	else
	{
		if (!(p->fl_minus))
			print_no_flminus(s, p);
		else
			print_pr_nm(s, p);
	}
}
