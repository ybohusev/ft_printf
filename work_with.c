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
	if (!sp.modifier && ft_strcmp(sp.type, "D"))
		return (call_int(sp, va_arg(ap, int)));
	else if (!ft_strcmp(sp.type, "D"))
		return (call_int(sp, va_arg(ap, long int)));
	else if (sp.modifier == M_H)
		return (call_int(sp, (short)va_arg(ap, int)));
	else if (sp.modifier == M_HH)
		return (call_int(sp, (char)va_arg(ap, int)));
	else if (sp.modifier == M_L)
		return (call_int(sp, va_arg(ap, long int)));
	else if (sp.modifier == M_LL)
		return (call_int(sp, va_arg(ap, long long int)));
	else if (sp.modifier == M_J)
		return (call_int(sp, va_arg(ap, intmax_t)));
	else if (sp.modifier == M_Z)
		return (call_int(sp, va_arg(ap, ssize_t)));
	return (0);
}

extern	int		work_with_uns(t_spec sp, va_list ap)
{
	if (!sp.modifier && ft_strcmp(sp.type, "U") && ft_strcmp(sp.type, "O"))
		return (call_uint(sp, va_arg(ap, unsigned int)));
	else if (!ft_strcmp(sp.type, "U") || !ft_strcmp(sp.type, "O"))
		return (call_uint(sp, va_arg(ap, unsigned long int)));
	else if (sp.modifier == M_HH)
		return (call_uint(sp, (unsigned char)va_arg(ap, unsigned int)));
	else if (sp.modifier == M_H)
		return (call_uint(sp, (unsigned short)va_arg(ap, unsigned int)));
	else if (sp.modifier == M_L || !ft_strcmp(sp.type, "U") ||
			!ft_strcmp(sp.type, "O"))
		return (call_uint(sp, va_arg(ap, unsigned long int)));
	else if (sp.modifier == M_LL)
		return (call_uint(sp, va_arg(ap, unsigned long long int)));
	else if (sp.modifier == M_J)
		return (call_uint(sp, va_arg(ap, uintmax_t)));
	else if (sp.modifier == M_Z)
		return (call_uint(sp, va_arg(ap, size_t)));
	return (0);
}

extern	int		work_with_char(t_spec sp, va_list ap)
{
	if (!sp.modifier && ft_strcmp(sp.type, "C"))
		return (print_char(sp, va_arg(ap, unsigned int)));
	if (sp.modifier == M_L || !ft_strcmp(sp.type, "C"))
		return (print_wchar(sp, va_arg(ap, unsigned int)));
	return (0);
}

extern	int		work_with_str(t_spec sp, va_list ap)
{
	if (!sp.modifier && ft_strcmp(sp.type, "S"))
		return (print_str(sp, va_arg(ap, char*)));
	if (sp.modifier == M_L || !ft_strcmp(sp.type, "S"))
		return (print_wstr(sp, va_arg(ap, wchar_t*)));
	return (0);
}

extern	int		work_with_ptr(t_spec sp, va_list ap)
{
	return (print_ptr(sp, va_arg(ap, void*)));
}
