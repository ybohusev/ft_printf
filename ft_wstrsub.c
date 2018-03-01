#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*sub;
	size_t	i;

	i = 0;
	sub = (wchar_t*)malloc(sizeof(wchar_t) * (len + 1));
	if (sub == NULL || s == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}