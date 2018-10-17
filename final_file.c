/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:17:35 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/05 14:17:37 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_p_w_forp(t_prin *p, char *s)
{
	if (p->precs != -42)
		p->p_pr = p->precs - ft_strlen(s);
	if (p->width)
		p->p_wd = p->width - FS - 2;
	if (p->precs > (int)ft_strlen(s))
		p->p_wd = p->p_wd - (p->precs - FS);
	if (p->p_wd < 0)
		p->p_wd = 0;
}

void	write_point_b(char *s, t_prin *p)
{
	if (!p->p_wd)
	{
		ft_putstr("0x");
		if (p->p_pr > 0)
			while (p->p_pr-- && ++p->res)
				ft_putchar('0');
		ft_putstr(s);
		p->res += FS + 2;
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(s);
		while (p->p_wd-- && ++p->res)
			ft_putchar(' ');
		p->res += FS + 2;
	}
}

void	write_point_c(char *s, t_prin *p)
{
	if (!p->fl_zero)
	{
		while (p->p_wd-- && ++p->res)
			ft_putchar(' ');
		ft_putstr("0x");
		if (p->precs > 0)
			while ((p->precs--) - (int)FS > 0 && ++p->res)
				ft_putchar('0');
		ft_putstr(s);
		p->res += FS + 2;
	}
	else
	{
		ft_putstr("0x");
		while (p->p_wd-- && ++p->res)
			ft_putchar('0');
		ft_putstr(s);
		p->res += FS + 2;
	}
}

void	write_point(char *s, t_prin *p, intmax_t n)
{
	if (!p->p_wd)
	{
		ft_putstr("0x");
		if (p->p_pr > 0)
		{
			while (p->p_pr-- && ++p->res)
				ft_putchar('0');
		}
		(n == 0 && p->precs == 0) ? (p->res--) : ft_putstr(s);
		p->res += FS + 2;
	}
	else
		write_point_c(s, p);
}

void	p_qual(va_list arg_ptr, t_prin *p)
{
	char		*s;
	intmax_t	n;

	n = (va_arg(arg_ptr, unsigned long int));
	s = ft_itoa_base(n, 16);
	find_p_w_forp(p, s);
	if (!p->fl_minus)
		write_point(s, p, n);
	else
		write_point_b(s, p);
	if (s && *s)
		free(s);
}
