/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:56:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/20 17:04:02 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *data)
{
	t_pos start;
	t_pos destination;
	start.x = 0;
	start.y = 0;
	destination.x = 457;
	destination.y = 597;
	draw(data, &start, &destination);
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
	data.win = mlx_new_window(data.mlx, 1280, 1024, "42");
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
