/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:15:07 by kefujiwa          #+#    #+#             */
/*   Updated: 2020/12/03 21:42:25 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MINI_LS_H
# define _FT_MINI_LS_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>

# define PATH_LS "."

typedef struct		s_flst
{
	char			*name;
	time_t			time;
	long			ntime;
	struct s_flst	*next;
}					t_flst;

void				flst_print(t_flst *lst);
void				flst_add(t_flst **lst, t_flst *new);
t_flst				*flst_new(char *name, time_t time, long ntime);
void				flst_clear(t_flst **lst);

#endif
