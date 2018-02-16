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

static	int		zero_width(t_spec sp)
{
	if (sp.flag.plus)
	{
		ft_putchar('+');
		return (1);
	}
	else if (sp.flag.space)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

static	int		zero(t_spec sp)
{
	char	*tmp;

	if (!sp.width)
		return (zero_width(sp));
	tmp = (char*)ft_memset(ft_strnew(sp.width), ' ', sp.width);
	if (!sp.flag.minus)
	{
		if (sp.flag.plus)
			tmp[ft_strlen(tmp) - 1] = '+';
		else if (sp.flag.space)
			tmp[ft_strlen(tmp) - 1] = ' ';
	}
	if (sp.flag.minus)
	{
		if (sp.flag.plus)
			tmp[0] = '+';
		else if (sp.flag.space)
			tmp[0] = ' ';
	}
	ft_putstr(tmp);
	free(tmp);
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
	arg = ft_itoa_large(a);
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
	return (printed);
}
