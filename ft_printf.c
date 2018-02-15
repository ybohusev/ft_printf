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
#include <locale.h>

static	int		parse(t_spec sp, va_list ap)
{
	if (!ft_strcmp(sp.type, "d") || !ft_strcmp(sp.type,"i")
		|| !ft_strcmp(sp.type, "D"))
		return (work_with_dec(sp, ap));
	else if (!ft_strcmp(sp.type, "o") || !ft_strcmp(sp.type,"u")
		|| !ft_strcmp(sp.type, "x") || !ft_strcmp(sp.type, "O")
		|| !ft_strcmp(sp.type,"U") || !ft_strcmp(sp.type, "X"))
		return (work_with_uns(sp, ap));
	else if (!ft_strcmp(sp.type, "c") || !ft_strcmp(sp.type,"C"))
		return (work_with_char(sp, ap));
	return (0);
}

static	t_spec	separate_specifiers(char *specifiers)
{
	t_spec	spec;

	spec.flag = get_flag(&specifiers);
	spec.width = get_width(&specifiers);
	spec.precision = get_precision(&specifiers);
	spec.modifier = get_modifier(&specifiers);
	spec.type = get_type(&specifiers);
	return (spec);
}

static	t_spec	get_specifiers(char **format, char *type)
{
	int		count;
	char	*spec;
	t_spec	sep_spec;
	int		i;

	count = 1;
	while ((*format)[count])
	{
		i = 0;
		while (type[i])
		{
			if ((*format)[count] == type[i])
				break ;
			i++;
		}
		if ((*format)[count] == type[i])
			break ;
		count++;
	}
	spec = ft_strsub(*format, 1, count);
	sep_spec = separate_specifiers(spec);
	free(spec);
	*format += count;
	return (sep_spec);
}

static	int		common(char **format, va_list ap)
{
	t_spec	specifiers;
	int		count;

	count = 0;
	specifiers = get_specifiers(format, "sSpdDioOuUxXcC");
	count = parse(specifiers, ap);
	return (count);
}

extern	int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			format++;
			ft_putchar('%');
			printed++;
		}
		else if (*format == '%')
			printed += common((char**)&format, ap);
		else
		{
			ft_putchar(*format);
			printed++;
		}
		format++;
	}
	va_end(ap);
	return (printed);
}

int		main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int 	i;

	i = ft_printf("%lcq\n", L'。');
	printf("%d\n", i);
	i = printf("%lcq\n", L'。');
	printf("%d\n", i);
	return 0;
}