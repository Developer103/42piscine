/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:42:59 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/22 21:30:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// 新規ノード作成
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

// ノードをdict->keyの小さい順に追加
bool	insert_node(t_dict *dict, t_dict *new)
{
	if (dict->next == NULL)
		dict->next = new;
	else if (strnum_cmp(dict->next->key, new->key) > 0) // 次のノードのkeyより小さければ挿入
	{
		new->next = dict->next;
		dict->next = new;
	} else if (strnum_cmp(dict->next->key, new->key) < 0) //次のノードのkeyより大きければ次のノードへ(再帰)
		return (insert_node(dict->next, new));
	else
		return (false);
	return (true);
}

// ノードから一致するキーを探す
char *find_key_value(t_dict *dict, char *key)
{
	if (strnum_cmp(dict->key, key) == 0) //key一致したらvalueを返す
		return (dict->value);
	if (dict->next == NULL)
		return (NULL);
	return (find_key_value(dict->next, key));
}


// ノードのdict->Valueを全free
void	free_all_nodes(t_dict *dict)
{
	if (dict->next == NULL)
		return ;
	free(dict->key);
	dict->key = NULL;
	free(dict->value);
	dict->value = NULL;
	free_all_nodes(dict->next); //再帰
	free(dict);
	dict = NULL;
}

void	print_all_node(t_dict *dict) //test用の関数、連結リストを全部出力
{
	printf("%s %s\n", dict->key, dict->value);
	if (dict->next == NULL)
		return ;
	print_all_node(dict->next);
}
