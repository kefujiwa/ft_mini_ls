/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:13:14 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/04 00:02:00 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	if (!dst && !src)
		return (NULL);
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (dst < src)
		while (len--)
		{
			*p_dst = *p_src;
			p_dst++;
			p_src++;
		}
	else
		while (len--)
			p_dst[len] = p_src[len];
	return (dst);
}
