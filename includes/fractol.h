/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/06 17:56:57 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/include/libft.h"
# include "../libmlx/includes/mlx.h"

# define D (double)
# define PI 3.14159265359
# define BG_CLR 0x3B3B3B
# define BG_DCLR 0x2D2D2D
# define UI_CLR 0xC0C0C0
# define UI_DCLR 0x647C15
# define OBJ_CLR 0x777777
# define PROG_NAME "fract'ol - bsouchet"
# define MIN_X v->minx
# define MIN_Y v->miny
# define MAX_X v->maxx
# define MAX_Y v->maxy
# define WIN_W 1280
# define WIN_H 720
# define MID_W 640
# define MID_H 360
# define MIN_J -3.20
# define MAX_J 3.200
# define DEFAULT_CLR 0x0F3241

# define MSG0 "usage: ./fractol (Julia / Mandelbrot / Tricorn)"
# define MSG1 "error: Window size must be greater than 1024 x 576."
# define MSG3 "\" isn't a valid fractal name."

typedef struct	s_var
{
	double		i;
	double		z;
	double		imax;
	double		padx;
	double		pady;
	int			e;
	int			x;
	int			y;
	int			sl;
	int			len;
	int			nbr;
	int			num;
	int			bpp;
	int			end;
	int			rot;
	int			clr;
	int			clr_frtl;
	int			m;
	char		*d;
	char		*nam;
	char		ftl[3][12];
	void		*img;
	void		*mlx;
	void		*win;
	long double	jr;
	long double	ji;
	long double	mr;
	long double mi;
	long double	zr;
	long double	zi;
	long double tmp;
	long double	mod;
	float		minx;
	float		miny;
}				t_var;

int				expose_hook(t_var *v);
int				key_hook(int keycode, t_var *v);
int				close_hook(int button, t_var *v);
int				mouse_hook(int button, int x, int y, t_var *v);
int				motion_hook(int x, int y, t_var *v);

int				put_pixel(t_var *v, int type);
void			draw_fractal(t_var *v);
void			user_interface(t_var *v);
void			user_interface_texts(t_var *v);

void			mlx_draw(t_var *v, int x, int y, int clr);

void			fractal_julia(t_var *v);
void			fractal_mandelbrot(t_var *v);
void			rotate_fractal(t_var *v, int rot);

#endif
