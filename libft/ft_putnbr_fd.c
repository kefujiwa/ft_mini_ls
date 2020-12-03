/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 01:13:46 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/07/09 00:11:19 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n <= -10)
			ft_putnbr_fd((n / 10) * -1, fd);
		ft_putchar_fd("0123456789"[(n % 10) * -1], fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd("0123456789"[n % 10], fd);
	}
}
