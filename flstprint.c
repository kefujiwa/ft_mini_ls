/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flstprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:19 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/03 18:28:56 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	flst_print(t_flst *lst)
{
	while (lst)
	{
		ft_putstr_fd(lst->name, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		lst = lst->next;
	}
}
