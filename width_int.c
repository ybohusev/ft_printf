/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:59:18 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/05 12:59:20 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	char	*width(t_spec sp, char *arg)
{
	char	*pos;
	char	*tmp;
	int		diff;

	tmp = arg;
	if ((diff = sp.width - (int)ft_strlen(arg)) > 0)
	{
		if (sp.flag.zero && !sp.flag.minus && sp.precision == -1)
		{
			pos = (char*)ft_memset(ft_strnew(diff), '0', diff);
			arg = ft_strjoin(pos, arg);
		}
		else
		{
			pos = (char*)ft_memset(ft_strnew(diff), ' ', diff);
			if (sp.flag.minus)
				arg = ft_strjoin(arg, pos);
			else
				arg = ft_strjoin(pos, arg);
		}
		free(tmp);
		free(pos);
	}
	return (arg);
}
