/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:46:55 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 08:46:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*hash_oct(char *arg, t_spec sp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = arg;
	while (!ft_isdigit(arg[i]))
		i++;
	if (sp.flag.minus && arg[i] != '0')
	{
		while (ft_isdigit(arg[i]))
			i++;
		while (i != 0)
		{
			arg[i] = arg[i - 1];
			i--;
		}
		arg[i] = '0';
	}
	else if (!i && arg[i] != '0' && (arg = ft_strjoin("0", arg)))
		free(tmp);
	else if (arg[i] != '0')
		arg[i - 1] = '0';
	return (arg);
}

static	char	*n_minus_hex(char *arg, t_spec sp, int bwidth)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = arg;
	if (sp.width - bwidth >= 2)
	{
		if (sp.flag.zero)
			arg[1] = 'x';
		else
		{
			while (!ft_isdigit(arg[i]))
				i++;
			arg[i - 1] = 'x';
			arg[i - 2] = '0';
		}
	}
	else if (sp.width - bwidth == 1)
	{
		arg[0] = 'x';
		arg = ft_strjoin("0", arg);
		free(tmp);
	}
	return (arg);
}

static	char	*minus_hex(char *arg, int bwidth, t_spec sp)
{
	char	*tmp;
	int		len_arg;

	tmp = arg;
	len_arg = ft_strlen(arg);
	arg = ft_strjoin("0x", arg);
	if (sp.width - bwidth >= 2)
	{
		arg[len_arg + 1] = '\0';
		arg[len_arg] = '\0';
	}
	else if (sp.width - bwidth == 1)
		arg[len_arg + 1] = '\0';
	free(tmp);
	return (arg);
}

static	char	*hash_hex(char *arg, t_spec sp, int bwidth)
{
	char	*tmp;

	tmp = arg;
	if (!sp.flag.minus)
	{
		if (sp.width - bwidth <= 0)
		{
			arg = ft_strjoin("0x", arg);
			free(tmp);
		}
		else
			arg = n_minus_hex(arg, sp, bwidth);
	}
	else
		arg = minus_hex(arg, bwidth, sp);
	return (arg);
}

extern	char	*hash_uint(char *arg, t_spec sp, int bwidth)
{
	if (!ft_strcmp(sp.type, "o") ||
		!ft_strcmp(sp.type, "O"))
		arg = hash_oct(arg, sp);
	else if (!ft_strcmp(sp.type, "x") ||
		!ft_strcmp(sp.type, "X"))
		arg = hash_hex(arg, sp, bwidth);
	return (arg);
}
