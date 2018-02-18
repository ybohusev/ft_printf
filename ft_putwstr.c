/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:38:09 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/18 15:38:13 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_putwstr(wchar_t *wstr)
{
	int i;
	int	prt;

	i = 0;
	prt = 0;
	if (wstr != NULL)
	{
		while (wstr[i])
		{
			ft_putwchar(wstr[i]);
			i++;
			prt += ft_count_octets(wstr[i]);
		}
	}
	return (prt);
}
