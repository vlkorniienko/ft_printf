/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_begin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:41:52 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/14 15:41:56 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_h_mod(char *s, int *i, t_prin *r)
{
	if (s[*i] == 'h')
	{
		if (s[*i + 1] == 'h')
			r->hh_size++;
		else
			r->h_size++;
	}
	else
	{
		if (s[*i + 1] == 'l')
			r->ll_size++;
		else
			r->l_size++;
	}
}

void	find_modif(char *s, int *i, t_prin *r)
{
	char *p;

	p = NULL;
	if (!(p = ft_strrchr("sSpdDioOuUxXcC%", s[*i])))
	{
		if (s[*i] == 'l' || s[*i] == 'h')
			l_h_mod(s, i, r);
		else if (s[*i] == 'j')
			r->j_size++;
		else
			r->z_size++;
	}
	while ((p = ft_strrchr("hljz", s[*i])))
		(*i)++;
}

void	find_real_p(char *s, t_prin *p)
{
	if (p->precs)
	{
		p->p_pr = p->precs - ft_strlen(s);
		if (p->p_pr < 0)
			p->p_pr = 0;
	}
}

void	find_real_w(char *s, t_prin *p, intmax_t n)
{
	if (p->width)
	{
		p->p_wd = p->width - ft_strlen(s) - p->p_pr - p->fl_plus -
		p->fl_space - p->fl_hash;
		if (n < 0)
			p->p_wd--;
		if (p->p_wd < 0)
			p->p_wd = 0;
	}
}

void	flag_writter(t_prin *p, char *s, intmax_t n)
{
	find_real_p(s, p);
	find_real_w(s, p, n);
	if (p->p_wd)
	{
		if (n >= 0)
			print_posit_wd(s, p, n);
		else
			print_negat_w(s, p);
	}
	else
		print_no_wd(s, p, n);
	if (s && *s)
		free(s);
}
