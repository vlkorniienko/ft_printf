/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unicd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:43:10 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/10 11:43:12 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_unicb(unsigned char octet, t_prin *p)
{
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o3 = (p->v << 26) >> 26;
	o2 = ((p->v >> 6) << 26) >> 26;
	o1 = ((p->v >> 12) << 28) >> 28;
	octet = (p->mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((p->mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((p->mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
	p->res += 3;
}

void	write_unica(unsigned char octet, t_prin *p)
{
	unsigned char o2;
	unsigned char o1;

	o2 = (p->v << 26) >> 26;
	o1 = ((p->v >> 6) << 27) >> 27;
	octet = (p->mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((p->mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
	p->res += 2;
}

void	write_unic(unsigned char octet, wchar_t value, t_prin *p)
{
	octet = value;
	write(1, &octet, 1);
	p->res++;
}

int		size_binary(unsigned int number)
{
	int res;

	res = 0;
	while (number)
	{
		number /= 2;
		res++;
	}
	return (res);
}

void	c_big_begin(wchar_t value, t_prin *p)
{
	int				size;
	unsigned char	octet;

	octet = '\0';
	p->mask0 = 0;
	p->mask1 = 49280;
	p->mask2 = 14712960;
	p->mask3 = 4034953344;
	p->v = value;
	size = size_binary(value);
	if (size <= 7)
		write_unic(octet, value, p);
	else if (size <= 11)
		write_unica(octet, p);
	else if (size <= 16)
		write_unicb(octet, p);
	else
		write_unicc(octet, p);
}
