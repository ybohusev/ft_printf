#include "ft_printf.h"

static	char	*space_plus(char *arg, t_spec sp)
{
	char	*tmp;

	tmp = arg;
	if (sp.flag.plus)
		arg = ft_strjoin("+", arg);
	else if (sp.flag.space)
		arg = ft_strjoin(" ", arg);
	free(tmp);
	return (arg);
}

static	char	*precis(char *arg, int ze, int a)
{
	char	*tmp;
	int		diff;
	char	*zeros;

	tmp = arg;
	if (a < 0)
		arg++;
	diff = ze - (int)ft_strlen(arg);
	zeros = (char*)ft_memset(ft_strnew(diff), '0', diff);
	arg = ft_strjoin(zeros, arg);
	free(zeros);
	free(tmp);
	if (a < 0)
	{
		tmp = arg;
		arg = ft_strjoin("-", arg);
		free(tmp);
	}
	return (arg);
}

static	char	*width(t_spec sp, char *arg, int a)
{
	char	*pos;
	char	*tmp;
	int		diff;

	tmp = arg;
	diff = sp.width - (int)ft_strlen(arg);
	pos = (char*)ft_memset(ft_strnew(diff), ' ', diff);
	if (sp.flag.minus)
		arg = ft_strjoin(arg, pos);
	else
		arg = ft_strjoin(pos, arg);
	free(tmp);
	free(pos);
	return (arg);
}

static	int		zero(t_spec sp, char *arg)
{
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	if (sp.flag.minus)
	{
		if (sp.flag.plus)
			ft_putchar('+');
		while (i < sp.width - sp.flag.plus)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (!sp.flag.minus)
	{
		while (i < sp.width - sp.flag.plus)
		{
			ft_putchar(' ');
			i++;
		}
		if (sp.flag.plus)
			ft_putchar('+');
	}
	return (sp.width);
}

extern	int		call_int(t_spec sp, int a)
{
	char	*arg;
	int		printed;

	printed = 0;
	arg = ft_itoa(a);
	if (sp.precision > (int)ft_strlen(arg + 1))
		arg = precis(arg, sp.precision, a);
	if ((sp.flag.plus || sp.flag.space) && a >= 0)
		arg = space_plus(arg, sp);
	if (!sp.flag.minus && sp.flag.zero &&
		sp.width > (int)ft_strlen(arg))
	{
		if (a < 0)
			arg = precis(arg, sp.width - 1, a);
		else
			arg = precis(arg, sp.width, a);
	}
	else if (sp.width > (int)ft_strlen(arg))
		arg = width(sp, arg, a);
	if (sp.precision == 0 && a == 0)
		printed = zero(sp, arg);
	else
		printed = ft_putstr(arg);
	free(arg);
	return(printed);
}
