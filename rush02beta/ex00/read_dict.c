/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:42:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 08:08:26 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

size_t	count_splitted(char **s);
bool	parse_line(char *s, t_dict **dict);

bool	read_dict(int fd, t_dict **dict)
{
	char	**s;
	char	*remainder;
	int		res;
	char	buf[BUF_SIZE];
	size_t	count;
	size_t	i;

	remainder = ft_strdup(""); // malloc
	if (!remainder)
		return (false);
	while (true)
	{
		res = read(fd, buf, BUF_SIZE - 1); //辞書を読み込む
		if (res == -1)
			return (error_return(NULL, -1, remainder, *dict));
		if (res == 0)
		{
			if (!parse_line(remainder, dict))
				return (error_return(NULL, -1, remainder, *dict));
			break ;
		}
		buf[res] = '\0';
		remainder = strjoin_dict(remainder, buf); //remainder(余り：前回の最終行)と読み込んだものを繋げる
		s = ft_split(remainder, "\n"); //1行ごとにsplit
		if (!s)
			return (error_return(NULL, -1, remainder, *dict));
		count = count_splitted(s); // 何行か数える
		remainder = ft_strcpy(remainder, s[count - 1]); // 余り：最終行をコピーして次回持ち越し
		i = 0;
		while (i < count - 1)
		{
			if (!parse_line(s[i++], dict)) //辞書の行を解析して、keyとvalueをノードに格納
				return (error_return(NULL, -1, remainder, *dict));
		}
	}
	return (true);
}

size_t	count_splitted(char **s)
{
	size_t	count;

	count = 0;
	while (*s != NULL)
	{
		count++;
		s++;
	}
	return (count);
}

bool	parse_line(char *s, t_dict **dict)
{
	t_dict	*new;
	char	*key;
	char	*value;
	int		sign;
	size_t	digits;
	size_t	len;

	while (ft_isspace(*s)) //空白を飛ばす
		s++;
	sign = 1;
	while (*s == '+' || *s == '-') //符号を確認
	{
		if (*s++ == '-')
			sign *= -1;
	}
	if (sign == -1)
		return (error_return("Dict Error\n", -1, NULL, NULL));
	digits = 0;
	while (ft_isdigit(s[digits])) // keyの桁数を数える
		digits++;
	key = (char *)malloc(digits + 1);
	if (!key)
		return (false);
	ft_strncpy(key, s, digits); // keyをコピー
	s += digits; // keyの文字数分進める
	while (ft_isspace(*s)) //空白を飛ばす
		s++;
	if (*s++ != ':') // ':'か確認
		return (error_return("Dict Error\n", -1, NULL, NULL));
	while (ft_isspace(*s))
		s++;
	len = 0;
	while (ft_isprintable(s[len])) //valueの文字数を数える
		len++;
	value = (char *)malloc(len + 1);
	if (!value)
		return (error_return(NULL, -1, key, NULL));
	ft_strncpy(value, s, len); //valueをコピー
	s += len; //valueの文字数分進める
	if (*s)
	{
		free(key);
		return (error_return("Dict Error\n", -1, value, NULL));
	}
	new = new_node(key, value);
	if (!new)
	{
		free(key);
		return (error_return(NULL, -1, value, NULL));
	}
	//printf("key %s, value %s\n", new->key, new->value); // パースできているか確認用
	if (*dict == NULL) //最初
		*dict = new;
	else if (!insert_node(*dict, new)) // keyが小さい順に連結リストに追加
	{
		free(key);
		return (error_return(NULL, -1, value, NULL));
	}
	return (true);
}
