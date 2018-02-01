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
	if (!sp.modifier)
		return (call_int(sp, va_arg(ap, int)));
// 	if (!ft_strcmp(sp.modifier, "h"))
// 		return (call_short);
// 	if (!ft_strcmp(sp.modifier, "hh"))
// 		return (call_schar);
// 	if (!ft_strcmp(sp.modifier, "l") || !ft_strcmp(sp.type, "D"))
// 		return (call_long(sp, ap))
// 	if (!ft_strcmp(sp.modifier, "ll"))
// 		return (call_longlong(sp, ap));
// 	if (!ft_strcmp(sp.modifier, "j"))
// 		return (call_intmax);
// 	if (!ft_strcmp(sp.modifier, "z"))
// 		return (call_usize_t);
}
