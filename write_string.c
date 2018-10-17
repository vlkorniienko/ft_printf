/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:25:14 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/31 15:25:16 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_w_fors(t_prin *p, char *s)
{
	if (p->width)
	{
		if (p->precs != -42)
		{
			if ((int)(p->precs - ft_strlen(s)) < 0)
				p->p_wd = (p->width - p->precs);
			else
				p->p_wd = p->width - ft_strlen(s);
		}
		else
			p->p_wd = p->width - ft_strlen(s);
	}
	if (p->p_wd < 0)
		p->p_wd = 0;
}

void	write_s_b(t_prin *p, char *s)
{
	if (p->precs == -42)
	{
		ft_putstr(s);
		p->res += FS;
	}
	else
	{
		while (((p->itr) < p->precs) && (p->itr < FS) && ++p->res)
			ft_putchar(s[p->itr++]);
	}
}

void	write_s_c(t_prin *p, char *s)
{
	if (p->p_wd)
	{
		if (p->precs == -42)
		{
			while (p->p_wd-- && ++p->res)
				(!p->fl_zero) ? ft_putchar(' ') : ft_putchar('0');
			ft_putstr(s);
			p->res += FS;
		}
		else
		{
			while (p->p_wd-- && ++p->res)
				(!p->fl_zero) ? ft_putchar(' ') : ft_putchar('0');
			while ((p->itr) < p->precs && (p->itr < FS) && ++p->res)
				ft_putchar(s[p->itr++]);
		}
	}
	else
		write_s_b(p, s);
}

void	write_zero_s(t_prin *p, wchar_t *ss)
{
	char *s;

	s = "(null)";
	free(ss);
	find_w_fors(p, s);
	if (p->fl_minus)
	{
		if (!p->p_wd)
		{
			if (p->precs == -42)
			{
				ft_putstr(s);
				p->res += FS;
			}
			else
			{
				while (((p->itr) < p->precs) && (p->itr < FS) && ++p->res)
					ft_putchar(s[p->itr++]);
			}
		}
		else
			write_s_a(p, s);
	}
	else
		write_s_c(p, s);
}

void	write_big_s(wchar_t *ss, t_prin *p)
{
	int res;

	res = 0;
	wd_for_bigs(p, ss);
	if (!p->fl_minus)
		print_sbig_aa(p, ss, res);
	else
		print_sbig_ab(p, ss, res);
}
