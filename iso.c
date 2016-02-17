/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:18:23 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/17 14:29:26 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void			free_draw(t_env *data)
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

void			pythagore(t_env *data)
{
	int		diag;
	t_pos	add;

	add.x = (data->win_width) / (data->max_x + 1);
	add.y = (data->win_height) / (data->max_y + 1);
	diag = sqrt(pow(data->max_x * add.x, 2) + pow(data->max_y * add.y, 2));
	while (diag > data->win_width)
	{
		data->zoom -= 0.4;
		diag /= 2;
	}
}

static	t_pos	three_d(int i, int j, float z, t_env *data)
{
	t_pos a;
	t_pos center;

	center.x = data->win_width / 2;
	center.y = data->win_height / 3;
	z /= 2;
	a.x = ((0.71) * (j - i)) * ((data->win_width) / (data->max_x + 1));
	a.y = -(((-0.41) * (j + i)) + 0.82 + z) * \
		((data->win_height) / (data->max_y + 1));
	a.x = a.x * data->zoom + center.x + data->left_right;
	a.y = a.y * data->zoom + center.y + data->up_down;
	return (a);
}

void			draw_iso(int **int_tab, t_env *data)
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
				draw(data, &b, &a);
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
