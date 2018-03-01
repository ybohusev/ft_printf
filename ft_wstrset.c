#include "libft.h"

wchar_t	*ft_wstrset(wchar_t *b, int c, size_t n)
{
	wchar_t	*p;

	p = b;
	while (n--)
		*p++ = (unsigned char)c;
	return (b);
}
