/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:15:22 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/06 17:45:19 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p_haystack;
	char	*p_needle;
	size_t	tmp_len;

	if (!*needle)
		return ((char*)haystack);
	while (len && *haystack)
	{
		p_haystack = (char*)haystack;
		p_needle = (char*)needle;
		tmp_len = len;
		while (*p_haystack == *p_needle && tmp_len--)
		{
			p_haystack++;
			p_needle++;
			if (*p_needle == '\0')
				return ((char*)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
