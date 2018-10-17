/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 13:50:11 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/05 15:40:50 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	second_function(char *s, int i, va_list arg_ptr, t_prin *r)
{
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return ;
			struct_iniz(r);
			find_signs(s, &i, r);
			find_width(s, &i, r);
			find_precision(s, &i, r);
			find_modif(s, &i, r);
			dissection(s, i, arg_ptr, r);
			find_perec(s, &i, r);
			r->counter++;
		}
		else
		{
			write(1, &s[i], 1);
			r->res2++;
		}
		i++;
	}
}

void	s_qual(char *str, int i, va_list arg_ptr, t_prin *p)
{
	char	*s;
	wchar_t *ss;

	if ((str[i] == 's' && !p->l_size) || (str[i] == 'S' && MB_CUR_MAX < 4))
	{
		s = va_arg(arg_ptr, char *);
		write_string(p, s, str, i);
	}
	else if ((str[i] == 'S' && MB_CUR_MAX > 1)
		|| (str[i] == 's' && p->l_size))
	{
		ss = va_arg(arg_ptr, wchar_t *);
		if (ss == NULL)
		{
			write_zero_s(p, ss);
			return ;
		}
		sbig_size(ss, p);
		write_big_s(ss, p);
	}
}

void	dissection(char *str, int i, va_list arg_ptr, t_prin *p)
{
	if (str[i] == 's' || str[i] == 'S')
		s_qual(str, i, arg_ptr, p);
	else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'D')
		d_i_qual(arg_ptr, p, str, i);
	else if (str[i] == 'o' || str[i] == 'x' || str[i] == 'u' ||
		str[i] == 'O' || str[i] == 'X' || str[i] == 'U')
		oxu_qual(arg_ptr, p, str, i);
	else if (str[i] == 'p')
		p_qual(arg_ptr, p);
	else if (str[i] == 'C' || str[i] == 'c')
		c_big_qual(str, i, arg_ptr, p);
	else if (str[i] == '%')
		put_char_cc(p, str[i]);
}

void	first_function(char *s, va_list arg_ptr, t_prin *r)
{
	int i;

	i = 0;
	r->res = 0;
	r->res2 = 0;
	r->counter = 0;
	second_function(s, i, arg_ptr, r);
	if (s[i] == '\0' && r->counter == 0)
	{
		ft_putstr(s);
		r->res = ft_strlen(s);
	}
}

int		ft_printf(const char *format, ...)
{
	t_prin	*p;
	va_list	arg_ptr;
	int		res;

	if (!(p = (t_prin *)malloc(sizeof(t_prin))))
		return (0);
	va_start(arg_ptr, format);
	first_function((char *)format, arg_ptr, p);
	va_end(arg_ptr);
	res = p->res + p->res2;
	free(p);
	return (res);
}
