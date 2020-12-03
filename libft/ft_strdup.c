/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:14:17 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/08/28 00:37:04 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_s1;
	size_t	len;
	size_t	cnt;

	len = ft_strlen(s1) + 1;
	copy_s1 = (char*)ft_calloc(len, sizeof(char));
	if (!copy_s1)
		return (NULL);
	cnt = 0;
	while (*s1)
		copy_s1[cnt++] = *(s1++);
	copy_s1[cnt] = '\0';
	return (copy_s1);
}
