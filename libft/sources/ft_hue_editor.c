/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hue_editor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 18:01:39 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/06 18:49:58 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_min(double num1, double num2)
{
	if (num1 <= num2)
		return (num1);
	return (num2);
}

static double	ft_max(double num1, double num2)
{
	if (num1 >= num2)
		return (num1);
	return (num2);
}

t_percent		ft_hex_to_percent(int hex)
{
	t_percent	percent;
	percent.r = ((double)((hex >> 16) & 0xFF) / 255.0);
	percent.g = ((double)((hex >> 8) & 0xFF) / 255.0);
	percent.b = ((double)((hex) & 0xFF) / 255.0);
	return (percent);
}

t_hsv			ft_hex_to_hsv(int hex)
{
	t_hsv		hsv;
	t_percent	percent;
	double		min;
	double		delta;

	percent = ft_hex_to_percent(hex);
	min = ft_min(ft_min(percent.r, percent.b), percent.b);
	hsv.v = ft_max(ft_max(percent.r, percent.g), percent.b);
	delta = hsv.v - min;
	if (hsv.v != 0.0)
		hsv.s = delta / hsv.v;
	else
		hsv.s = 0.0;
	if (hsv.s == 0.0)
		hsv.h = 0.0;
	else if (hsv.v == percent.r)
		hsv.h = (percent.g - percent.b) / delta;
	else if (hsv.v == percent.g)
		hsv.h = 60.0 * (((percent.b - percent.r) / delta) + 2.0);
	else if (hsv.v == percent.b)
		hsv.h = 60.0 * (((percent.r - percent.g) / delta) + 4.0);
	hsv.h += (hsv.s != 0.0 && hsv.h < 0.0) ? 360.0 : 0.0;
	return (hsv);
}

int				ft_hsv_to_hex(t_hsv hsv)
{
	(void)hsv;
	return (0x84AD00);
}
