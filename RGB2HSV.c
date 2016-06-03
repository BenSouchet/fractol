#include <stdio.h>

double	ft_min(double n1, double n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}

double	ft_max(double n1, double n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

void	hexa_to_hsv(int clr)
{
	double h; // Hue of HSV
	double s; // Saturation of HSV
	double v; // Value of HSV
	double r; // Red of RGB
	double g; // Green of RGB
	double b; // Blue of RGV
	double min; // Min Value
	double delta; // Delta Value

	r = (double)((clr >> 16) & 0xFF) / 255.0;
	g = (double)((clr >> 8) & 0xFF) / 255.0;
	b = (double)((clr) & 0xFF) / 255.0;	
	min = ft_min(ft_min(r, b), b);
	v = ft_max(ft_max(r, g), b);
	delta = v - min;
	if (v != 0.0)
		s = delta / v;
	else
		s = 0.0;
	if (s == 0.0)
		h = 0.0;
	if (v == r)
		h = (g - b) / delta;
	else if (v == g)
		h = 60.0 * (((b - r) / delta) + 2.0);
	else
		h = 60.0 * (((r - g) / delta) + 4.0);
	h += (h < 0) ? 360 : 0;
	//printf("r : %f --- g : %f --- b : %f\n", r, g, b);
	//printf("h : %f --- s : %f --- v : %f\n", h, s, v);
}

int		main(void)
{
	hexa_to_hsv(0x84AD00);
	return (0);
}
