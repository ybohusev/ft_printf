#include "ft_printf.h"

size_t		ft_wstrsize(wchar_t *wstr)
{
	size_t	i;
	size_t	prt;

	i = 0;
	prt = 0;
	if (wstr != NULL)
	{
		while (wstr[i])
		{
			prt += ft_count_octets(wstr[i]);
			i++;
		}
	}
	return (prt);
}
