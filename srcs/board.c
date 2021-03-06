/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:26:52 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:24:26 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_dim(int *dimy, int *dimx)
{
	char *line;
	char *tmp;

	if (get_next_line(0, &line) != 1)
		return (0);
	tmp = line;
	while (tmp && !ft_isdigit(*tmp))
		++tmp;
	*dimy = ft_atoi(tmp);
	while (tmp && ft_isdigit(*tmp))
		++tmp;
	*dimx = ft_atoi(tmp);
	free(line);
	return (*dimx && *dimy);
}

static int	parse_line(int **board, char *tmp, int i, int dimx)
{
	int j;

	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == '.')
			board[i][j] = 0;
		else if (tmp[j] == 'O' || tmp[j] == 'o')
			board[i][j] = 1;
		else if (tmp[j] == 'X' || tmp[j] == 'x')
			board[i][j] = 2;
		else
			return (0);
		++j;
	}
	return (j == dimx);
}

static int	parse_board(int **board, int dimx, int dimy)
{
	char	*line;
	int		i;

	i = 0;
	while (i < dimy && get_next_line(0, &line) == 1)
	{
		if (ft_strlen(line) < 5
			|| !(board[i] = (int *)malloc(sizeof(int) * dimx))
			|| !parse_line(board, line + 4, i, dimx))
		{
			free(line);
			return (0);
		}
		free(line);
		++i;
	}
	return (i == dimy);
}

void		del_board(int **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		++i;
	}
	free(board);
}

int			**init_board(int *dimx, int *dimy)
{
	int		**board;
	char	*line;
	int		i;

	if (!get_dim(dimy, dimx)
		|| !(board = (int **)malloc(sizeof(int *) * (*dimy + 1))))
		return (NULL);
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i <= *dimy)
		board[i++] = NULL;
	if (!parse_board(board, *dimx, *dimy))
	{
		del_board(board);
		return (NULL);
	}
	return (board);
}
