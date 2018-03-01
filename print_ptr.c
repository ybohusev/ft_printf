#include "ft_printf.h"

int		print_ptr(t_spec sp, void *ptr)
{
	char			*arg;
	char			*tmp;
	unsigned long	x;
	int				printed;

	x = (unsigned long)ptr;
	if (sp.flag.zero)
		sp.flag.zero = 0;
	arg = ft_itoa_base(x, 16);
	tmp = arg;
	arg = ft_strjoin("0x", arg);
	arg = width(sp, arg);
	printed = ft_putstr(arg);
	free(tmp);
	free(arg);
	return (printed);
}