/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hue_editor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 18:01:39 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/07 19:27:47 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_percent		ft_rgb_to_percent(t_rgb rgb)
{
	t_percent	percent;

	percent.r = ((double)rgb.r / 255.);
	percent.g = ((double)rgb.g / 255.);
	percent.b = ((double)rgb.b / 255.);
	return (percent);
}

t_rgb			ft_hex_to_rgb(int hex)
{
	t_rgb		rgb;

	rgb.r = (((hex >> 16) & 0xFF) / 255.);
	rgb.g = (((hex >> 8) & 0xFF) / 255.);
	rgb.b = (((hex) & 0xFF) / 255.);
	return (rgb);
}

t_rgb			ft_hsv_to_rgb(t_hsv hsv)
{
	t_rgb		rgb;
	double		p;
	double		q;
	double		t;

	(hsv.h == 360.) ? (hsv.h = 0.) : (hsv.h /= 60.);
	p = hsv.v * (1. - hsv.s);
	q = hsv.v * (1. - (hsv.s * (hsv.h - floor(hsv.h))));
	t = hsv.v * (1. - (hsv.s * (1. - (hsv.h - floor(hsv.h)))));
	rgb = (t_rgb){.r = 0., .g = 0., .b = 0.};
	if (hsv.s == 0.)
		rgb = (t_rgb){.r = hsv.v, .g = hsv.v, .b = hsv.v};
	else if (0. <= hsv.h && hsv.h < 1.)
		rgb = (t_rgb){.r = hsv.v, .g = t, .b = p};
	else if (1. <= hsv.h && hsv.h < 2.)
		rgb = (t_rgb){.r = q, .g = hsv.v, .b = p};
	else if (2. <= hsv.h && hsv.h < 3.)
		rgb = (t_rgb){.r = p, .g = hsv.v, .b = t};
	else if (3. <= hsv.h && hsv.h < 4.)
		rgb = (t_rgb){.r = p, .g = q, .b = hsv.v};
	else if (4. <= hsv.h && hsv.h < 5.)
		rgb = (t_rgb){.r = t, .g = p, .b = hsv.v};
	else if (5. <= hsv.h && hsv.h < 6.)
		rgb = (t_rgb){.r = hsv.v, .g = p, .b = q};
	return (rgb);
}

int				ft_rgb_to_hex(t_rgb rgb)
{
	int			r;
	int			g;
	int			b;

	r = (int)(rgb.r * 255.0);
	g = (int)(rgb.g * 255.0);
	b = (int)(rgb.b * 255.0);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
