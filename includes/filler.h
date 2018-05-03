/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:52:26 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:22:37 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define POS(x) ((t_pos *)x->content)

typedef struct	s_board
{
	int			**board;
	int			dimx;
	int			dimy;
}				t_board;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

int				get_dim(int *dimx, int *dimy);
void			del_board(int **board);
int				**init_board(int *dimx, int *dimy);
void			print_board(int fd, int **board, int dimx);
t_dlist			*parse_piece(t_pos *origin);
void			place_piece(t_board b,
							t_dlist *piece,
							t_pos origin,
							int player);
void			free_block(void	*content, size_t content_size);

#endif
