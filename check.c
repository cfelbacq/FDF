/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:56:46 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/17 14:19:11 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	char	**check_char(char **string_tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string_tab[i] != NULL)
	{
		j = 0;
		while (string_tab[i][j] != '\0')
		{
			if ((string_tab[i][j] > '9' || string_tab[i][j] < '0') &&\
					(string_tab[i][j] != '-' && string_tab[i][j] != ' '))
				return (NULL);
			if (string_tab[i][j] == '-' && string_tab[i][j + 1] == '-')
				return (NULL);
			j++;
		}
		i++;
	}
	return (string_tab);
}

char			**check_tab(char **string_tab)
{
	if ((check_char(string_tab)) == NULL)
		return (NULL);
	return (string_tab);
}
