/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:21:11 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/07 21:06:43 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nbytes;
	void	*p;

	nbytes = count * size;
	p = malloc(nbytes);
	if (!p)
		return (NULL);
	else
		ft_bzero(p, nbytes);
	return (p);
}
