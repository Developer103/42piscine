/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:12:33 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/22 21:04:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

#define BUF_SIZE 256

typedef struct s_dict {
	char			*key;
	char 			*value;
	struct s_dict	*next;
}	t_dict;

//ロジック
bool	check_key(char *s);
bool	read_dict(int fd, t_dict **dict);
bool	search_dict(t_dict *dict, char *key);
bool	search_dict(t_dict *dict, char *key);
//node
t_dict	*new_node(char *key, char *value);
bool	insert_node(t_dict *dict, t_dict *new);
char	*find_key_value(t_dict *dict, char *key);
void	free_all_nodes(t_dict *dict);
//標準関数
size_t	ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strndup(char const *s1, size_t n);
int		ft_isspace(int c);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int		ft_isdigit(char c);
int		ft_isprintable(char c);
void	ft_putstr(char *str);
//utils
bool	error_return(char *s, int fd, char *allocated_mem, t_dict *dict);
int		strnum_cmp(char *s_num1, char *s_num2);
char	*strjoin_dict(char *remainder, char *buf);

//テスト用
# include <stdio.h>
void	print_all_node(t_dict *dict);

#endif
