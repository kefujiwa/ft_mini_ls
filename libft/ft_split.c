/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:14:02 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/06 23:36:07 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char *s, char c)
{
	int		cnt;
	char	*next_s;

	cnt = 0;
	while (*s)
	{
		next_s = s;
		next_s++;
		if (*s != c && (*next_s == c || *next_s == '\0'))
			cnt++;
		s++;
	}
	return (cnt);
}

static int	word_len(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	free_all(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**split_s(char **split, char *s, char c, int words)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		split[i] = (char*)ft_calloc(len + 1, sizeof(char));
		if (!split[i])
		{
			free_all(split, i);
			return (NULL);
		}
		j = -1;
		while (++j < len)
			split[i][j] = *(s++);
		split[i][j] = '\0';
	}
	split[i] = NULL;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		cnt;

	if (!s)
		return (NULL);
	cnt = word_cnt((char*)s, c);
	split = (char **)ft_calloc(cnt + 1, sizeof(char*));
	if (!split)
		return (NULL);
	split = split_s(split, (char*)s, c, cnt);
	return (split);
}
