/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sbigc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:28:07 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/02 17:28:09 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bigs_c(t_prin *p, wchar_t *ss, int res)
{
	while (p->res <= p->precs && ss[p->itr])
	{
		check_next(ss[p->itr], p);
		if ((p->res + p->check) > p->precs)
			break ;
		p->res += p->check;
		p->itr++;
	}
	p->p_wd = p->width - p->res;
	p->res = 0;
	p->itr = 0;
	while (res <= p->precs && ss[p->itr])
	{
		check_next(ss[p->itr], p);
		if ((res + p->check) > p->precs)
			break ;
		res += p->check;
		c_big_begin(ss[p->itr], p);
		p->itr++;
	}
	while (p->p_wd-- && ++p->res)
		ft_putchar(' ');
}

void	print_sbig_aa(t_prin *p, wchar_t *ss, int res)
{
	if (!p->p_wd)
	{
		if (p->precs == -42)
			print_s_biga(ss, p);
		else
			print_s_biig(p, ss);
	}
	else
	{
		if (p->precs == -42)
		{
			while (p->p_wd-- && ++p->res)
				(!p->fl_zero) ? ft_putchar(' ') : ft_putchar('0');
			print_s_biga(ss, p);
		}
		else
			print_s_bigb(p, ss, res);
	}
}

void	print_sbig_ab(t_prin *p, wchar_t *ss, int res)
{
	if (!p->p_wd)
	{
		if (p->precs == -42)
			print_s_biga(ss, p);
		else
			print_s_biig(p, ss);
	}
	else
	{
		if (p->precs == -42)
		{
			print_s_biga(ss, p);
			while (p->p_wd-- && ++p->res)
				ft_putchar(' ');
		}
		else
			print_bigs_c(p, ss, res);
	}
}

void	put_char_cc(t_prin *p, char c)
{
	if (p->fl_minus)
	{
		ft_putchar('%');
		if (p->width >= 1)
			p->width--;
		p->res++;
		while (p->width-- && ++p->res)
			ft_putchar(' ');
	}
	else
	{
		if (p->width >= 1)
			p->width--;
		while (p->width-- && ++p->res)
			(!p->fl_zero) ? ft_putchar(' ') : ft_putchar('0');
		ft_putchar('%');
		p->res++;
	}
}

void	print_uox_fin(t_prin *p, char *s, uintmax_t n, char *str)
{
	if (p->p_wd)
	{
		if (!(p->p_pr))
			print_uox_e(p, s, n, str);
		else
			print_uox_f(p, s, n, str);
	}
	else
	{
		if (p->p_pr)
			print_uox_g(p, s, str, n);
		else
			write_oux_final(p, n, str, s);
	}
}
