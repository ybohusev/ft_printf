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

	i = 0;
	if (sp.flag.minus && sp.flag.hash &&
		(!ft_strcmp(sp.type, "o") || !ft_strcmp(sp.type, "O")))
	{
		i += 1;
		ft_putchar('0');
	}
	while (i < sp.width)
	{
		ft_putchar(' ');
		i++;
	}
	if (!sp.flag.minus && sp.flag.hash &&
		(!ft_strcmp(sp.type, "o") || !ft_strcmp(sp.type, "O")))
	{
		i += 1;
		ft_putchar('0');
	}
	return (i);
}

static	char	*ch_base(uintmax_t a, t_spec sp)
{
	char	*arg;

	arg = NULL;
	if (!ft_strcmp(sp.type, "o") ||
		!ft_strcmp(sp.type, "O"))
		arg = ft_itoa_base(a, 8);
	else if (!ft_strcmp(sp.type, "u") ||
		!ft_strcmp(sp.type, "U"))
		arg = ft_itoa_base(a, 10);
	else if (!ft_strcmp(sp.type, "x") ||
		!ft_strcmp(sp.type, "X"))
		arg = ft_itoa_base(a, 16);
	return (arg);
}

static	void	capitalize(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]) && arg[i] >= 97 &&
			arg[i] <= 122)
			arg[i] = arg[i] - 32;
		i++;
	}
}

extern	int		call_uint(t_spec sp, uintmax_t a)
{
	char	*arg;
	int		printed;
	int		tmp;

	printed = 0;
	arg = ch_base(a, sp);
	arg = precis(arg, sp);
	tmp = ft_strlen(arg);
	arg = width(sp, arg);
	if (sp.flag.hash && a != 0)
		arg = hash_uint(arg, sp, tmp);
	if (!ft_strcmp(sp.type, "X"))
		capitalize(arg);
	if (sp.precision == 0 && a == 0)
	{
		printed = zero(sp);
	}
	else
		printed = ft_putstr(arg);
	free(arg);
	return (printed);
}
