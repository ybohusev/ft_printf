/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:19:58 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 10:20:00 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		mem_size(intmax_t n, int base)
{
	int		i;

	i = 1;
	while (n / base != 0)
	{
		i++;
		n = n / base;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

extern	char	*ft_itoa_base(intmax_t n, int base)
{
	unsigned long long	temp;
	char				*str;
	int					i;

	i = mem_size(n);
	if (n < 0)
		temp = n * -1;
	else
		temp = n;
	str = (char*)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
