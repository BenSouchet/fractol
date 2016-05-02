/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:23:53 by bsouchet          #+#    #+#             */
/*   Updated: 2016/04/12 15:25:03 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rand(int min, int max)
{
	int i;
	int cpy;
	int num;
	int	res;

	i = 0;
	res = 0;
	num = (long)malloc(sizeof(long));
	if (num < 0)
		num = -num;
	cpy = num;
	while (num >= 10)
	{
		res += (num % 10);
		num = num / 10;
		i++;
	}
	res = res * 17 + cpy + i;
	res = (res % (max + 1)) + min;
	return (res);
}
