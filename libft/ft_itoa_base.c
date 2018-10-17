/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:36:12 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/03 18:21:31 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checker(intmax_t number, int base)
{
	int j;

	j = 0;
	if (number <= 0 && base == 10)
		j++;
	while (number)
	{
		number = number / base;
		j++;
	}
	return (j);
}

char	*ft_itoa_base(intmax_t n, int base)
{
	int		size;
	char	*p;

	p = NULL;
	if (n == MIN_LONG || n == 0)
	{
		p = ft_strdup((n == 0) ? "0" : "-9223372036854775808");
		return (p);
	}
	size = checker(n, base);
	if (!(p = ft_memalloc(size + 1)))
		return (NULL);
	p[size--] = '\0';
	if (n < 0)
		n *= -1;
	while (n)
	{
		p[size] = (n % base > 9) ? (n % base + 87) : (n % base + 48);
		n = n / base;
		size--;
	}
	if (p[0] == 0)
		p[0] = '-';
	return (p);
}
