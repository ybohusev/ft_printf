#include "libft.h"

static	int		mas1(unsigned int a)
{
	unsigned char	ch;

	ch = a;
	write(1, &ch, 1);
	return (1);
}

static	int		mas2(unsigned int a, unsigned int mask)
{
	unsigned char	ch1;
	unsigned char	ch2;
	unsigned char	ch;

	ch2 = (a << 26) >> 26;
	ch1 = ((a >> 6) << 27) >> 27;
	ch = (mask >> 8) | ch1;
	write(1, &ch, 1);
	ch = (mask << 24) >> 24 | ch2;
	write(1, &ch, 1);
	return (2);
}

static	int		mas3(unsigned int a, unsigned int mask)
{
	unsigned char	ch1;
	unsigned char	ch2;
	unsigned char	ch3;
	unsigned char	ch;

	ch3 = (a << 26) >> 26;
	ch2 = ((a >> 6) << 26) >> 26;
	ch1 = ((a >> 12) << 28) >> 28;
	ch = (mask >> 16) | ch1;
	write(1, &ch, 1);
	ch = (mask << 16) >> 24 | ch2;
	write(1, &ch, 1);
	ch = (mask << 24) >> 24 | ch3;
	write(1, &ch, 1);
	return (3);
}

static	int		mas4(unsigned int a, unsigned int mask)
{
	unsigned char	ch1;
	unsigned char	ch2;
	unsigned char	ch3;
	unsigned char	ch4;
	unsigned char	ch;

	ch4 = (a << 26) >> 26;
	ch3 = ((a >> 6) << 26) >> 26;
	ch2 = ((a >> 12) << 26) >> 26;
	ch1 = ((a >> 18) << 29) >> 29;
	ch = (mask >> 24) | ch1;
	write(1, &ch, 1);
	ch = (mask << 8) >> 24 | ch2;
	write(1, &ch, 1);
	ch = (mask << 16) >> 24 | ch3;
	write(1, &ch, 1);
	ch = (mask << 24) >> 24 | ch4;
	write(1, &ch, 1);
	return (4);
}

extern	int		ft_putwchar(unsigned int a)
{
	int				bits;
	
	bits = (int)ft_strlen(ft_itoa_base(a, 2));
	if (bits <= 7)
		return(mas1(a));
	if (bits > 7 && bits <= 11)
		return(mas2(a, 49280));
	if (bits > 11 && bits <= 16)
		return(mas3(a, 14712960));
	if (bits > 16)
		return(mas4(a, 4034953344));
	return (0);
}
