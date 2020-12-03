/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flstadd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:05:50 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/03 22:35:43 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls_bonus.h"

static int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

static void	do_add(t_flst **lst, t_flst *new, t_flst *tmp, t_flst *prev)
{
	new->next = tmp;
	if (prev)
		prev->next = new;
	else
		*lst = new;
}

static int	flst_cmp(t_flst **lst, t_flst *new, t_flst *tmp, t_flst *prev)
{
	int	len;

	if (new->time < tmp->time)
		return (1);
	else if (new->time > tmp->time)
		return (-1);
	else if (new->ntime < tmp->ntime)
		return (1);
	else if (new->ntime > tmp->ntime)
		return (-1);
	else
	{
		len = max(ft_strlen(new->name), ft_strlen(tmp->name));
		if (ft_strncmp(new->name, tmp->name, len + 1) > 0)
			return (1);
		else
			return (-1);
	}
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
			if (flst_cmp(lst, new, tmp, prev) == 1)
				return (do_add(lst, new, tmp, prev));
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = new;
	}
	else
		*lst = new;
}
