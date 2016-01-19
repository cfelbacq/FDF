/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:30:38 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/19 15:31:19 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
