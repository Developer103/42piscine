/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keiito <keiito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:11:38 by stanaka2          #+#    #+#             */
/*   Updated: 2025/02/23 11:15:07 by keiito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int main(int argc, char **argv)
{
	int		fd;
	t_dict	*dict_head = NULL;
	int		x;//added
	char	buffer[256];//added
	int		i;//added

	if (argc == 2)
	{
		if (!check_key(argv[1])) // key が数字だけかチェック
			return (!error_return("Error\n", -1, NULL, NULL));
		fd = open("numbers.dict", O_RDONLY); //O_RDONLY 読み取り専用で開く
		if (fd == -1) //open()が失敗
			return (!error_return("Error\n", -1, NULL, NULL));
		x = 1;
	}
	else if (argc == 3)
	{
		if (!check_key(argv[2])) // key が数字だけかチェック
			return (!error_return("Error\n", -1, NULL, NULL));
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (!error_return("Error\n", -1, NULL, NULL));
		x = 2;
	}
	//added whole of else if
	else if (argc == 1)
	{
		read(0, buffer, 256);
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n' && buffer[i + 1] == '\0')
			{
				buffer[i] = '\0';
				break ;
			}
			i++;
		}
		if (!check_key(buffer)) // key が数字だけかチェック
			return (!error_return("Error\n", -1, NULL, NULL));
		fd = open("numbers.dict", O_RDONLY); //O_RDONLY 読み取り専用で開く
		if (fd == -1) //open()が失敗
			return (!error_return("Error\n", -1, NULL, NULL));
		x = -1;
	}
	else
		return (!error_return("Error\n", -1, NULL, NULL)); //引数が不正

	// ここからロジック部分
	if (!read_dict(fd, &dict_head)) //辞書を読み込んで、keyとvalueのノードを作る
		return (!error_return(NULL, fd, NULL, NULL));
	// print_all_node(dict_head); //test用の関数、連結リストを全部出力
	if (x == -1 && !search_dict(dict_head, buffer))
		return (!error_return(NULL, fd, NULL, dict_head));
	else if (!search_dict(dict_head, argv[x])) //keyを解析し、辞書を参照しながら出力
		return (!error_return(NULL, fd, NULL, dict_head));

	// 終了
	free_all_nodes(dict_head); // 全てのnodeをfree()
	close(fd); //ファイルclose()
	return (0);
}

bool	error_return(char *s, int fd, char *allocated_mem, t_dict *dict) // エラーメッセージ、ファイルのclose、free、ノードの解放の内必要なものをしながらfalseを返す
{
	if (s != NULL)
		write(1, s, sizeof(s) - 1);
	if (fd != -1)
		close(fd);
	if (allocated_mem != NULL)
		free(allocated_mem);
	if (dict != NULL)
		free_all_nodes(dict);
	return (false);
}
