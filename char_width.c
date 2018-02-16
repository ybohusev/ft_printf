#include "ft_printf.h"

int		char_width(t_spec sp, int bytes)
{
	int		i;

	i = 0;
	if (sp.width > bytes)
	{
		while (i < sp.width - bytes)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}