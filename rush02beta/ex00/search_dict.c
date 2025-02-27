/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:57:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 12:13:54 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	parse_key(t_dict *dict, char **key);
bool	print_three_digits(t_dict *dict, char *key);
bool	print_two_digits(t_dict *dict, char *key, int a);
bool	print_one_digit(t_dict *dict, char *key, int a);
bool	print_numerical_units(t_dict *dict, char *key);

bool	search_dict(t_dict *dict, char *key)
{
	int digits;

	if (strnum_cmp(key, "0") == 0) // 0は例外
		return (print_one_digit(dict, key, 0));
	while (*key)
	{
		if (!parse_key(dict, &key)) // 1 - 3桁ずつ出力
			return (false);
		digits = ft_strlen(key);
		if (digits > 3) // 1000以上
		{
			write(1, " ", 1);
			print_numerical_units(dict, key); // 単位の出力
		}
		key++;
		while (*key && *key == '0') // 0は何もしない
			key++;
		if (*key)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (true);
}

bool	parse_key(t_dict *dict, char **key)
{
	int digits;

	digits = ft_strlen(*key);
	if (digits % 3 == 0) // 100の位
	{
		if (!print_three_digits(dict, *key))
			return (false);
		*key += 2;
	}
	else if (digits % 3 == 2) //10の位
		return(print_two_digits(dict, *key++, 0));
	else if (digits % 3 == 1) //1の位
		return (print_one_digit(dict, *key, 0));
	return (true);
}

bool	print_three_digits(t_dict *dict, char *key)
{
	char	*s;

	s = find_key_value(dict, (char []){*key, '\0'}); // 百のくらいの数字をkeyとして検索
	if (!s)
		return (false);
	ft_putstr(s);
	write (1, " ", 1);
	s = find_key_value(dict, "100"); // hundredを検索
	if (!s)
		return (error_return("Dict Error\n", -1, NULL, NULL));
	ft_putstr(s);
	if (*(key + 1) != '0')
	{
		write (1, " ", 1);
		print_two_digits(dict, key + 1, 1); //10の位 & added 1
	}
	else if (*(key + 2) != '0')
	{
		write (1, " ", 1);
		print_one_digit(dict, key + 2, 1); // 1の位 & added 1
	}
	return (true);
}

bool	print_two_digits(t_dict *dict, char *key, int a)
{
	char	*s;

	if ((a || *(key - 1)) && *key != '0')//added
		write(1, "and ", 4);//added
	if (strnum_cmp((char []){*key, *(key + 1), '\0'}, "20") >= 0)
	{
		s = find_key_value(dict, (char []){*key, '0', '\0'}); //20以上のとき、十の位を検索
		if (!s)
			return (error_return("Dict Error\n", -1, NULL, NULL));
		ft_putstr(s);
		if (*(key + 1) != '0')
		{
			write (1, "-", 1);//added
			print_one_digit(dict, key + 1, 0); // 1の位を検索
		}
	}
	else
	{
		s = find_key_value(dict, (char []){*key, *(key + 1), '\0'}); //10-19を検索
		if (!s)
			return (error_return("Dict Error\n", -1, NULL, NULL));
		ft_putstr(s);
	}
	return (true);
}

bool	print_one_digit(t_dict *dict, char *key, int a)
{
	char	*s;

	if (a)//added
		write(1, "and ", 4);//added
	else if (*(key - 1) && a)//added
		write(1, "and ", 4);//added
	s = find_key_value(dict, (char []){*key, '\0'}); //1の位を検索
	if (!s)
		return (error_return("Dict Error\n", -1, NULL, NULL));
	ft_putstr(s);
	return (true);
}

bool	print_numerical_units(t_dict *dict,char *key)
{
	char	*units;
	size_t	len;
	char	*s;

	len = ft_strlen(key);
	units = (char *)malloc(len + 1);
	if (!units)
		return (false);
	units[0] = '1';
	units[len] = '\0';
	while (--len > 0)
		units[len] = '0';
	s = find_key_value(dict, units); // 1000などの単位を検索
	//printf("units: %s, key: %s\n", units, key);
	if (!s)
		return (error_return("Dict Error\n", -1, units, NULL));
	ft_putstr(s);
	len = 1;//added from here to end of if
	while (key[len] == '0')
		len++;
	if (key[len] != '\0')
		write(1, ",", 1);
	free(units);
	return (true);
}
