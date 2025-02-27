/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:03:10 by keiito            #+#    #+#             */
/*   Updated: 2025/02/23 13:41:14 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_isprintable(char c)
{
	return ((' ' <= (unsigned char)c && (unsigned char)c <= '~'));
}

int	count_size(char *file)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDWR);
	while (read(fd, &c, 1) > 0)
	{
		count++;
	}
	close(fd);
	return (count);
}

char	*read_file(char *filename)
{
	char	*lines;
	int		fd;
	int		r;

	lines = malloc(count_size(filename) + 1);
	fd = open(filename, O_RDONLY);
	r = read(fd, lines, count_size(filename));
	lines[r] = '\0';
	close(fd);
	return (lines);
}

char	*format_dict(char *dict, int size)
{
	int		a;
	int		f;
	int		b;
	char	*result;

	a = 0;
	f = 0;
	b = 0;
	result = malloc(size);
	while (dict[a] != '\0')
	{
		if (dict[a] == '\n')
		{
			while (dict[a] == '\n')
				a++;
			f = 0;
		}
		if (dict[a] == ' ' && (f == 0 || f == 1))
		{
			f += 1;
			while (dict[a] == ' ')
				a++;
		}
		else
			result[b++] = dict[a++];
	}
	result[b] = '\0';
	return (result);
}

int	check_format(char *str)
{
	int	a;
	int	f;

	a = 0;
	f = 0;
	while (str[a] != '\0')
	{
		if (str[a] == '\n')
		{
			if (str[a + 1] != ':')
				f = 0;
			else
				return (1);
		}
		if (str[a] == ':' && f == 0)
			f = 1;
		if (f == 0 && (str[a] < '0' || str[a] > '9'))
			return (1);
		if (f == 1 && (str[a] < 32 || str[a] > 126))
			return (1);
		a++;
	}
	return (0);
}

int	str_len(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*str_dup(char *str)
{
	char	*res;
	int		a;

	a = 0;
	res = (char *)malloc(((str_len(str) + 1)) * sizeof(char));
	while (str[a] != '\0')
	{
		res[a] = str[a];
		a++;
	}
	res[a] = '\0';
	return (res);
}

t_dict	*create_entry(char *key, char *value)
{
	t_dict	*new_entry;

	new_entry = (t_dict *)malloc(sizeof(t_dict));
	new_entry->num = str_dup(key);
	new_entry->name = str_dup(value);
	new_entry->digit = str_len(key);
	new_entry->next = NULL;
	return (new_entry);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	a;

	len = 0;
	a = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[a] != '\0')
	{
		dest[len] = src[a];
		a++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

//Change each "if" into searching for digit + num inside dictionary (under 3 digits)
char	*search_dict(char num, int digit)
{
	(void) num;
	char	*names[] = {"Four hundred ", "fourty ", "two", "Error\n"};
	if (digit == 1)
		return (names[2]);
	if (digit == 2)
		return (names[1]);
	if (digit == 3)
		return (names[0]);
	return (names[3]);
}

char	*triple_digit_name(char *num)
{
	int		a;
	int		b;
	char	*result;
	int		len;

	a = str_len(num);
	b = 0;
	len = 0;
	while (num[b] != '\0')
	{
		if (a == 3)
			len += str_len(search_dict(num[b], a));
		else if (a == 2)
			len += str_len(search_dict(num[b], a));
		else if (a == 1)
			len += str_len(search_dict(num[b], a));
		b++;
		a--;
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	while (b > a)
	{
		ft_strcat(result, search_dict(num[3 - b], b));
		b--;
	}
	return (result);
}

//Return name of number thousand and beyond(million, billion) if its 1 followed by zeros(up to digit - 1)
char	*search_thousands(int digits)
{
	(void) digits;
	return ("Thousand");
}

int	send_to_name(char *num, int pos, int digit)
{
	int		start_pos;
	int		total_digit;
	char	n[4];

	if (num[pos] == '\0')
		return (0);
	start_pos = pos;
	while (pos < start_pos + digit)
	{
		n[pos - start_pos] = num[pos];
		pos++;
	}
	n[pos - start_pos] = '\0';
	write(1, triple_digit_name(n), str_len(triple_digit_name(n)));
	total_digit = str_len(num) - pos;
	write(1, search_thousands(total_digit), str_len(search_thousands(total_digit)));
	send_to_name(num, pos, 3);
	return (0);
}

int main()
{
	unsigned char c = (unsigned char)("é"[0]);
	//unsigned char c = 195;
	// char *dictionary[] = {"Four hundred ", "fourty ", "two"};
	// char *dictionary = "Four hundred ";
	// char *test = read_file("test");
	// char *result = format_dict(test, count_size("test"));
	// printf("test: %s\n", test);
	// printf("result: %s\n", result);
	// printf("format: %d\n", check_format(result));
	//printf("%d, é\n", ft_isprintable('é'));
	printf("é: %c\n", c);
	return (0);
}
