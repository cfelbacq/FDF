/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:56:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/03 15:56:20 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *data)
{
	t_pos start;
	t_pos destination;
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


void	place_point(int **integer_tab, t_env *data)
{
	int i;
	int j;
	t_pos a;

	a.x = 10;
	a.y = 10;
	i = 0;
	j = 0;
	while (i < data->max_y)
	{
		j = 0;
		a.x = 10;
		while (j < data->max_x)
		{
			a.x += 10;
			mlx_pixel_put(data->mlx, data->win, a.x, a.y, 0xFF0000);
			ft_putstr("a.x : ");
			ft_putnbr(a.x);
			ft_putchar('\n');
			j++;
		}
		a.y += 10;
			ft_putstr("a.y : ");
			ft_putnbr(a.y);
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

void	draw_x(t_env *data)
{
	
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
	place_point(integer_tab, &data);
	draw_x(&data);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
