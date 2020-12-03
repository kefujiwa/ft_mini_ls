/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:14:52 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/01 22:07:27 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p_src;

	p_src = (char*)src;
	if (dstsize != 0)
	{
		while (dstsize - 1 && *src)
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (ft_strlen(p_src));
}
