/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:58:44 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 12:58:47 by ybohusev         ###   ########.fr       */
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

static	char	*d_sign(char *arg)
{
	char	*new;

	arg++;
	new = ft_strdup(arg);
	arg--;
	free(arg);
	return (new);
}

extern	int		call_int(t_spec sp, intmax_t a)
{
	char	*arg;
	int		printed;
	char	*tmp;
	int		minus;

	printed = 0;
	minus = 1;
	arg = ft_itoa(a);
	if (a < 0)
	{
		minus = -1;
		arg = d_sign(arg);
	}
	arg = precis(arg, sp);
	tmp = arg;
	arg = width(sp, arg);
	arg = sign_int(arg, tmp, sp, minus);
	if (sp.precision == 0 && a == 0)
		printed = zero(sp);
	else
		printed = ft_putstr(arg);
	free(arg);
	return(printed);
}
