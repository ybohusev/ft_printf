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

static	char	*ch_base(uintmax_t a, t_spec sp)
{
	char	*arg;
	int		i;

	arg = NULL;
	i = 0;
	if (!ft_strcmp(sp.type, "o") ||
		!ft_strcmp(sp.type, "O"))
		arg = ft_itoa_base(a, 8);
	else if (!ft_strcmp(sp.type, "u") ||
		!ft_strcmp(sp.type, "U"))
		arg = ft_itoa_base(a, 10);
	else if (!ft_strcmp(sp.type, "x") ||
		!ft_strcmp(sp.type, "X"))
		arg = ft_itoa_base(a, 16);
	if (!ft_strcmp(sp.type, "X"))
	{
		while (arg[i])
		{
			if (ft_isalpha(arg[i]) && arg[i] >= 97 &&
				arg[i] <= 122)
				arg[i] = arg[i] - 32;
			i++;
		}
	}
	return (arg);
}	

extern	int		call_uint(t_spec sp, uintmax_t a)
{
	char	*arg;
	int		printed;

	printed = 0;
	arg = ch_base(a, sp);
	arg = precis(arg, sp);
	arg = width(sp, arg);
	if (sp.flag.hash)
		arg = hash_uint(arg, sp);
	if (sp.precision == 0 && a == 0)
		printed = zero(sp);
	else
		printed = ft_putstr(arg);
	free(arg);
	return(printed);
}
