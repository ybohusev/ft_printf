/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:59:34 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/27 10:59:37 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern	int		work_with_dec(t_spec sp, va_list ap)
{
	if (!ft_strcmp(sp.type, "D"))
 		return (call_int(sp, va_arg(ap, long int)));
	else if (!sp.modifier || !ft_strcmp(sp.modifier, "h") ||
		!ft_strcmp(sp.modifier, "hh"))
		return (call_int(sp, va_arg(ap, int)));
 	else if (!ft_strcmp(sp.modifier, "l"))
 		return (call_int(sp, va_arg(ap, long int)));
 	else if (!ft_strcmp(sp.modifier, "ll"))
		return (call_int(sp, va_arg(ap, long long int)));
	else if (!ft_strcmp(sp.modifier, "j"))
		return (call_int(sp, va_arg(ap, intmax_t)));
	else if (!ft_strcmp(sp.modifier, "z"))
		return (call_int(sp, va_arg(ap, ssize_t)));
	return (0);
}

extern	int		work_with_uns(t_spec sp, va_list ap)
{
	if (!ft_strcmp(sp.type, "U") || !ft_strcmp(sp.type, "O"))
 		return (call_int(sp, va_arg(ap, unsigned long int)));
	else if (!sp.modifier || !ft_strcmp(sp.modifier, "h") ||
		!ft_strcmp(sp.modifier, "hh"))
		return (call_uint(sp, va_arg(ap, unsigned int)));
 	else if (!ft_strcmp(sp.modifier, "l"))
 		return (call_uint(sp, va_arg(ap, unsigned long int)));
 	else if (!ft_strcmp(sp.modifier, "ll"))
		return (call_uint(sp, va_arg(ap, unsigned long long int)));
	else if (!ft_strcmp(sp.modifier, "j"))
		return (call_uint(sp, va_arg(ap, uintmax_t)));
	else if (!ft_strcmp(sp.modifier, "z"))
		return (call_uint(sp, va_arg(ap, size_t)));
	return (0);
}
