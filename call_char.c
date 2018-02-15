#include "ft_printf.h"

static	int		char_width(t_spec sp)
{
	int		i;

	i = 0;

	if (sp.width > 1)
	{
		while (i < sp.width - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}

extern	int		call_char(t_spec sp, unsigned int a)
{
	int		i;

	i = 0;
	if (!sp.flag.minus)
		i += char_width(sp);
	if (!sp.modifier && ft_strcmp(sp.type, "C"))
		i += ft_putchar(a);
	else if (!ft_strcmp(sp.modifier, "l") || !ft_strcmp(sp.type, "C"))
		i += ft_putwchar(a);
	if (sp.flag.minus)
		i += char_width(sp);
	return (i);
}