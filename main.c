/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:56:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/10 16:10:24 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


void	draw_iso(int **int_tab, t_env *data);
void	free_draw(t_env *data);

int		expose_hook(t_env *data)
{
	free_draw(data);
	draw_iso(data->integer_tab_s, data);
	return (0);
}

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

int		key_hook(int keycode, t_env *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		free_draw(data);
			data->zoom += 0.2;
		draw_iso(data->integer_tab_s, data);
	}
	if (keycode == 78)
	{
		free_draw(data);
		if (data->zoom > 0)
		data->zoom -= 0.2;
		draw_iso(data->integer_tab_s, data);
	}
	return (0);
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

t_pos	three_d(int i, int j, int z, t_env *data, t_pos *add)
{
	t_pos a;
	t_pos center;
	
	data->color = 0xffffff;
	add.x = (data->win_width - 100) / (data->max_x + 1);
	add.y = (data->win_height - 100) / (data->max_y + 1);
	center.x = data->win_width / 2;
	center.y = data-> win_height / 4*;
	a.x = ((0.72) * (j - i)) * add.x;
	a.y = -(((-0.40) * (j + i)) + 0.82 + z) * add.y;
	a.x *= data->zoom;
	a.y *= data->zoom;
	a.x += center.x;
	a.y += center.y;
	return (a);
}

void	draw_iso(int **int_tab, t_env *data, t_pos *add)
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
			a = three_d(i.y, i.x, int_tab[i.y - 1][i.x - 1], data, add);
			if (i.x > 1)
			{
				b = three_d(i.y, i.x - 1, int_tab[i.y - 1][i.x - 2], data, add);
				draw (data, &b, &a);
			}
			if (i.y > 1)
			{
				b = three_d(i.y - 1, i.x, int_tab[i.y - 2][i.x - 1], data, add);
				draw(data, &b, &a);
			}
			i.x++;
		}
		i.y++;
	}
}

void	find_max_int(int **integer_tab, t_env *data)
{
	int i;
	int j;

	data->max_int = 0;
	i = 0;
	j = 0;
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x)
		{
			if (data->max_int < integer_tab[i][j])
				data->max_int = integer_tab[i][j];
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char **string_tab;
	int fd;
	int	**integer_tab;
	t_env data;
	t_pos add;

	data.max_y = 0;
	data.max_x = 0;
	data.win_width = 1200;
	data.win_height = 1200;
	string_tab = NULL;
	fd = open(argv[1], O_RDONLY);
	integer_tab = NULL;
	if (argc == 2)
		integer_tab = fill_tab(fd, string_tab, argv[1], integer_tab, &data);
	ft_putstr("max_y : ");
	ft_putnbr(data.max_y);
	ft_putchar('\n');
	ft_putstr("max_x : ");
	ft_putnbr(data.max_x);
	ft_putchar('\n');
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_height, data.win_width, "42");
	find_max_int(integer_tab, &data);
	data.integer_tab_s = integer_tab;
	data.zoom = 1;
	pythagore(&data, &add);
	draw_iso(data.integer_tab_s, &data, &add);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
