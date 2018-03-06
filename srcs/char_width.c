/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:46:19 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 08:46:21 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_width(t_spec sp, int bytes)
{
	int		i;

	i = 0;
	if (sp.width > bytes)
	{
		while (i < sp.width - bytes)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}
