#include <stdio.h>
#include <math.h>

typedef struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct	s_percent
{
	double		r;
	double		g;
	double		b;
}				t_percent;

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

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

t_rgb		ft_hsv_to_rgb(t_hsv hsv)
{
	t_rgb	rgb;
	double	p;
	double	q;
	double	t;

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

int		main(void)
{
	t_hsv	hsv;
	t_rgb	rgb;

	hsv = ft_hex_to_hsv(0x84AD00);
	hsv.h += (((360.0 / 50) * 1));
	hsv.v += (((1.0 - hsv.v) / 50) * 1);
	while (hsv.h < 0.)
		hsv.h += 360.;
	while (hsv.h >= 360.)
		hsv.h -= 360.;
	rgb = ft_hsv_to_rgb(hsv);
	printf("%f --- %f ---%f\n", rgb.r, rgb.g, rgb.b);
	return (0);
}
