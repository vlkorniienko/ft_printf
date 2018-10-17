/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:22:31 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/29 16:22:34 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_oux_final(t_prin *p, uintmax_t n, char *str, char *s)
{
	if (p->fl_hash && n != 0 && str[p->t_i] != 'o' && str[p->t_i] != 'O')
	{
		(p->temp_z == 42) ? ft_putstr("0x") : ft_putstr("0X");
		p->res += 2;
	}
	if (p->fl_hash && p->p_pr != 0 &&
		(str[p->t_i] == 'o' || str[p->t_i] != 'O'))
	{
		ft_putchar('0');
		p->p_wd--;
	}
	if (p->fl_hash && n == 0 && p->precs != 1 &&
		(str[p->t_i] == 'o' || str[p->t_i] != 'O'))
	{
		ft_putchar('0');
		p->p_wd--;
	}
	if (n == 0 && p->precs == 0 && ++p->res)
		return ;
	ft_putstr(s);
	p->res += FS;
}

void	write_oux_ff(uintmax_t n, char *s, t_prin *p)
{
	if (n != 0)
		ft_putstr(s);
	if (n == 0 && (p->precs > 0 || p->precs == -42))
		ft_putstr(s);
	p->res += FS;
	if (p->p_wd > 0)
		while (p->p_wd-- && ++p->res)
			ft_putchar(' ');
}

void	put_char_c(t_prin *p, char c)
{
	if (p->fl_minus)
	{
		ft_putchar(c);
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
		ft_putchar(c);
		p->res++;
	}
}

void	write_string(t_prin *p, char *s, char *str, uintmax_t i)
{
	if (s == NULL)
		s = "(null)";
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

void	write_s_a(t_prin *p, char *s)
{
	if (p->precs == -42)
	{
		ft_putstr(s);
		p->res += FS;
		while (p->p_wd-- && ++p->res)
			ft_putchar(' ');
	}
	else
	{
		while (((p->itr) < p->precs) && (p->itr < FS) && ++p->res)
			ft_putchar(s[p->itr++]);
		while (p->p_wd-- && ++p->res)
			ft_putchar(' ');
	}
}
