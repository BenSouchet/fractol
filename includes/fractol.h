/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/17 19:09:39 by bsouchet         ###   ########.fr       */
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
# define WIN_W 1280
# define WIN_H 720

# define MSG00 "usage: ./fractol fractal_name"
# define MSG01 "error: Window size must be greater than 1024 x 576"
# define MSG03 " isn't a valid fractal name\n"

typedef struct	s_var
{
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
}				t_var;

int				expose_hook(t_var *v);
int				key_hook(int keycode, t_var *v);
int				close_hook(int button, t_var *v);

int				put_pixel(t_var *v, int color, int type);
t_var			*user_interface(t_var *v, int type);
void			user_interface_texts(t_var *v);

void			mlx_draw(t_var *v, int x, int y);

#endif
