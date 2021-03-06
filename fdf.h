/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:44:08 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/02/17 14:35:38 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		max_x;
	int		max_y;
	int		color;
	int		max_int;
	int		**integer_tab_s;
	int		win_width;
	int		win_height;
	float	zoom;
	int		up_down;
	int		left_right;
}				t_env;

typedef struct	s_win
{
	int		width;
	int		height;
}				t_win;

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

void			draw(t_env *data, t_pos *start, t_pos *destination);
void			free_double_tab(char **string_tab);
void			free_triple_tab(char ***string);
void			free_int_doubletab(t_env *data, int **int_tab);
int				count_len_line(char *s);
int				count_len_nb(char **string_tab, t_env *data);
char			**memalloc_string_tab(char **string_tab, char *s, char *file);
int				**fill_tab(char *file, int **integer_tab,\
				t_env *data);
void			draw_iso(int **int_tab, t_env *data);
void			free_draw(t_env *data);
void			find_max_int(int **integer_tab, t_env *data);
void			pythagore(t_env *data);
char			**check_tab(char **string_tab);
#endif
