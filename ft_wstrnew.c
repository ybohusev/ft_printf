#include "libft.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*newstr;
	size_t	i;

	i = 0;
	newstr = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	if (newstr == NULL)
		return (NULL);
	while (i <= size)
		newstr[i++] = '\0';
	return (newstr);
}
