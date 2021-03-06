/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:28:48 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/17 14:36:41 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	char	***fill_tmp_tab(char **string_tab, char ***string, t_env *data)
{
	int i;
	int j;

	i = 0;
	while (string_tab[i] != NULL)
		i++;
	string = (char ***)ft_memalloc(sizeof(char **) * i + 1);
	string[i] = NULL;
	data->max_y = i;
	i = 0;
	j = 0;
	while (string_tab[i] != NULL)
	{
		string[i] = ft_strsplit(string_tab[i], ' ');
		i++;
	}
	return (string);
}

static	int		**fill_integer_tab(char **string_tab, int **integer_tab,\
		t_env *data)
{
	int		i;
	char	***string;
	int		j;

	if ((count_len_nb(string_tab, data)) <= 1)
		return (0);
	i = 0;
	string = NULL;
	string = fill_tmp_tab(string_tab, string, data);
	integer_tab = (int **)ft_memalloc(sizeof(int *) * data->max_y);
	while (string[i] != NULL)
	{
		integer_tab[i] = (int *)ft_memalloc(sizeof(int) * \
				count_len_nb(string_tab, data));
		j = 0;
		while (string[i][j] != NULL)
		{
			integer_tab[i][j] = ft_atoi(string[i][j]);
			j++;
		}
		i++;
	}
	free_triple_tab(string);
	free_double_tab(string_tab);
	return (integer_tab);
}

static	char	**fill_string_tab(char **string_tab, int fd, char *line)
{
	int i;
	int j;
	int ret;
	int k;

	i = 0;
	ret = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		string_tab[i] = (char *)ft_memalloc(sizeof(char) * \
				count_len_line(line) + 1);
		j = 0;
		k = 0;
		while (line[j] != '\0')
		{
			while ((line[j] == ' ') && (line[j + 1] == ' '))
				j++;
			string_tab[i][k] = line[j];
			k++;
			j++;
		}
		string_tab[i][k] = '\0';
		i++;
	}
	return (check_tab(string_tab));
}

int				**fill_tab(char *file, int **integer_tab, t_env *data)
{
	char	**string_tab;
	char	*line;
	int		fd;

	line = NULL;
	string_tab = NULL;
	string_tab = memalloc_string_tab(string_tab, line, file);
	if (string_tab == NULL)
	{
		ft_putendl("File error.");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if ((fill_string_tab(string_tab, fd, line)) == NULL)
	{
		ft_putendl("File error.");
		return (0);
	}
	if ((integer_tab = fill_integer_tab(string_tab, integer_tab, data)) == 0)
	{
		ft_putendl("Not enough Numbers.");
		return (0);
	}
	return (integer_tab);
}
