/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:43:14 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/03 16:22:13 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_dx(t_env *data, t_pos *start, int dx, int dy)
{
	int cumul;
	int i;
	int xinc;
	int yinc;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	cumul = dx / 2;
	i = 1;
	while (i <= dx)
	{
		start->x = start->x + xinc;
		cumul = cumul + dy;
		if (cumul >= dx )
		{
			cumul = cumul - dx;
			start->y = start->y + yinc;
		}
		mlx_pixel_put(data->mlx, data->win, start->x, start->y, 0xFF00FF);
		i++;
	}
}

void	draw_dy(t_env *data, t_pos *start, int dx, int dy)
{
	int cumul;
	int i;
	int xinc;
	int yinc;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	i = 1;
	cumul = dy / 2;
	while (i <= dy)
	{
		start->y = start->y + yinc;
		cumul = cumul + dx;
		if (cumul >= dy)
		{
			cumul = cumul - dy;
			start->x = start->x + xinc;
		}
		mlx_pixel_put(data->mlx, data->win, start->x, start->y, 0xFF00FF);
		i++;
	}
}

void	draw(t_env *data, t_pos *start, t_pos *destination)
{
	int dx;
	int dy;

	dx = destination->x - start->x;
	dy = destination->y - start->y;
	mlx_pixel_put(data->mlx, data->win , start->x, start->y, 0xFF0000);
	if ( abs(dx) > abs(dy) )
		draw_dx(data, start, dx, dy);
	else
		draw_dy(data, start, dx, dy);
}
