/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:23:44 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:25:08 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	parse_line(char *line, t_dlist **piece, int i, int piecex)
{
	int		j;
	t_pos	tmp;

	j = 0;
	while (line[j] && j < piecex)
	{
		if (line[j] == '*')
		{
			tmp.y = i;
			tmp.x = j;
			ft_dlstprepend(piece, ft_dlstnew(&tmp, sizeof(tmp)));
		}
		++j;
	}
	return (j == piecex);
}

t_dlist		*parse_piece(t_pos *dim)
{
	t_dlist		*piece;
	char		*line;
	int			i;

	if (!get_dim(&dim->y, &dim->x))
		return (NULL);
	piece = NULL;
	i = 0;
	line = NULL;
	while (i < dim->y && get_next_line(0, &line) == 1)
	{
		if (!parse_line(line, &piece, i, dim->x))
		{
			free(line);
			ft_dlstdel(&piece, free_block);
			return (NULL);
		}
		free(line);
		i += 1;
	}
	if (i != dim->y)
		ft_dlstdel(&piece, free_block);
	return (piece);
}
