/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseuns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:06:54 by vkorniie          #+#    #+#             */
/*   Updated: 2018/07/11 17:06:56 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checker_k(unsigned long long number, int base)
{
	int j;

	j = 0;
	if (number == 0)
		j++;
	while (number)
	{
		number = number / base;
		j++;
	}
	return (j);
}

char	*ft_itoa_baseuns(unsigned long long n, int base, char c)
{
	int		size;
	char	*p;

	size = checker_k(n, base);
	if (!(p = ft_memalloc(size + 1)))
		return (NULL);
	if (n == 0)
	{
		p = ft_strdup("0");
		return (p);
	}
	p[size--] = '\0';
	while (n)
	{
		p[size] = (n % base > 9) ? (n % base + c - 10) : (n % base + 48);
		n = n / base;
		size--;
	}
	return (p);
}
