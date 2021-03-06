/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:17:32 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/17 14:21:47 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		expose_hook(t_env *data)
{
	draw_iso(data->integer_tab_s, data);
	return (0);
}

static	int		key_hook(int keycode, t_env *data)
{
	if (keycode == 53)
	{
		free_int_doubletab(data, data->integer_tab_s);
		exit(0);
	}
	if (keycode == 69)
		data->zoom += 0.2;
	if (keycode == 78)
		if (data->zoom > 0.4)
			data->zoom -= 0.2;
	if (keycode == 123)
		data->left_right -= 10;
	if (keycode == 124)
		data->left_right += 10;
	if (keycode == 126)
		data->up_down -= 10;
	if (keycode == 125)
		data->up_down += 10;
	free_draw(data);
	draw_iso(data->integer_tab_s, data);
	return (0);
}

static	void	init_data(int **integer_tab, t_env *data)
{
	data->color = 0xffffff;
	data->win_width = 1200;
	data->win_height = 1200;
	data->left_right = 0;
	data->up_down = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_height,\
			data->win_width, "42_FDF");
	find_max_int(integer_tab, data);
	data->integer_tab_s = integer_tab;
	data->zoom = 1;
}

int				main(int argc, char **argv)
{
	int		**integer_tab;
	t_env	data;

	integer_tab = NULL;
	if (argc == 2)
	{
		if ((integer_tab = fill_tab(argv[1], integer_tab, &data)) == 0)
			return (0);
		init_data(integer_tab, &data);
		pythagore(&data);
		draw_iso(data.integer_tab_s, &data);
		mlx_expose_hook(data.win, expose_hook, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_putendl("Wrong number of arguments.");
	return (0);
}
