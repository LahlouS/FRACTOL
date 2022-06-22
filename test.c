#include <stdio.h>
#include <stdlib.h>

double	ft_strtod(const char *nptr)
{
	double	res;
	double	sign;
	double	nb_dec;

	res = 0;
	nb_dec = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13) || *nptr == '+')
		nptr++;
	sign = ((*nptr == '-') * -1) + (*nptr != '-');
	nptr += (*nptr == '-');
	while (*nptr <= '9' && *nptr >= '0')
	{
		res = res * 10 + ((*nptr) - 48);
		nptr++;
	}
	nptr += (*nptr == '.');
	while (*nptr <= '9' && *nptr >= '0')
	{
		res = res * 10 + ((*nptr) - 48);
		nb_dec *= 10;
		nptr++;
	}
	return ((res * sign) / nb_dec);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(void)
{
	printf("%ld\n", ft_strlen("conseil: pour les configurations de julia,\
	 les nombres entre doivent etre de la forme decimal, entre 2.000 et 2.000\n"));
	return (0);
}