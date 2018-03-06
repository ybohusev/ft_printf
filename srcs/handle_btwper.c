/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_btwper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:32:19 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 15:32:21 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

extern	int		handle_btwper(t_spec sp)
{
	char	*arg;
	int		printed;

	if (sp.width <= 1)
		return (ft_putstr("%"));
	arg = ft_strnew(sp.width);
	arg = ft_memset(arg, ' ', sp.width);
	if (!sp.flag.minus)
		arg[sp.width - 1] = '%';
	else
		arg[0] = '%';
	printed = ft_putstr(arg);
	free(arg);
	printf("HERE\n");
	return (printed);
}
