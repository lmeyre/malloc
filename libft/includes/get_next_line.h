/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:08:32 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 16:27:58 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# define CNTT ((t_fd*)(lst->content))

# include "./libft.h"

typedef struct	s_fd
{
	struct s_fd	*next;
	char		*tmp;
	char		padding[4];
	int			fd;
}				t_fd;

typedef struct	s_filler
{
	int			ret;
	int			bool;
	int			boolbis;
	int			lll;
	char		*buf;
}				t_filler;

int				get_next_line(int fd, char **line);

#endif
