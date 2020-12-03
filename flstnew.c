/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:01:02 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/03 18:37:02 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

t_flst	*flst_new(char *name, time_t time, ino_t inum)
{
	t_flst	*lst;

	lst = (t_flst*)malloc(sizeof(t_flst));
	if (!lst)
		return (NULL);
	lst->name = ft_strdup(name);
	if (!lst->name)
		return (NULL);
	lst->time = time;
	lst->inum = inum;
	lst->next = NULL;
	return (lst);
}
