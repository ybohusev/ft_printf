/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:28:13 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/06 09:50:44 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_spec sp, unsigned int ch)
{
	char	*tmp;
	int		pr;

	if (sp.width < 2)
		return (write(1, &ch, 1));
	tmp = (char*)ft_memset(ft_strnew(sp.width), ' ', sp.width);
	if (!sp.flag.minus)
		tmp[sp.width - 1] = ch;
	else
		tmp[0] = ch;
	pr = ft_putstr(tmp);
	if (ch == '\0')
	{
		ft_putchar(ch);
		pr++;
	}
	free(tmp);
	return (pr);
}

int		print_wchar(t_spec sp, unsigned int wch)
{
	int		octets;
	int		pr;

	octets = ft_count_octets(wch);
	if (sp.width <= octets)
		return (ft_putwchar(wch));
	pr = octets;
	while (pr <= sp.width)
	{
		if (!sp.flag.minus && pr == sp.width)
			ft_putwchar(wch);
		else if (sp.flag.minus && pr == octets)
			ft_putwchar(wch);
		else
			ft_putchar(' ');
		pr++;
	}
	return (pr - 1);
}
