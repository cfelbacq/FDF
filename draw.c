/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:43:14 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/11 15:56:15 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "fdf.h"

static	int		Round(float x)
{
	x = x + 0.5;
	return ((int)x);
}

void	draw(t_env *data, t_pos *start, t_pos *destination)
{
	int i;
	int x;
	int y;
	float m;
	int dx;
	int dy;

	i = 0;
	x = 0;
	y = 0;
	dy = destination->y - start->y;
	dx = destination->x - start->x;
	m = ((float)dy / (float)dx);
	while (i < dx)
	{
		i++;
		x = start->x + i;
		y = Round(start->y + m * i);
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
	}
}
