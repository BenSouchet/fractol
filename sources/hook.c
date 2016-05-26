/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:35:58 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/26 18:33:46 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int		expose_hook(t_var *v)
{
	double mouloude;
	mouloude = (((WIN_W / 2) - (v->zoom * 2)) * ((-4.40 * 2) - 2)) / WIN_W;
	v->minx = (mouloude * 2.0) + 1.0;
	v->miny = 0;
	//v->maxx = 0.6;
	//v->maxy = 1.2;
	printf("%f --- %f\n", v->minx, v->maxx);
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	draw_fractal(v);
    //user_interface(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	//user_interface_texts(v);
	return (0);
}

int		key_hook(int keycode, t_var *v)
{
    int r;

    r = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else
	{
		if (keycode == 83 && v->num != 1 && ++r > 0)
			v->num = 1;
		else if (keycode == 84 && v->num != 2 && ++r > 0)
			v->num = 2;
		else if (keycode == 85 && v->num != 3 && ++r > 0)
			v->num = 3;
		else if ((keycode == 1 || keycode == 46) && v->m == UI_CLR && ++r > 0)
			v->m = UI_DCLR;
		else if ((keycode == 1 || keycode == 46) && v->m != UI_CLR && ++r > 0)
			v->m = UI_CLR;
		else if (keycode == 123 && ++r > 0)
			v->zoom -= 10;
		else if (keycode == 124 && ++r > 0)
			v->zoom += 10;
        if (r > 0)
        {
		    mlx_destroy_image(v->mlx, v->img);
		    mlx_clear_window(v->mlx, v->win);
		    expose_hook(v);
        }
	}
	return (0);
}

int		close_hook(int button, t_var *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}
