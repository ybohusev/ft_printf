#include "libft.h"

int		ft_count_octets(unsigned int a)
{
	int				bits;
	
	bits = (int)ft_strlen(ft_itoa_base(a, 2));
	if (bits <= 7)
		return(1);
	else if (bits <= 11)
		return(2);
	else if (bits <= 16)
		return(3);
	else if (bits > 16)
		return(4);
	return (0);
}
