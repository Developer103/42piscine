/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:11:38 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 16:59:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

bool	stdin_main(int argc, char **argv);
bool	free_return(int fd, char *alloc_mem, char *alloc_mem2, t_dict *dict);

int	main(int argc, char **argv)
{
	char	*key;
	int		fd;
	t_dict	*dict_head;
	char	*output;

	dict_head = NULL;
	if (argc == 1)
		return (stdin_main(argc, argv));
	if (!read_key(argc, argv, &key))
		return (1);
	if (!check_key(key))
		return (!error_return("Error\n", -1, NULL, NULL));
	fd = open_dict(argc, argv);
	if (fd == -1)
		return (1);
	if (!read_dict(fd, &dict_head))
		return (!error_return(NULL, fd, NULL, dict_head));
	if (!is_strdup_success(&output, ""))
		return (!error_return(NULL, fd, NULL, dict_head));
	if (!search_dict(dict_head, key, &output))
		return (!error_return(NULL, fd, output, dict_head));
	print_output(output);
	return (free_return(fd, output, NULL, dict_head));
}

bool	stdin_main(int argc, char **argv)
{
	char	*key;
	int		fd;
	t_dict	*dict_head;
	char	*output;

	dict_head = NULL;
	if (!read_key(argc, argv, &key))
		return (1);
	if (!check_key(key))
		return (!error_return("Error\n", -1, key, NULL));
	fd = open_dict(argc, argv);
	if (fd == -1)
		return (!error_return(NULL, -1, key, NULL));
	if (!read_dict(fd, &dict_head))
		return (!error_return(NULL, fd, key, dict_head));
	if (!is_strdup_success(&output, ""))
		return (!error_return(NULL, fd, key, dict_head));
	if (!search_dict(dict_head, key, &output))
	{
		free(output);
		return (!error_return(NULL, fd, key, dict_head));
	}
	print_output(output);
	return (free_return(fd, output, key, dict_head));
}

bool	free_return(int fd, char *alloc_mem, char *alloc_mem2, t_dict *dict)
{
	if (fd != -1)
		close(fd);
	if (alloc_mem != NULL)
		free(alloc_mem);
	if (alloc_mem2 != NULL)
		free(alloc_mem2);
	if (dict != NULL)
		free_all_nodes(dict);
	return (0);
}

bool	error_return(char *s, int fd, char *allocated_mem, t_dict *dict)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
	if (fd != -1)
		close(fd);
	if (allocated_mem != NULL)
	{
		free(allocated_mem);
	}
	if (dict != NULL)
		free_all_nodes(dict);
	return (false);
}
