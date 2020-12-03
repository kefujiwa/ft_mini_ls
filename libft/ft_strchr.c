/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:14:10 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/06/30 04:43:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (NULL);
}
