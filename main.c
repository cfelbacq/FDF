/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:17:32 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/12 14:29:29 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

int		expose_hook(t_env *data)
{
	//free_draw(data);
	draw_iso(data->integer_tab_s, data);
	return (0);
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
		if (data->zoom > 0.4)
			data->zoom -= 0.2;
			draw_iso(data->integer_tab_s, data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	int	**integer_tab;
	t_env data;
	t_pos add;

	data.max_y = 0;
	data.max_x = 0;
	data.win_width = 1200;
	data.win_height = 1200;
	fd = open(argv[1], O_RDONLY);
	integer_tab = NULL;
	if (argc == 2)
		integer_tab = fill_tab(fd, argv[1], integer_tab, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_height, data.win_width, "42");
	find_max_int(integer_tab, &data);
	data.integer_tab_s = integer_tab;
	data.zoom = 1;
	pythagore(&data, &add);
	draw_iso(data.integer_tab_s, &data);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
