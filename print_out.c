/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:11:02 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/23 10:11:03 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_begin(char *s, t_prin *p)
{
	if (p->fl_space && ++p->res)
		ft_putchar(' ');
	if (p->fl_plus && ++p->res)
		ft_putchar('+');
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_cont(char *s, t_prin *p)
{
	ft_putchar('-');
	p->res++;
	while (p->p_pr-- && ++p->res)
		ft_putchar('0');
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_a(char *s, t_prin *p, intmax_t n)
{
	if (p->fl_minus && p->fl_plus && n == 0 && p->precs == 0)
	{
		ft_putchar('+');
		p->res++;
		return ;
	}
	if (p->fl_minus && p->fl_plus && n == 0 && p->precs == -42)
	{
		ft_putchar('+');
		ft_putchar('0');
		p->res++;
		return ;
	}
	if (n == 0 && !p->fl_plus && !p->fl_space && p->precs == 0)
		return ;
	if (p->fl_space && !p->fl_plus && ++p->res)
		ft_putchar(' ');
	if (p->fl_plus && ++p->res)
		ft_putchar('+');
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_b(char *s, t_prin *p)
{
	ft_putchar('-');
	p->res++;
	ft_putstr(s);
	p->res += ft_strlen(s);
}

void	print_no_wd(char *s, t_prin *p, intmax_t n)
{
	if (p->p_pr)
	{
		if (n >= 0)
			print_begin(s, p);
		else
			print_cont(s, p);
	}
	else
	{
		if (n >= 0)
			print_a(s, p, n);
		else
			print_b(s, p);
	}
}
