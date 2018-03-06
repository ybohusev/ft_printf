/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:46:35 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 10:46:37 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*prec_str(char *str, t_spec sp)
{
	if (sp.precision < (int)ft_strlen(str) && sp.precision != -1)
		str = ft_strsub(str, 0, sp.precision);
	return (str);
}

static	wchar_t	*prec_wstr(wchar_t *wstr, t_spec sp)
{
	int		oct;
	int		count;

	oct = 0;
	count = 0;
	if (sp.precision < (int)ft_wstrsize(wstr) && sp.precision != -1)
	{
		while ((oct += ft_count_octets(wstr[count])) <= sp.precision)
			count++;
		wstr = ft_wstrsub(wstr, 0, count);
	}
	return (wstr);
}

extern	int		print_str(t_spec sp, char *str)
{
	char	*pos;
	int		diff;

	if (!str)
		return (ft_putstr("(null)"));
	str = prec_str(str, sp);
	if (sp.width <= (int)ft_strlen(str))
		return (ft_putstr(str));
	diff = sp.width - (int)ft_strlen(str);
	pos = (char*)ft_memset(ft_strnew(diff), ' ', diff);
	if (sp.flag.minus)
		str = ft_strjoin(str, pos);
	else
		str = ft_strjoin(pos, str);
	diff = ft_putstr(str);
	free(str);
	return (diff);
}

extern	int		print_wstr(t_spec sp, wchar_t *wstr)
{
	wchar_t	*pos;
	int		diff;

	if (!wstr)
		return (ft_putstr("(null)"));
	wstr = prec_wstr(wstr, sp);
	if (sp.width <= (int)ft_wstrsize(wstr))
		return (ft_putwstr(wstr));
	diff = sp.width - (int)ft_wstrsize(wstr);
	pos = (wchar_t*)ft_wstrset(ft_wstrnew(diff), L' ', diff);
	if (sp.flag.minus)
		wstr = ft_wstrjoin(wstr, pos);
	else
		wstr = ft_wstrjoin(pos, wstr);
	diff = ft_putwstr(wstr);
	free(wstr);
	return (diff);
}
