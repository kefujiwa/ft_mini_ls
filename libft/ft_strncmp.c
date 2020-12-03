/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 04:23:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/06 17:21:12 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- && *s1 == *s2 && *s1 && *s2)
	{
		if (n != 0)
		{
			s1++;
			s2++;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
