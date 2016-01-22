/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:56:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/22 16:28:24 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *data)
{
	t_pos start;
	t_pos destination;
	start.x = data->x;
	start.y = data->y;
	mlx_pixel_put(data->mlx, data->win, start.x, start.y, data->color);
	//draw(data, &start, &destination);
	return (0);
}

int		key_hook(int keycode, t_env *data)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *data)
{
	t_pos a;
	a.x = 500;
	a.y = 500;
	mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
	if (button == 1)
	{
		t_pos destination_mouse;
		destination_mouse.x = x;
		destination_mouse.y = y;
		draw(data, &a, &destination_mouse);
	}
	return (0);
}

void		choose_color(int int_tab, t_env *data)
{
	int div;

	div = data->max_int / 4;
	if (int_tab < div)
		data->color = 0xFF0000;
	else if(int_tab > div && int_tab < div * 2)
		data->color = 0x00FF00;
	else if(int_tab > div * 2 && int_tab < div * 3)
		data->color = 0x0000FF;
	else
		data->color = 0xFFFFFF;
}

void	place_point(int **integer_tab, t_env *data)
{
	int i;
	int j;
	int startx;
	int starty;

	i = 0;
	j = 0;
	data->x = 10;
	data->y = 10;
	startx = data->win_x / data->max_x;
	starty = data->win_y / data->max_y;
	while (i < data->max_y)
	{
		j = 0;
		data->x = startx + 10;
		while (j < data->max_x)
		{
			data->x = data->x + startx;
			ft_putstr("data.x : ");
			ft_putnbr(data->x);
			ft_putchar('\n');
			choose_color(integer_tab[i][j], data);
			expose_hook(data);
			j++;
		}
		data->y = data->y + starty;
			ft_putstr("data.y : ");
			ft_putnbr(data->y);
			ft_putchar('\n');
		i++;
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
	int i;
	int j;
	int	**integer_tab;
	t_env data;

	data.max_y = 0;
	data.max_x = 0;
	data.win_y = 1200;
	data.win_x = 1200;
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
	data.win = mlx_new_window(data.mlx, data.win_y, data.win_x, "42");
	mlx_mouse_hook(data.win, mouse_hook, &data);
	find_max_int(integer_tab, &data);
	place_point(integer_tab, &data);
	//mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
