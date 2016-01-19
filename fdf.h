/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:44:08 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/19 15:38:45 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <mlx.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

typedef struct	s_max
{
	int y;
	int x;
}				t_max;

void	draw(t_env *data, t_pos *start, t_pos *destination);
void	free_double_tab(char **string_tab);
void	free_triple_tab(char ***string);
int		count_len_line(char *s);
int		count_len_nb(char **string_tab, t_max *max);
char	**count_line_in_file(int fd, char **string_tab, char *s);
char	***fill_tmp_tab(char **string_tab, char ***string, t_max *max);
int		**fill_integer_tab(char **string_tab, int **integer_tab, t_max *max);
int		**fill_tab(int fd, char **string_tab, char *file, int **integer_tab,\
		t_max *max);
#endif
