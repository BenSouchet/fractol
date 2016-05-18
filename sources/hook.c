/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:35:58 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/17 19:07:24 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int				expose_hook(t_var *v)
{
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	/*mettre le taf*/
    user_interface(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	user_interface_texts(v);
	return (0);
}

int				key_hook(int keycode, t_var *v)
{
    int redraw;

    redraw = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else
	{
		if (keycode == 83 && v->num != 1 && ++redraw > 0)
			v->num = 1;
		else if (keycode == 84 && v->num != 2 && ++redraw > 0)
			v->num = 2;
		else if (keycode == 85 && v->num != 3 && ++redraw > 0)
			v->num = 3;
		/*if (keycode >= 0 && keycode < 80)
			v = key_hook_rotate(v, keycode);
		else if (keycode > 110 && keycode < 130)
			v = key_hook_translate(v, keycode);*/
        if (redraw > 0)
        {
		    mlx_destroy_image(v->mlx, v->img);
		    mlx_clear_window(v->mlx, v->win);
		    expose_hook(v);
        }
	}
	return (0);
}

int				close_hook(int button, t_var *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}
