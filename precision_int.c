/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:59:57 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 13:00:01 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	char	*precis(char *arg, t_spec sp)
{
	char	*tmp;
	int		diff;
	char	*zeros;

	tmp = arg;
	if (sp.precision > (int)ft_strlen(arg))
	{
		diff = sp.precision - (int)ft_strlen(arg);
		zeros = (char*)ft_memset(ft_strnew(diff), '0', diff);
		arg = ft_strjoin(zeros, arg);
		free(zeros);
		free(tmp);
	}
	return (arg);
}
