/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 23:24:05 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/09 00:01:58 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_start(char *s, char *set)
{
	while (*s)
		if (ft_strchr(set, *s))
			s++;
		else
			break ;
	return (s);
}

static char	*find_end(char *s, char *set)
{
	int	index;

	index = ft_strlen(s) - 1;
	while (s[index])
		if (ft_strchr(set, s[index]))
			index--;
		else
			break ;
	return (&s[index]);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*p_str;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	start = find_start((char*)s1, (char*)set);
	end = find_end((char*)s1, (char*)set);
	if (!*start)
	{
		if (!(str = (char*)ft_calloc(1, sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(str = (char*)ft_calloc(end - start + 2, sizeof(char))))
			return (NULL);
		p_str = str;
		while (start <= end)
			*(p_str++) = *(start++);
		*p_str = '\0';
	}
	return (str);
}
