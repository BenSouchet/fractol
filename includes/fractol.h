/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/19 16:25:53 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/include/libft.h"
# include "../libmlx/includes/mlx.h"

# define PI 3.14159265359
# define BG_COLOR 0x353535
# define BG2_COLOR 0x2D2D2D
# define UI_COLOR 0x84AC00
# define UI2_COLOR 0x647C15
# define PROG_NAME "fract'ol - bsouchet"
# define MIN_X v->minx
# define MIN_Y v->miny
# define MAX_X v->maxx
# define MAX_Y v->maxy
# define WIN_W 1280
# define WIN_H 720

# define MSG00 "usage: ./fractol fractal_name"
# define MSG01 "error: Window size must be greater than 1024 x 576"
# define MSG03 " isn't a valid fractal name\n"

typedef struct	s_var
{
	int			i;
	int			imax;
	int			x;
	int			y;
	int			sl;
	int			len;
	int			nbr;
	int			num;
	int			bpp;
	int			end;
	char		*d;
	char		*nam;
	char		ftl[3][12];
	void		*img;
	void		*mlx;
	void		*win;
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double tmp;
	float		minx;
	float		miny;
	float		maxx;
	float		maxy;
}				t_var;

int				expose_hook(t_var *v);
int				key_hook(int keycode, t_var *v);
int				close_hook(int button, t_var *v);

int				put_pixel(t_var *v, int color, int type);
void			draw_fractal(t_var *v);
void			user_interface(t_var *v);
void			user_interface_texts(t_var *v);

void			mlx_draw(t_var *v, int x, int y);

void			fractal_julia(t_var *v);
void			fractal_mandelbrot(t_var *v, long double mod);
void			fractal_troisieme(t_var *v);

#endif
