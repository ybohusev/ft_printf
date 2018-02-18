/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:28:13 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/18 15:28:14 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_spec sp, unsigned int ch)
{
	if (!sp.width)
	{
		ft_putchar(ch);
		return(1);
	}
	return(0);
}
int		print_wchar(t_spec sp, unsigned int wch)
{
	ft_putwchar(wch);
	return (sp.width);
}
