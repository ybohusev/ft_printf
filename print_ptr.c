/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:28:30 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:28:40 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ptr(t_spec sp, void *ptr)
{
	char			*arg;
	char			*tmp;
	unsigned long	x;
	int				printed;

	x = (unsigned long)ptr;
	if (sp.flag.zero)
		sp.flag.zero = 0;
	arg = ft_itoa_base(x, 16);
	tmp = arg;
	arg = ft_strjoin("0x", arg);
	arg = width(sp, arg);
	printed = ft_putstr(arg);
	free(tmp);
	free(arg);
	return (printed);
}
