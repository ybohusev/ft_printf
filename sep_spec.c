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
	int		i;
	t_flags	flag;

	i = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.hash = 0;
	flag.zero = 0;
	while ((*sp)[i] == '-' || (*sp)[i] == '+' || (*sp)[i] == ' ' ||
			(*sp)[i] == '#' || (*sp)[i] == '0')
	{
		if ((*sp)[i] == '-')
			flag.minus = 1;
		else if ((*sp)[i] == '+')
			flag.plus = 1;
		else if ((*sp)[i] == ' ')
			flag.space = 1;
		else if ((*sp)[i] == '#')
			flag.hash = 1;
		else if ((*sp)[i] == '0')
			flag.zero = 1;
		i++;
	}
	*sp += i;
	return (flag);
}

int		get_width(char **sp)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (ft_isdigit((*sp)[i]))
		i++;
	width = ft_atoi(*sp);
	*sp += i;
	return (width);
}

int		get_precision(char **sp)
{
	int		i;
	int		precision;

	i = 0;
	precision = 0;
	if ((*sp)[i] != '.')
		return (-1);
	(*sp)++;
	while (ft_isdigit((*sp)[i]))
		i++;
	precision = ft_atoi(*sp);
	*sp += i;
	return (precision);
}

char	*get_modifier(char **sp)
{
	char	*modifier;

	modifier = NULL;
	if ((**sp == 'h' && *(*sp + 1) == 'h') ||
		(**sp == 'l' && *(*sp + 1) == 'l'))
	{
		modifier = ft_strsub(*sp, 0, 2);
		*sp += 2;
	}
	else if (**sp == 'h' || **sp == 'l' || **sp == 'j' || **sp == 'z')
	{
		modifier = ft_strsub(*sp, 0, 1);
		*sp++;
	}
	return (modifier);
}

char	*get_type(char **sp)
{
	char	*type;

	type = ft_strdup(*sp);
	return (type);
}
