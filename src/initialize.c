/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:30:43 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 19:32:48 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_game *game)
{
	game->map.width = -1;
	game->map.height = 0;
	game->map.map = NULL;
	game->map.line = NULL;
	game->map.collectibles = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	game->player.alive = 1;
	game->player.count = 0;
	game->player.collected = 0;
	game->player.prev_x = 0;
	game->player.prev_y = 0;
	game->player.movement = 3;
	game->player.move_dir = 1;
	game->map.exit.open = 0;
	game->map.exit.count = 0;
	game->counter = 0;
	initialize_img(game);
}

void	initialize_img(t_game *game)
{
	game->img.wall_img = NULL;
	game->img.wall_img = NULL;
	game->img.floor_img = NULL;
	game->img.player_img_d = NULL;
	game->img.player_img_l = NULL;
	game->img.player_img_r = NULL;
	game->img.player_img_u = NULL;
	game->img.enemy_img1 = NULL;
	game->img.enemy_img2 = NULL;
	game->img.collectible_img = NULL;
	game->img.exit_c_img = NULL;
	game->img.exit_o_img = NULL;
	game->img.star_c = NULL;
	game->img.fire1 = NULL;
	game->img.fire2 = NULL;
	game->img.fire3 = NULL;
	game->img.fire4 = NULL;
	game->img.fire5 = NULL;
	game->img.fire6 = NULL;
	game->img.fire7 = NULL;
	game->img.fire8 = NULL;
}
