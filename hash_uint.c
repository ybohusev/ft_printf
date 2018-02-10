#include "ft_printf.h"

static	char	*hash_oct(char *arg, t_spec sp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = arg;
	while (!ft_isdigit(arg[i]))
		i++;
	if (sp.flag.minus && arg[i] != '0')
	{
		while (ft_isdigit(arg[i]))
			i++;
		while(i != 0)
		{
			arg[i] = arg[i - 1];
			i--;
		}
		arg[i] = '0';	
	}
	else if (!i && arg[i] != '0')
	{
		arg = ft_strjoin("0", arg);
		free(tmp);
	}
	else if (arg[i] != '0')
		arg[i - 1] = '0';
	return (arg);
}

static	char	*add_0x(char *arg, int space, int zero)
{

}

static	char	*hash_hex(char *arg, t_spec sp)
{
	
}

extern	char	*hash_uint(char *arg, t_spec sp)
{
	if (!ft_strcmp(sp.type, "o") ||
		!ft_strcmp(sp.type, "O"))
		arg = hash_oct(arg, sp);
	if (!ft_strcmp(sp.type, "x") ||
		!ft_strcmp(sp.type, "X"))
		arg = hash_hex(arg, sp);

	return (arg);
}
