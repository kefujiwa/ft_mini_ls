/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flstclear_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:57:27 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/03 22:35:54 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

void	flst_clear(t_flst **lst)
{
	t_flst *next_lst;

	if (!lst)
		return ;
	while (*lst)
	{
		next_lst = (*lst)->next;
		free((*lst)->name);
		free(*lst);
		*lst = next_lst;
	}
}
