#include "ft_printf.h"

static	int		zero(char *arg, t_spec sp)
{
	int		i;

	i = 1;
	if (sp.flag.minus)
		ft_putchar('+');
	while (i < sp.width)
	{
		ft_putchar(' ');
		i++;
	}
	if (!sp.flag.minus)
		ft_putchar('+');
	return (sp.width);
}

extern	int		call_int(t_spec sp, int a)
{
	char	*arg;
	int		printed;
	char	*tmp;

	printed = 0;
	if (a < 0)
		arg = ft_itoa(a * -1);
	else
		arg = ft_itoa(a);
	arg = precis(arg, sp);
	tmp = arg;
	arg = width(sp, arg);
	arg = sign_int(arg, tmp, sp, a);
	if (sp.precision == 0 && a == 0)
		printed = zero(arg, sp);
	else
		printed = ft_putstr(arg);
	free(arg);
	return(printed);
}
