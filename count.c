/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:30:16 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/03 15:42:50 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_len_line(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int		count_len_nb(char **string_tab, t_env *data)
{
	int i;
	int j;
	int tmp;

	tmp = 0;
	j = 0;
	i = 0;
	while (string_tab[i] != NULL)
	{
		data->max_x = 0;
		j = 0;
		while (string_tab[i][j] != '\0')
		{
			if (((string_tab[i][j] >= '0' && string_tab[i][j] <= '9')) && \
			((string_tab[i][j + 1] == ' ' || string_tab[i][j + 1] == '\0')))
				data->max_x++;
			j++;
		}
		i++;
		if (tmp < data->max_x)
			tmp = data->max_x;
	}
	if (i > 1)
		data->max_x = tmp;
	return (data->max_x);
}

char**		memalloc_string_tab(int fd, char **string_tab, char *line)
{
	int i;
	int ret;
	
	ret = 0;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		i++;
	string_tab = (char **)ft_memalloc(sizeof(char *) * i + 1);
	string_tab[i] = NULL;
	line = NULL;
	return (string_tab);
}
