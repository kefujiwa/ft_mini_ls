/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flstprint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:19 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/04 01:53:14 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static void	put_isexec(mode_t mode)
{
	if (mode & S_ISUID)
		ft_putstr_fd("\033[30m\033[41m", STDOUT_FILENO);
	else if (mode & S_ISGID)
		ft_putstr_fd("\033[30m\033[46m", STDOUT_FILENO);
	else
		ft_putstr_fd("\033[31m", STDOUT_FILENO);
}

static void	put_isdir(mode_t mode)
{
	if (mode & (S_IWOTH | S_ISVTX))
		ft_putstr_fd("\033[30m\033[42m", STDOUT_FILENO);
	else if (mode & S_IWOTH)
		ft_putstr_fd("\033[30m\033[41m]", STDOUT_FILENO);
	else
		ft_putstr_fd("\033[34m", STDOUT_FILENO);
}

static void	put_clr(mode_t mode)
{
	if (S_ISDIR(mode))
		put_isdir(mode);
	else if (S_ISLNK(mode))
		ft_putstr_fd("\033[35m", STDOUT_FILENO);
	else if (S_ISSOCK(mode))
		ft_putstr_fd("\033[32m", STDOUT_FILENO);
	else if (S_ISFIFO(mode))
		ft_putstr_fd("\033[33m", STDOUT_FILENO);
	else if (S_ISREG(mode) && (mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		put_isexec(mode);
	else if (S_ISBLK(mode))
		ft_putstr_fd("\033[34m\033[46m", STDOUT_FILENO);
	else if (S_ISCHR(mode))
		ft_putstr_fd("\033[34m\033[43m", STDOUT_FILENO);
}

void		flst_print(t_flst *lst, int flag)
{
	while (lst)
	{
		if (flag == 1)
			put_clr(lst->mode);
		ft_putstr_fd(lst->name, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		lst = lst->next;
	}
}
