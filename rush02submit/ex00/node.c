/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumiyata <yumiyata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:42:59 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 17:47:54 by yumiyata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*new_node(char *key, char *value)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->key = key;
	dict->value = value;
	dict->next = NULL;
	return (dict);
}

bool	insert_node(t_dict *dict, t_dict *new)
{
	if (dict->next == NULL)
		dict->next = new;
	else if (strnum_cmp(dict->next->key, new->key) > 0)
	{
		new->next = dict->next;
		dict->next = new;
	}
	else if (strnum_cmp(dict->next->key, new->key) < 0)
		return (insert_node(dict->next, new));
	else
		return (false);
	return (true);
}

char	*find_key_value(t_dict *dict, char *key)
{
	if (strnum_cmp(dict->key, key) == 0)
		return (dict->value);
	if (dict->next == NULL)
		return (NULL);
	return (find_key_value(dict->next, key));
}

void	free_all_nodes(t_dict *dict)
{
	if (dict == NULL)
		return ;
	free(dict->key);
	dict->key = NULL;
	free(dict->value);
	dict->value = NULL;
	if (dict->next != NULL)
		free_all_nodes(dict->next);
	dict->next = NULL;
	free(dict);
}
