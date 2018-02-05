/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:49:36 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 14:49:38 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		zero(t_spec sp)
{
	int		i;

	i = 1;
	if (sp.flag.minus && sp.flag.plus)
		ft_putchar('+');
	while (i < sp.width)
	{
		ft_putchar(' ');
		i++;
	}
	if (!sp.flag.minus && sp.flag.plus)
		ft_putchar('+');
	return (sp.width);
}

extern	int		call_uint(t_spec sp, uintmax_t a)
{
	char	*arg;
	int		printed;
	char	*tmp;

	printed = 0;
	arg = ft_itoa(a);
	arg = precis(arg, sp);
	tmp = arg;
	arg = width(sp, arg);
	if (sp.precision == 0 && a == 0)
		printed = zero(sp);
	else
		printed = ft_putstr(arg);
	free(arg);
	return(printed);
}
