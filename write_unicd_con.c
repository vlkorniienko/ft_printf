/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unicd_con.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:16:04 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/10 12:16:06 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_unicc(unsigned char octet, t_prin *p)
{
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o4 = (p->v << 26) >> 26;
	o3 = ((p->v >> 6) << 26) >> 26;
	o2 = ((p->v >> 12) << 26) >> 26;
	o1 = ((p->v >> 18) << 29) >> 29;
	octet = (p->mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((p->mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((p->mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((p->mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
	p->res += 4;
}

void	write_flags(char *p, t_prin *r)
{
	if (*p == '+')
		r->fl_plus++;
	else if (*p == '-')
		r->fl_minus++;
	else if (*p == ' ')
		r->fl_space++;
	else if (*p == '#')
		r->fl_hash++;
	else
		r->fl_zero++;
}

void	find_width_ss(char *s, int *i, t_prin *r, char *w)
{
	int count;

	count = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		w[count] = s[*i];
		count++;
		(*i)++;
	}
	w[count] = '\0';
	r->width = ft_atoi(w);
	free(w);
}

void	find_width(char *s, int *i, t_prin *r)
{
	char	*p1;
	char	*p2;
	char	*width;
	int		j;
	int		count;

	j = *i;
	count = 0;
	if (s[j] != '.' && (!(p1 = ft_strrchr("sSpdDioOuUxXcC%", s[j]))
		&& (!(p2 = ft_strrchr("hljtzq", s[j])))))
	{
		while (s[j] >= '0' && s[j] <= '9')
		{
			count++;
			j++;
		}
		width = (char *)malloc(sizeof(char) * (count + 1));
		find_width_ss(s, i, r, width);
	}
}

void	find_precision(char *s, int *i, t_prin *r)
{
	char	*str;
	int		j;
	int		temp;

	if (s[*i] == '.')
	{
		(*i)++;
		temp = 0;
		j = *i;
		while (ft_isdigit(s[j++]))
			temp++;
		str = (char *)malloc(sizeof(char) * (temp + 1));
		temp = 0;
		while (ft_isdigit(s[*i]))
		{
			str[temp] = s[*i];
			temp++;
			(*i)++;
		}
		str[temp] = '\0';
		r->precs = ft_atoi(str);
		free(str);
	}
}
