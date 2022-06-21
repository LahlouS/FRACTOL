/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:00:36 by slahlou           #+#    #+#             */
/*   Updated: 2022/06/21 16:00:38 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	matrix(int i, int prec)
{
	if (i == prec)
		return (0x0D0208);
	else if (i < prec && i > 200)
		return (0x00FF41);
	else if (i <= 200 && i > 80)
		return (0x00FF41);
	else if (i <= 80 && i > 40)
		return (0x008711);
	else if (i <= 40 && i > 20)
		return (0xFFFFFF);
	else if (i <= 20 && i > 17)
		return (0x003B00);
	else if (i <= 17 && i > 14)
		return (0x008711);
	else if (i <= 14 && i > 13)
		return (0x00FF41);
	else if (i <= 13 && i > 11)
		return (0x0D0208);
	else if (i <= 11 && i > 9)
		return (0x003B00);
	else if (i <= 9 && i > 8)
		return (0x008711);
	else
		return (0x0D0208);
}

int	cyber_punk(int i, int prec)
{
	if (i == prec)
		return (0x0D0208);
	else if (i < prec && i > 200)
		return (0xFF2CDF);
	else if (i <= 200 && i > 80)
		return (0xFCD07A);
	else if (i <= 80 && i > 40)
		return (0x1200FF);
	else if (i <= 40 && i > 20)
		return (0x00FF5B);
	else if (i <= 20 && i > 17)
		return (0xFF0A6C);
	else if (i <= 17 && i > 14)
		return (0x2D27FF);
	else if (i <= 14 && i > 13)
		return (0xFFE53B);
	else if (i <= 13 && i > 11)
		return (0x00FF5B);
	else if (i <= 11 && i > 9)
		return (0x00E1FD);
	else if (i <= 9 && i > 8)
		return (0xFF00A0);
	else
		return (0x0D0208);
}

int	retro(int i, int prec)
{
	if (i == prec)
		return (0x8DB4AD);
	else if (i < prec && i > 100)
		return (0xE9311A);
	else if (i <= 100 && i > 50)
		return (0xECAE7D);
	else if (i <= 50 && i > 20)
		return (0xED6335);
	else if (i <= 20 && i > 15)
		return (0x026C80);
	else if (i <= 15 && i > 14)
		return (0x064C72);
	else if (i <= 14 && i > 13)
		return (0x026C80);
	else if (i <= 13 && i > 12)
		return (0x984900);
	else if (i <= 12 && i > 11)
		return (0x434A16);
	else if (i <= 11 && i > 9)
		return (0x00E1FD);
	else if (i <= 9 && i > 8)
		return (0xBA8F2A);
	else
		return (0xB9A68A);
}

int	black_white(int i, int prec)
{

	if (i == prec)
		return (0x0D0208);
	else if (i < prec && i > 100)
		return (0xFFFFFF);
	else if (i <= 100 && i > 30)
		return (0x040273);
	else if (i <= 30 && i > 20)
		return (0x530000);
	else if (i <= 20 && i > 13)
		return (0x8944EA);
	else
		return (0xFFFFFF);
}

int	dont_know(int i, int prec)
{
	if (i == prec)
		return (0x0D1208);
	else if (i < prec && i > 200)
		return (0x10FF41);
	else if (i <= 200 && i > 80)
		return (0x00FF41);
	else if (i <= 80 && i > 40)
		return (0x006711);
	else if (i <= 40 && i > 20)
		return (0xFF0FFF);
	else if (i <= 20 && i > 17)
		return (0xEE3B00);
	else if (i <= 17 && i > 14)
		return (0x008711);
	else if (i <= 14 && i > 13)
		return (0x00AF81);
	else if (i <= 13 && i > 11)
		return (0x0D0D08);
	else if (i <= 11 && i > 9)
		return (0xAA3B00);
	else if (i <= 9 && i > 8)
		return (0xD08711);
	else
		return (0x041273);
}