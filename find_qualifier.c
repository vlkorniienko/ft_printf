/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_qualifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:41:10 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/01 16:24:33 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_signs(char *s, int *i, t_prin *r)
{
	char *point;

	point = NULL;
	while ((point = ft_strrchr("#-+0 ", s[*i])))
	{
		write_flags(point, r);
		(*i)++;
	}
}

void	d_i_qual(va_list arg_ptr, t_prin *p, char *str, int i)
{
	char		*s;
	intmax_t	n;

	if (p->l_size || str[i] == 'D')
		n = va_arg(arg_ptr, long int);
	else if (p->h_size)
		n = (short)va_arg(arg_ptr, int);
	else if (p->hh_size)
		n = (char)va_arg(arg_ptr, int);
	else if (p->ll_size)
		n = va_arg(arg_ptr, long long int);
	else if (p->j_size)
		n = va_arg(arg_ptr, intmax_t);
	else if (p->z_size)
		n = va_arg(arg_ptr, long int);
	else
		n = va_arg(arg_ptr, int);
	if (n > 0)
		s = ft_itoa_base(n, 10);
	else
		s = ft_itoa_plus(n, 10);
	flag_writter(p, s, n);
}

void	oxu_qual(va_list arg_ptr, t_prin *p, char *str, int i)
{
	if (p->l_size)
		find_base(va_arg(arg_ptr, unsigned long int), p, str, i);
	else if (p->ll_size)
		find_base(va_arg(arg_ptr, unsigned long long int), p, str, i);
	else if (p->h_size && str[i] != 'U')
		find_base((unsigned short)va_arg(arg_ptr, unsigned int), p, str, i);
	else if (p->hh_size && (str[i] == 'O' || str[i] == 'U'))
		find_base((unsigned int)va_arg(arg_ptr, unsigned int), p, str, i);
	else if (p->hh_size)
		find_base((unsigned char)va_arg(arg_ptr, unsigned int), p, str, i);
	else if (p->j_size)
		find_base(va_arg(arg_ptr, uintmax_t), p, str, i);
	else if (p->z_size)
		find_base(va_arg(arg_ptr, size_t), p, str, i);
	else if (str[i] == 'U' || str[i] == 'O')
		find_base(va_arg(arg_ptr, unsigned long int), p, str, i);
	else
		find_base(va_arg(arg_ptr, unsigned int), p, str, i);
}

void	sbig_size(wchar_t *val, t_prin *p)
{
	unsigned int	size;
	int				i;

	i = 0;
	while (val[i] != '\0')
	{
		size = size_binary(val[i]);
		if (size <= 7)
			p->sitr++;
		else if (size <= 11)
			p->sitr += 2;
		else if (size <= 16)
			p->sitr += 3;
		else
			p->sitr += 4;
		i++;
	}
}

void	find_perec(char *p, int *i, t_prin *pr)
{
	if (p[*i] == 's' || p[*i] == 'S' || p[*i] == 'p' || p[*i] == 'd' ||
		p[*i] == 'D' || p[*i] == 'i' || p[*i] == 'o' || p[*i] == 'O' ||
		p[*i] == 'u' || p[*i] == 'U' || p[*i] == 'x' || p[*i] == 'X' ||
		p[*i] == 'c' || p[*i] == 'C' || p[*i] == '%')
		return ;
	else
		put_char_c(pr, p[*i]);
}
