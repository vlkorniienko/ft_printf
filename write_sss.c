/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:24:31 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/02 11:24:33 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wd_for_bigs(t_prin *p, wchar_t *ss)
{
	if (p->width)
	{
		if (p->precs != -42)
		{
			if ((int)(p->precs - p->sitr) < 0)
				p->p_wd = (p->width - p->precs);
			else
				p->p_wd = p->width - p->sitr;
		}
		else
			p->p_wd = p->width - p->sitr;
	}
	if (p->p_wd < 0)
		p->p_wd = 0;
}

void	check_next(wchar_t c, t_prin *p)
{
	unsigned int size;

	size = size_binary(c);
	p->check = 0;
	if (size <= 7)
		p->check++;
	else if (size <= 11)
		p->check += 2;
	else if (size <= 16)
		p->check += 3;
	else
		p->check += 4;
}

void	print_s_biig(t_prin *p, wchar_t *ss)
{
	if (p->precs >= p->sitr)
	{
		while (ss[p->itr])
		{
			c_big_begin(ss[p->itr], p);
			p->itr++;
		}
	}
	else
	{
		while (p->res <= p->precs && ss[p->itr])
		{
			check_next(ss[p->itr], p);
			if ((p->res + p->check) > p->precs)
				break ;
			c_big_begin(ss[p->itr], p);
			p->itr++;
		}
	}
}

void	print_s_biga(wchar_t *ss, t_prin *p)
{
	while (ss[p->itr])
	{
		c_big_begin(ss[p->itr], p);
		p->itr++;
	}
}

void	print_s_bigb(t_prin *p, wchar_t *ss, int res)
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
	while (p->p_wd-- && ++p->res)
		(!p->fl_zero) ? ft_putchar(' ') : ft_putchar('0');
	while (res <= p->precs && ss[p->itr])
	{
		check_next(ss[p->itr], p);
		if ((res + p->check) > p->precs)
			break ;
		res += p->check;
		c_big_begin(ss[p->itr], p);
		p->itr++;
	}
}
