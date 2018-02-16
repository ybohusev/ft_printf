/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:46:35 by ybohusev          #+#    #+#             */
/*   Updated: 2018/02/16 10:46:37 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_symbol(char *ch, t_spec sp)
{
	int		bytes;

	bytes = 0;
	sp.width++;
	bytes = ft_putstr(ch);
	return (bytes);
}
