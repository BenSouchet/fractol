/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:30:09 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/06 17:56:39 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int		error(int type, char **av)
{
	char *str;

	if (type == 0)
		write(2, MSG0, ft_strlen(MSG0));
	else if (type == 1)
		write(2, MSG1, ft_strlen(MSG1));
	else if (type == 2)
	{
		str = ft_strjoin2(ft_strjoin("error : \"", av[1]), MSG3, 0);
		write(2, str, ft_strlen(str));
		write(2, "\n", 2);
		write(2, MSG0, ft_strlen(MSG0));
		free(str);
	}
	write(2, "\n", 1);
	return (-1);
}

static int		check(t_var *v, char **av)
{
	ft_cpy("Julia\0", v->ftl[0]);
	ft_cpy("Mandelbrot\0", v->ftl[1]);
	ft_cpy("Tricorn\0", v->ftl[2]);
	if (ft_strcmp(av[1], "Julia") == 0 ||
		ft_strcmp(av[1], "julia") == 0)
		v->num = 1;
	else if (ft_strcmp(av[1], "Mandelbrot") == 0 ||
			ft_strcmp(av[1], "mandelbrot") == 0)
		v->num = 2;
	else if (ft_strcmp(av[1], "Tricorn") == 0 ||
			ft_strcmp(av[1], "tricorn") == 0)
		v->num = 3;
	else
		return (1);
	return (0);
}

static void		assign(t_var *v)
{
	v->e = 0;
	v->rot = 0;
	v->z = 170.0;
	v->padx = 0.0;
	v->pady = 0.0;
	v->imax = 50.0;
	v->jr = -1.1380;
	v->ji = 0.2403;
	v->m = ft_shade_color(UI_CLR, 0.45);
	v->clr_frtl = DEFAULT_CLR;
}

static void		init_win(t_var *v)
{
	assign(v);
	v->mlx = mlx_init();
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->win = mlx_new_window(v->mlx, -1, -1, WIN_W, WIN_H, PROG_NAME);
	v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	mlx_expose_hook(v->win, expose_hook, v);
	mlx_hook(v->win, 6, 64, motion_hook, v);
	mlx_hook(v->win, 17, 0, close_hook, v);
	mlx_hook(v->win, 2, 0, key_hook, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_do_key_autorepeaton(v->mlx);
	mlx_loop(v->mlx);
	exit(0);
}

int				main(int ac, char **av)
{
	t_var *v;

	v = (t_var *)malloc(sizeof(t_var));
	v->nbr = ac;
	if (ac != 2)
		return (error(0, av));
	else if (WIN_W < 1024 || WIN_H < 576)
		return (error(1, av));
	else if (check(v, av) > 0)
		return (error(2, av));
	else
		init_win(v);
	return (0);
}
