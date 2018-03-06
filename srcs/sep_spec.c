/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:27:14 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/25 15:27:16 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	get_flag(char **sp)
{
	t_flags	flag;

	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.hash = 0;
	flag.zero = 0;
	while (**sp == '-' || **sp == '+' || **sp == ' ' ||
			**sp == '#' || **sp == '0')
	{
		if (**sp == '-')
			flag.minus = 1;
		else if (**sp == '+')
			flag.plus = 1;
		else if (**sp == ' ')
			flag.space = 1;
		else if (**sp == '#')
			flag.hash = 1;
		else if (**sp == '0')
			flag.zero = 1;
		(*sp)++;
	}
	return (flag);
}

int		get_width(char **sp, va_list ap)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	if ((*sp)[i] == '*')
	{
		width = va_arg(ap, int);
		*sp += 1;
		return (width);
	}
	while (ft_isdigit((*sp)[i]))
		i++;
	width = ft_atoi(*sp);
	*sp += i;
	return (width);
}

int		get_precision(char **sp, va_list ap)
{
	int		i;
	int		precision;

	i = 0;
	precision = 0;
	if ((*sp)[i] != '.')
	{
		if ((*sp)[i] == '*')
		{
			precision = va_arg(ap, int);
			*sp += 1;
			return (precision);
		}
		return (-1);
	}
	(*sp)++;
	while (ft_isdigit((*sp)[i]))
		i++;
	precision = ft_atoi(*sp);
	*sp += i;
	return (precision);
}

int		get_modifier(char **sp)
{
	int		mod;

	mod = 0;
	if (!strncmp(*sp, "hh", 2))
		mod = M_HH;
	else if (!strncmp(*sp, "ll", 2))
		mod = M_LL;
	else if (!strncmp(*sp, "h", 1))
		mod = M_H;
	else if (!strncmp(*sp, "l", 1))
		mod = M_L;
	else if (!strncmp(*sp, "j", 1))
		mod = M_J;
	else if (!strncmp(*sp, "z", 1))
		mod = M_Z;
	if (mod == M_LL || mod == M_HH)
		*sp += 2;
	else if (mod == M_L || mod == M_H ||
			mod == M_J || mod == M_Z)
		*sp += 1;
	return (mod);
}

char	*get_type(char **sp)
{
	char	*type;

	type = ft_strdup(*sp);
	return (type);
}
