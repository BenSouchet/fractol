/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:44:25 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/20 15:44:58 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gradient_color(int clr1, int clr2, double val)
{
	int r;
	int g;
	int b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr1 >> 16) & 0xFF) -
	((D((clr1 >> 16) & 0xFF) - D((clr2 >> 16) & 0xFF)) * val));
	g = floor(D((clr1 >> 8) & 0xFF) -
	((D((clr1 >> 8) & 0xFF) - D((clr2 >> 8) & 0xFF)) * val));
	b = floor(D((clr1) & 0xFF) -((D((clr1) & 0xFF) - D((clr2) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
