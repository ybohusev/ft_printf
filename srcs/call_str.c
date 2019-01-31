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

static	int		prec_str(char **str, t_spec sp)
{
	if (sp.precision < (int)ft_strlen(*str) && sp.precision != -1)
	{
		*str = ft_strsub(*str, 0, sp.precision);
		return (1);
	}
	return (0);
}

static	int		prec_wstr(wchar_t **wstr, t_spec sp)
{
	int		oct;
	int		count;

	oct = 0;
	count = 0;
	if (sp.precision < (int)ft_wstrsize(*wstr) && sp.precision != -1)
	{
		while ((oct += ft_count_octets(*wstr[count])) <= sp.precision)
			count++;
		*wstr = ft_wstrsub(*wstr, 0, count);
		return (1);
	}
	return (0);
}

extern	int		print_str(t_spec sp, char *str)
{
	char	*pos;
	char	*con;
	int		diff;
	int		is_alloc;

	if (!str)
		return (ft_putstr("(null)"));
	is_alloc = prec_str(&str, sp);
	if (sp.width <= (int)ft_strlen(str))
		diff = ft_putstr(str);
	else
	{
		diff = sp.width - (int)ft_strlen(str);
		pos = (char*)ft_memset(ft_strnew(diff), ' ', diff);
		if (sp.flag.minus)
			con = ft_strjoin(str, pos);
		else
			con = ft_strjoin(pos, str);
		diff = ft_putstr(con);
		free(con);
		free(pos);
	}
	if (is_alloc)
		free(str);
	return (diff);
}

extern	int		print_wstr(t_spec sp, wchar_t *wstr)
{
	wchar_t	*pos;
	wchar_t	*con;
	int		diff;
	int		is_alloc;

	if (!wstr)
		return (ft_putstr("(null)"));
	is_alloc = prec_wstr(&wstr, sp);
	if (sp.width <= (int)ft_wstrsize(wstr))
		diff = ft_putwstr(wstr);
	else
	{
		diff = sp.width - (int)ft_wstrsize(wstr);
		pos = (wchar_t*)ft_wstrset(ft_wstrnew(diff), L' ', diff);
		if (sp.flag.minus)
			con = ft_wstrjoin(wstr, pos);
		else
			con = ft_wstrjoin(pos, wstr);
		diff = ft_putwstr(wstr);
		free(con);
		free(pos);
	}
	if (is_alloc)
		free(wstr);
	return (diff);
}
