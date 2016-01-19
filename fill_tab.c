/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:28:48 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/19 15:41:03 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***fill_tmp_tab(char **string_tab, char ***string, t_max *max)
{
	int i;
	int j;

	i = 0;
	while (string_tab[i] != NULL)
		i++;
	string = (char ***)ft_memalloc(sizeof(char **) * i + 1);
	string[i] = NULL;
	max->y = i;
	i = 0;
	j = 0;
	while (string_tab[i] != NULL)
	{
		string[i] = ft_strsplit(string_tab[i], ' ');
		i++;
	}
	return (string);
}

int		**fill_integer_tab(char **string_tab, int **integer_tab, t_max *max)
{
	int i;
	char ***string;
	int j;
	int len_of_line;
	
	len_of_line = count_len_nb(string_tab, max);
	i = 0;
	j = 0;
	string = NULL;
	string = fill_tmp_tab(string_tab, string, max);
	integer_tab = (int **)ft_memalloc(sizeof(int *) * max->y);
	while (string[i] != NULL)
	{
		integer_tab[i] = (int *)ft_memalloc(sizeof(int) * len_of_line);
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

int		**fill_tab(int fd, char **string_tab, char *file, int **integer_tab,\
		t_max *max)
{
	int i;
	char *line;
	int ret;
	int j;

	i = 0;
	ret = 0;
	line = NULL;
	string_tab = count_line_in_file(fd, string_tab, line);
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		string_tab[i] = (char *)ft_memalloc(sizeof(char) * \
				count_len_line(line) + 1);
		j = 0;
		while (line[j] != '\0')
		{
			string_tab[i][j] = line[j];
			j++;
		}
		string_tab[i][j] = '\0';
		i++;
	}
	integer_tab = fill_integer_tab(string_tab, integer_tab, max);
	return (integer_tab);
}
