/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:18:23 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/12 14:35:25 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

void	free_draw(t_env *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->win_height)
	{
		j = 0;
		while (j < data->win_width)
		{
			mlx_pixel_put(data->mlx, data->win, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	pythagore(t_env *data, t_pos *add)
{
	int diag;

	add->x = (data->win_width - 100) / (data->max_x + 1);
	add->y = (data->win_height - 100) / (data->max_y + 1);
	diag = sqrt(pow(data->max_x * add->x, 2) + pow(data->max_y * add->y, 2));
	while (diag > data->win_width)
	{
		data->zoom -= 0.2;
		diag /= 2;
	}
}

t_pos	three_d(int i, int j, int z, t_env *data)
{
	t_pos a;
	t_pos center;
	t_pos add;
	data->color = 0x00ff00;
	add.x = (data->win_width - 100) / (data->max_x + 1);
	add.y = (data->win_height - 100) / (data->max_y + 1);
	center.x = data->win_width / 2;
	center.y = data-> win_height / 2.5;
	a.x = ((0.71) * (j - i)) * add.x;
	a.y = -(((-0.41) * (j + i)) + 0.82 + z) * add.y;
	a.x *= data->zoom;
	a.y *= data->zoom;
	a.x += center.x;
	a.y += center.y;
	return (a);
}

void	draw_iso(int **int_tab, t_env *data)
{
	t_pos i;
	t_pos a;
	t_pos b;

	i.y = 1;
	while (i.y < data->max_y + 1)
	{
		i.x = 1;
		while (i.x < data->max_x + 1)
		{
			a = three_d(i.y, i.x, int_tab[i.y - 1][i.x - 1], data);
			if (i.x > 1)
			{
				b = three_d(i.y, i.x - 1, int_tab[i.y - 1][i.x - 2], data);
				draw (data, &b, &a);
			}
			if (i.y > 1)
			{
				b = three_d(i.y - 1, i.x, int_tab[i.y - 2][i.x - 1], data);
				draw(data, &b, &a);
			}
			i.x++;
		}
		i.y++;
	}
}
