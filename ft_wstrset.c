/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:23:15 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:23:18 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrset(wchar_t *b, int c, size_t n)
{
	wchar_t	*p;

	p = b;
	while (n--)
		*p++ = (unsigned char)c;
	return (b);
}
