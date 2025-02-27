/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:24:25 by tmizumur          #+#    #+#             */
/*   Updated: 2025/02/26 20:39:46 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <sys/time.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (0);
}

int	read_and_check(char *s, int ***map, int ***map_cpy, t_keys *key)
{
	if (check_map(s) == -1)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	*key = get_key(&s, key->argv);
	*map = get_map(s, *key);
	*map_cpy = copy_map(*map, *key);
	return (0);
}

void	solve_and_print(int ***map, int ***map_cpy, t_keys key, t_max *max)
{
	max->val = 0;
	max->x1 = 0;
	max->x2 = 0;
	max->y1 = 0;
	max->y2 = 0;
	solve(map, key);
	get_max(*map, max, &key);
	if (max->x2 == 0)
	{
		get_display_map(max, map_cpy, 1);
		print_map(*map_cpy, key);
	}
	else
	{
		get_display_map(max, map_cpy, 1);
		print_map(*map_cpy, key);
	}
}

int	file_to_print(t_vars *vars, t_keys *key, t_max *max)
{
	int	x;

	x = vars->num_files;
	while (vars->num_files > 0)
	{
		if (!vars->files)
			vars->s = read_standard_input();
		else if (read_file(vars->files[key->argv], &vars->s) == -1)
			return (error_allocs(vars));
		if (vars->s)
		{
			if (read_and_check(vars->s, &vars->map, &vars->map_cpy, key))
				return (free_allocs(vars, *key, 1));
			solve_and_print(&vars->map, &vars->map_cpy, *key, max);
			free_allocs(vars, *key, 0);
		}
		else
			error_allocs(vars);
		key->argv += 1;
		vars->num_files--;
		if (vars->num_files != 0)
			write(1, "\n", 1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_keys	key;
	t_max	max;

	if (argc >= 2)
	{
		key.argv = 1;
		vars.num_files = argc - 1;
		vars.files = argv;
	}
	else if (argc == 1)
	{
		vars.files = 0;
		vars.num_files = 1;
	}
	if (file_to_print(&vars, &key, &max) == -1)
		return (-1);
	return (0);
}
