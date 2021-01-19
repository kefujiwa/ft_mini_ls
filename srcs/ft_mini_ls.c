/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:04:52 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/04 20:02:40 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static int	die(char *path)
{
	perror(path);
	return (1);
}

static int	do_ls(char *path, DIR *dp)
{
	struct dirent	*ent;
	struct stat		st;
	t_flst			*head;
	t_flst			*new;

	head = NULL;
	while ((ent = readdir(dp)))
	{
		if (*(ent->d_name) == '.')
			continue;
		if (lstat(ent->d_name, &st) < 0)
			return (die(path));
		if (!(new = flst_new(ent->d_name, &st)))
		{
			flst_clear(&head);
			return (die(path));
		}
		flst_add(&head, new);
	}
	flst_print(head);
	flst_clear(&head);
	return (0);
}

int			main(int argc, char *argv[])
{
	DIR	*dp;
	int	exit;

	if (argc != 1)
	{
		ft_putstr_fd("./ft_mini_ls: Required no arguments\n", STDERR_FILENO);
		return (1);
	}
	dp = opendir(PATH_LS);
	if (!dp)
		return (die(argv[0]));
	exit = do_ls(argv[0], dp);
	closedir(dp);
	return (exit);
}
