/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flstadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:05:50 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/03 19:28:32 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

static int	do_add(t_flst **lst, t_flst *new, t_flst *tmp, t_flst *prev)
{
	new->next = tmp;
	if (prev)
		prev->next = new;
	else
		*lst = new;
	return (0);
}

static int	flst_cmp(t_flst **lst, t_flst *new, t_flst *tmp, t_flst *prev)
{
	int	len;

	if (new->time < tmp->time)
		return (do_add(lst, new, tmp, prev));
	else if (new->time == tmp->time)
	{
		if (new->inum < tmp->inum)
			return (do_add(lst, new, tmp, prev));
		else if (new->inum == tmp->inum)
		{
			len = max(ft_strlen(new->name), ft_strlen(tmp->name));
			if (ft_strncmp(new->name, tmp->name, len + 1) > 0)
				return (do_add(lst, new, tmp, prev));
		}
	}
	return (1);
}

void		flst_add(t_flst **lst, t_flst *new)
{
	t_flst	*prev;
	t_flst	*tmp;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		prev = NULL;
		tmp = *lst;
		while (tmp)
		{
			if (flst_cmp(lst, new, tmp, prev) == 0)
				return ;
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = new;
	}
	else
		*lst = new;
}
