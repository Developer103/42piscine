/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:39 by tmizumur          #+#    #+#             */
/*   Updated: 2025/02/26 20:53:42 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H

# define INCLUDES_H

# define BUFF_SIZE 4096
# define MAX_BUFF 1000000
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_max
{
	int	val;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_max;

typedef struct s_keys
{	
	int		rows;
	int		columns;
	char	full;
	char	empty;
	char	obsct;
	int		argv;
}	t_keys;

typedef struct s_vars
{
	char	*s;
	int		num_files;
	int		**map;
	int		**map_cpy;
	char	**files;
}	t_vars;

t_keys	get_key(char **s, int argv);
int		check_map(char *s);
int		**get_map(char *s, t_keys key);
char	*ft_strdup(char *src);
int		str_len(char *s);
int		ty_atoi(char *s, int *n);
int		key_dup(char keys[3]);
int		ft_strcmp(char *s1, char *s2);
char	*read_standard_input_2(void);
void	skip(char *s, int *a, char keys[3], int *cols);
char	*ft_strcat(char *dest, char *src);
int		reader(char **result, char *filename);
int		read_file(char *filename, char **result);
char	*read_standard_input(void);
int		**copy_map(int **map, t_keys key);
void	ty_replace(char *s);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlen(char *str);
void	print_map(int **map, t_keys key);
void	calculate(int ***dp, int a, int b);
void	solve(int ***dp, t_keys keys);
void	get_max(int **dp, t_max *max, t_keys *keys);
void	fill_grid(int x, int y, int max, int ***result);
void	get_display_map(t_max *max, int ***result, int f);
int		free_allocs(t_vars *vars, t_keys key, int i);
int		error_allocs(t_vars *vars);

#endif