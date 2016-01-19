/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:56:47 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/19 15:44:32 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int		expose_hook(t_env *data)
  {
  t_pos start;
  t_pos destination;
  start.x = 0;
  start.y = 0;
  destination.x = 115;
  destination.y = 178;
  mlx_pixel_put(data->mlx, data->win, 115, 178, 0x00FF00);
  mlx_pixel_put(data->mlx, data->win, 115, 179, 0x00FF00);
  mlx_pixel_put(data->mlx, data->win, 116, 178, 0x00FF00);
  mlx_pixel_put(data->mlx, data->win, 116, 179, 0x00FF00);
  draw(data, &start, &destination);
  return (0);
  }*/

int	main(int argc, char **argv)
{
	char **string_tab;
	int fd;
	int i;
	int j;
	int	**integer_tab;
	t_max max;

	max.y = 0;
	max.x = 0;
	string_tab = NULL;
	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	integer_tab = NULL;
	if (argc == 2)
		integer_tab = fill_tab(fd, string_tab, argv[1], integer_tab, &max);
	while (i < max.y)
	{
		j = 0;
		while(j < max.x)
		{
			ft_putnbr(integer_tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	/*t_env	data;
	  data.mlx = mlx_init();
	  data.win = mlx_new_window(data.mlx, 1280, 1024, "42");
	  mlx_expose_hook(data.win, expose_hook, &data);
	  mlx_loop(data.mlx);*/
	return (0);
}
