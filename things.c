#include "fractol.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr && !(*nptr >= '0' && *nptr <= '9'))
		nptr++;
	while (*nptr <= '9' && *nptr >= '0')
	{
		res = res * 10 + ((*nptr) - 48);
		nptr++;
	}
	return (res * sign);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	return (0);
}

int ft_check_error(int ac, char **av)
{
    if (ac == 2 && !(ft_strncmp(*(av + 1), "mandelbrot", 65)))
        return (0);
    if (ac == 4 && !(ft_strncmp(*(av + 1), "julia1", 65)) && (ft_strncmp(*(av + 2), "0", 65)))
        return (0);
    ft_man();
    return (1);
}

void ft_man(void)
{
    if (write(1, "\n\tERREUR ARGUMENTS ENTRE\n\n-->liste des arguments valides:\n", 58))
        ;
    if (write(1, ">\tmandelbrot\n>\tjulia1 reel_param imaginaire_param\n\n", 51))
        ;
    if (write(1, "\t-->ex: ./fractol julia1 0.3 0.5\n", 33))
        ;
    if (write(1, "\t-->ex: ./fractol mandelbrot\n\n", 30))
        ;
} 