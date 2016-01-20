/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:44:08 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/20 15:40:14 by cfelbacq         ###   ########.fr       */
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
	int		max_x;
	int		max_y;
}				t_env;

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;


void	draw(t_env *data, t_pos *start, t_pos *destination);
void	free_double_tab(char **string_tab);
void	free_triple_tab(char ***string);
int		count_len_line(char *s);
int		count_len_nb(char **string_tab, t_env *data);
char	**count_line_in_file(int fd, char **string_tab, char *s);
char	***fill_tmp_tab(char **string_tab, char ***string, t_env *data);
int		**fill_integer_tab(char **string_tab, int **integer_tab, t_env *data);
int		**fill_tab(int fd, char **string_tab, char *file, int **integer_tab,\
		t_env *data);
#endif