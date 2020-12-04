/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:04:52 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/04 20:05:57 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static int	die(char *path)
{
	perror(path);
	return (1);
}

static int	do_ls(char *path, DIR *dp, int flag)
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
	flst_print(head, flag);
	flst_clear(&head);
	return (0);
}

static void	put_error(char *option)
{
	ft_putstr_fd("./ft_mini_ls: illegal option -- ", STDERR_FILENO);
	if (*option == '-')
		ft_putstr_fd(++option, STDERR_FILENO);
	else
		ft_putstr_fd(option, STDERR_FILENO);
	ft_putstr_fd("\nusage: ./ft_mini_ls [-G]\n", STDERR_FILENO);
}

int			main(int argc, char *argv[])
{
	DIR	*dp;
	int	exit;
	int	flag;

	if (argc > 2)
	{
		ft_putstr_fd("./ft_mini_ls: One argument available\n", STDERR_FILENO);
		return (1);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-' && ft_strchr(argv[1], 'G'))
			flag = 1;
		else
		{
			put_error(argv[1]);
			return (1);
		}
	}
	dp = opendir(PATH_LS);
	if (!dp)
		return (die(argv[0]));
	exit = do_ls(argv[0], dp, flag);
	closedir(dp);
	return (exit);
}
