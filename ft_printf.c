/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:16 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/22 14:39:17 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*get_specifiers(char **format)
{
	char	*type;
	int		count;
	char	*spec;
	int		i;

	type = "sSpdDioOuUxXcC";
	count = 0;
	while (*format[count])
	{
		i = 0;
		while (type[i])
		{
			if (*format[count] == type[i])
				break ;
			i++;
		}
		count++;
	}
	spec = ft_strsub(*format, 1, count);
	*format += count + 1;
	return (spec);
}

static	void	parse(char **format, va_list ap)
{
	char	*specifiers;
	char	*type;

	specifiers = get_specifiers(format);
}

extern	int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			parse(%format);
		else
			ft_putchar(*format);
		format++;
	}

}
