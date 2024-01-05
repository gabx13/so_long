/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:24:48 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 19:25:40 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	counter(t_game *game)
{
	game->counter++;
	if (game->counter == COUNTER)
		game->counter = 0;
}

int	close_program(t_game *data)
{
	ft_printf("%sEnd of the game!%s%s", WARNING, NONE, data->mlx_ptr);
	exit(0);
}

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img,
		x * IMG_SIZE, y * IMG_SIZE);
}
