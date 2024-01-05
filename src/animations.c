/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:22 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/05 16:40:08 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	car_animation(t_game *game, void *img1, void *img2)
{
	if (game->counter < (COUNTER * 0.125))
		put_img(game, img1, game->player.x, game->player.y);
	else if (game->counter > (COUNTER * 0.125) && game->counter < (COUNTER * 0.25))
		put_img(game, img2, game->player.x, game->player.y);
	else if (game->counter > (COUNTER * 0.25) && game->counter < (COUNTER * 0.375))
		put_img(game, img1, game->player.x, game->player.y);
	else if (game->counter > (COUNTER * 0.375))
		put_img(game, img2, game->player.x, game->player.y);
}

void	enemy_loop(t_game *game, int j, int i)
{
	if (game->counter < COUNTER / 2)
		put_img(game, game->img.enemy_img1, j, i);
	if (game->counter > COUNTER / 2)
		put_img(game, game->img.enemy_img2, j, i);
}

void	explosion_loop(t_game *game, int j, int i)
{
	if (game->counter < (COUNTER * 0.125))
		put_img(game, game->img.fire1, j, i);
	if (game->counter > (COUNTER * 0.125) && game->counter < (COUNTER * 0.25))
		put_img(game, game->img.fire2, j, i);
	if (game->counter > (COUNTER * 0.25) && game->counter < (COUNTER * 0.375))
		put_img(game, game->img.fire3, j, i);
	if (game->counter > (COUNTER * 0.375) && game->counter < (COUNTER * 0.5))
		put_img(game, game->img.fire4, j, i);
	if (game->counter > (COUNTER * 0.5) && game->counter < (COUNTER * 0.625))
		put_img(game, game->img.fire5, j, i);
	if (game->counter > (COUNTER * 0.625) && game->counter < (COUNTER * 0.75))
		put_img(game, game->img.fire6, j, i);
	if (game->counter > (COUNTER * 0.75) && game->counter < 0.875)
		put_img(game, game->img.fire7, j, i);
	if (game->counter > (COUNTER * 0.875) && game->counter < COUNTER - 1)
		put_img(game, game->img.fire8, j, i);
	if (game->counter == COUNTER - 1)
		close_program(game);
}
