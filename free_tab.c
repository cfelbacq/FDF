/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:30:38 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/16 16:09:58 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**memalloc_string_tab(char **string_tab, char *line, char *file)
{
	int i;
	int ret;
	int fd;

	ret = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
		i++;
	string_tab = (char **)ft_memalloc(sizeof(char *) * i + 1);
	string_tab[i] = NULL;
	line = NULL;
	return (string_tab);
}

void	free_double_tab(char **string_tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string_tab[i] != NULL)
	{
		ft_strdel(&string_tab[i]);
		i++;
	}
	free(string_tab);
}

void	free_triple_tab(char ***string)
{
	int i;
	int j;

	i = 0;
	while (string[i] != NULL)
	{
		j = 0;
		while (string[i][j] != NULL)
		{
			ft_strdel(&string[i][j]);
			j++;
		}
		free(string[i]);
		i++;
	}
	free(string);
}

void	free_int_doubletab(t_env *data, int **int_tab)
{
	int i;

	i = 0;
	while (i < data->max_y)
	{
		free(int_tab[i]);
		i++;
	}
	free(int_tab);
}
