/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:52:08 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/07 18:14:56 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_hsv		ft_random_color(void)
{
	t_hsv	hsv;
	t_rgb	rgb;

	hsv.h = ((double)ft_rand(0, 3600) / 10.0);
	hsv.s = ((double)ft_rand(600, 900) / 1000.0);
	hsv.v = ((double)ft_rand(600, 900) / 1000.0);
	return (hsv);
}
