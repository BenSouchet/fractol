/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:42:55 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/03 12:57:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_shade_color(int clr, double val)
{
	int r;
	int g;
	int b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr >> 16) & 0xFF) - D(D((clr >> 16) & 0xFF) * val));
	g = floor(D((clr >> 8) & 0xFF) - D(D((clr >> 8) & 0xFF) * val));
	b = floor(D((clr) & 0xFF) - D(D((clr) & 0xFF) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
