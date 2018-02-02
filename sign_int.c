#include "ft_printf.h"

static	char	*change_ch(char *arg, t_spec sp, int a)
{
	int		i;

	i = 0;
	while (!ft_isdigit(arg[i + 1]))
		i++;
	if (a < 0)
		arg[i] = '-';
	else if (sp.flag.plus)
		arg[i] = '+';
	else if (sp.flag.space)
		arg[i] = ' ';
	return (arg);
}

static	char	*add_ch(char *arg, t_spec sp, int a)
{
	char	*tmp;

	tmp = arg;
	if (a < 0)
		arg = ft_strjoin("-", arg);
	else if (sp.flag.plus)
		arg = ft_strjoin("+", arg);
	else if (sp.flag.space)
		arg = ft_strjoin(" ", arg);
	free(tmp);
	return (arg);
}

static	char	*change_ch_l(char *arg, t_spec sp, int a)
{
	int		i;

	i = 0;
	while (ft_isdigit(arg[i]))
		i++;
	while(i != 0)
	{
		arg[i] = arg[i - 1];
		i--;
	}
	if (a < 0)
		arg[0] = '-';
	else if (sp.flag.plus)
		arg[0] = '+';
	else if (sp.flag.space)
		arg[0] = ' ';
	return (arg);
}

extern	char	*sign_int(char *arg, char *tmp, t_spec sp, int a)
{
	if (sp.width > (int)ft_strlen(tmp) && !sp.flag.minus)
		arg = change_ch(arg, sp, a);
	else if (sp.flag.minus && sp.width > (int)ft_strlen(tmp))
		arg = change_ch_l(arg, sp, a);
	else if (a < 0 || sp.flag.plus || sp.flag.space)
		arg = add_ch(arg, sp, a);
	return (arg);
}