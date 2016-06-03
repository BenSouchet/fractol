/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:52:08 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/03 12:54:29 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_random_color(void)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	while (42)
	{
		if ((r <= MIN_V && g <= MIN_V) || (r <= MIN_V && b <= MIN_V) ||
				(g <= MIN_V && b <= MIN_V))
		{
			r = ft_rand(0, 255);
			g = ft_rand(0, 255);
			b = ft_rand(0, 255);
		}
		else
			return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
	}
	return (0);
}
