/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:59:42 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 12:59:44 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*change_ch(char *arg, t_spec sp, int a)
{
	int		i;

	i = 0;
	while (!ft_isdigit(arg[i + 1]))
		i++;
	if (a < 0)
		arg[i] = '-';
	else if (sp.flag.plus)
		arg[i] = '+';
	else if (sp.flag.space)
		arg[i] = ' ';
	return (arg);
}

static	char	*add_ch(char *arg, t_spec sp, int a)
{
	char	*tmp;

	tmp = arg;
	if (a < 0)
		arg = ft_strjoin("-", arg);
	else if (sp.flag.plus)
		arg = ft_strjoin("+", arg);
	else if (sp.flag.space)
		arg = ft_strjoin(" ", arg);
	free(tmp);
	return (arg);
}

static	char	*change_ch_l(char *arg, t_spec sp, int a, char *t)
{
	int		i;
	char	*tmp;

	tmp = arg;
	i = ft_strlen(arg);
	if (a < 0)
		arg = ft_strjoin("-", arg);
	else if (sp.flag.plus)
		arg = ft_strjoin("+", arg);
	else if (sp.flag.space)
		arg = ft_strjoin(" ", arg);
	if (sp.width > (int)ft_strlen(t))
		arg[i] = '\0';
	if (tmp != arg)
		free(tmp);
	return (arg);
}

extern	char	*sign_int(char *arg, char *tmp, t_spec sp, int a)
{
	if (sp.width > (int)ft_strlen(tmp) && !sp.flag.minus)
		arg = change_ch(arg, sp, a);
	else if (sp.flag.minus && sp.width > (int)ft_strlen(tmp))
		arg = change_ch_l(arg, sp, a, tmp);
	else if (a < 0 || sp.flag.plus || sp.flag.space)
		arg = add_ch(arg, sp, a);
	return (arg);
}
