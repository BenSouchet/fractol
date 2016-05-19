/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:30:09 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/19 16:53:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int		error(int type)
{
	if (type == 0)
		write(2, MSG00, 29);
	else if (type == 1)
		write(2, MSG01, 51);
	else if (type == 2)
		;
	write(2, "\n", 1);
	return (-1);
}

static int		check(t_var *v, char **av, int err)
{
	char	*str;

	ft_cpy("Julia\0", v->ftl[0]);
	ft_cpy("Mandelbrot\0", v->ftl[1]);
	ft_cpy("Troisieme\0", v->ftl[2]);
	if (ft_strcmp(av[1], "Julia") == 0 ||
		ft_strcmp(av[1], "julia") == 0)
		v->num = 1;
	else if (ft_strcmp(av[1], "Mandelbrot") == 0 ||
		ft_strcmp(av[1], "mandelbrot") == 0)
		v->num = 2;
	else if (ft_strcmp(av[1], "Troisieme") == 0 ||
		ft_strcmp(av[1], "troisieme") == 0)
		v->num = 3;
	else
	{
		str = ft_strjoin2(ft_strjoin("error : ", av[1]), MSG03, 0);
		write(2, str, ft_strlen(str));
		free(str);
		err++;
	}
	return (err);
}

static void		init_win(t_var *v)
{
	v->imax = 50;
	v->minx = -2.1;
	v->miny = -1.2;
	v->maxx = 0.6;
	v->maxy = 1.2;
	v->minx -= ((MAX_X - MIN_X) / WIN_W) * 440; //
	v->maxx -= ((MAX_X - MIN_X) / WIN_W) * 440; //
	v->mlx = mlx_init();
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->win = mlx_new_window(v->mlx, -1, -1, WIN_W, WIN_H, PROG_NAME);
	v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	mlx_expose_hook(v->win, expose_hook, v);
	mlx_hook(v->win, 17, 0, close_hook, v);
	mlx_hook(v->win, 2, 0, key_hook, v);
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
		return (error(0));
	else if (WIN_W < 1024 || WIN_H < 576)
		return (error(1));
	else if (check(v, av, 0) > 0)
		return (-1);
	else
		init_win(v);
	return (0);
}
