/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:14:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/10/05 20:54:34 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	cnt;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)ft_calloc(len, sizeof(char))))
		return (NULL);
	cnt = 0;
	while (*s1)
		str[cnt++] = *(s1++);
	while (*s2)
		str[cnt++] = *(s2++);
	str[cnt] = '\0';
	return (str);
}
