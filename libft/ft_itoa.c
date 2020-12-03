/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:09:59 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/06 23:35:44 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_digits(int n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		cnt++;
		if (n /= 10)
			cnt++;
		n *= -1;
	}
	while (n /= 10)
		cnt++;
	return (cnt);
}

static void	set_nbr(int n, char *s, int index)
{
	if (n < 0)
	{
		s[0] = '-';
		if (n <= -10)
			set_nbr((n / 10) * -1, s, index - 1);
		s[index] = "0123456789"[(n % 10) * -1];
	}
	else
	{
		if (n >= 10)
			set_nbr(n / 10, s, index - 1);
		s[index] = "0123456789"[n % 10];
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		cnt;

	cnt = cnt_digits(n);
	s = (char*)ft_calloc(cnt + 1, sizeof(char));
	if (!s)
		return (NULL);
	s[cnt] = '\0';
	set_nbr(n, s, cnt - 1);
	return (s);
}
