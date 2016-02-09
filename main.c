/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:56:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/09 16:58:00 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	place_point(int **integer_tab, t_env *data, t_win *window);
void	free_draw(t_env *data);

int		expose_hook(t_env *data)
{
	t_win window;

	window.width = data->win_width;
	window.height = data->win_height;

	free_draw(data);
	place_point(data->integer_tab_s, data, &window);
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
	return (0);
}

t_pos	threed(int i, int j, t_pos a, int z, t_pos *add)
{
	a.x = ((M_SQRT2 / 2) * (j - i)) * add->x;
	a.y = -(((-0.60) * (j + i)) + 0.82 + z)\
		   * add->y;
	a.x *= 0.5;
	a.y *= 0.5;
	a.x += 500;
	a.y += 500;
	return (a);
}

void	draw_x(t_env *data, int **integer_tab, t_pos *add, t_win *window)
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
			a = threed(i.y, i.x, a, integer_tab[i.y - 1][i.x - 1], add);
			if (i.x > 1)
			{
				b = threed(i.y, i.x - 1, a, integer_tab[i.y - 1][i.x - 2], add);
				draw (data, &b, &a);
			}
			if (i.y > 1)
			{
				b = threed(i.y - 1, i.x, a, integer_tab[i.y - 2][i.x - 1], add);
				draw(data, &b, &a);
			}
			i.x++;
		}
		i.y++;
	}
}

void	place_point(int **integer_tab, t_env *data, t_win *window)
{
	t_pos add;

	data->color = 0xffffff;
	add.x = (window->width - 100) / (data->max_x + 1);
	add.y = (window->height - 100) / (data->max_y + 1) ;
	draw_x(data, integer_tab, &add, window);
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
	int i;
	int j;
	int	**integer_tab;
	t_env data;
	t_win window;

	data.max_y = 0;
	data.max_x = 0;
	window.width = 1200;
	window.height = 1200;
	string_tab = NULL;
	i = 0;
	j = 0;
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
	data.win = mlx_new_window(data.mlx, window.height, window.width, "42");
	find_max_int(integer_tab, &data);
	place_point(integer_tab, &data, &window);
	data.win_width = window.width;
	data.win_height = window.height;
	data.integer_tab_s = integer_tab;
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
