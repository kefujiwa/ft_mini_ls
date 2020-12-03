/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:08:42 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/10/05 21:09:04 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	calc_atoi(const char *str, int sign, unsigned long num,
unsigned long max)
{
	while (ft_isdigit(*str))
	{
		if (num < max / 10 || (num == max / 10 && *str - '0' <= 7))
			num = num * 10 + (*str - '0');
		else
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		str++;
	}
	return ((int)num * sign);
}

int			ft_atoi(const char *str)
{
	unsigned long	num;
	unsigned long	max;
	int				sign;

	num = 0;
	max = 9223372036854775807;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '+' ? 1 : -1);
		str++;
	}
	return (calc_atoi(str, sign, num, max));
}
