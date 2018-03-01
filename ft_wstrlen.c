#include "libft.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	i;

	i = 0;
	if (wstr != NULL)
	{
		while (wstr[i])
			i++;
	}
	return (i);
}
