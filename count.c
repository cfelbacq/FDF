/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:30:16 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/16 16:07:44 by cfelbacq         ###   ########.fr       */
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
