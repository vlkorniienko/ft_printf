/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_qualifier_cont.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:25:58 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/06 10:50:02 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_iniz(t_prin *r)
{
	r->fl_minus = 0;
	r->fl_plus = 0;
	r->fl_space = 0;
	r->fl_hash = 0;
	r->fl_zero = 0;
	r->width = 0;
	r->precs = -42;
	r->h_size = 0;
	r->hh_size = 0;
	r->l_size = 0;
	r->ll_size = 0;
	r->j_size = 0;
	r->z_size = 0;
	r->p_pr = 0;
	r->p_wd = 0;
	r->temp_z = 1;
	r->t_i = 0;
	r->pr_o = 0;
	r->itr = 0;
	r->sitr = 0;
	r->check = 0;
}

void	c_big_qual(char *str, int i, va_list arg_ptr, t_prin *p)
{
	wchar_t v;
	char	vl;

	if (str[i] == 'C' || (str[i] == 'c' && p->l_size))
	{
		v = va_arg(arg_ptr, wchar_t);
		c_big_begin(v, p);
	}
	else if (str[i] == 'c' && !p->l_size)
	{
		vl = va_arg(arg_ptr, int);
		put_char_c(p, vl);
	}
}

void	find_base(uintmax_t n, t_prin *p, char *str, int i)
{
	char *s;

	if (str[i] == 'u')
		s = ft_itoa_baseuns(n, 10, 'a');
	else if (str[i] == 'U')
		s = ft_itoa_baseuns(n, 10, 'a');
	else if (str[i] == 'o')
	{
		s = ft_itoa_baseuns(n, 8, 'a');
		p->pr_o = 1;
	}
	else if (str[i] == 'O')
	{
		s = ft_itoa_baseuns(n, 8, 'a');
		p->pr_o = 1;
	}
	else if (str[i] == 'x')
	{
		s = ft_itoa_baseuns(n, 16, 'a');
		p->temp_z = 42;
	}
	else
		s = ft_itoa_baseuns(n, 16, 'A');
	p->t_i = i;
	write_oux(p, s, n, str);
}

void	write_oux(t_prin *p, char *s, uintmax_t n, char *str)
{
	find_real_p(s, p);
	find_wd_oux(s, p);
	if (!(p->fl_minus))
	{
		if (p->p_wd)
		{
			if (!(p->p_pr))
				print_uox(p, str, n, s);
			else
				print_uox_b(p, str, n, s);
		}
		else
		{
			if (p->p_pr)
				print_uox_c(p, str, n, s);
			else
				print_uox_d(p, s, n, str);
		}
	}
	else
		print_uox_fin(p, s, n, str);
	if (s && *s)
		free(s);
}
