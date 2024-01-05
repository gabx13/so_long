/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:27:23 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 19:29:07 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int y, int x, int dir)
{
	if (game->map.map[game->player.y + y][game->player.x + x] != WALL &&
				game->player.alive)
	{
		game->player.prev_x = game->player.x;
		game->player.prev_y = game->player.y;
		game->map.map[game->player.y + y][game->player.x + x] = PLAYER;
		game->player.x += x;
		game->player.y += y;
		game->player.move_dir = dir;
		game->player.movement = 1;
		game->player.moves++;
		ft_printf("moves:%i, stars collected: %i/%i\n",
			game->player.moves, game->player.collected,
			game->map.collectibles);
		if (game->player.alive == 2)
		{
			game->player.alive = 0;
			ft_printf("%sWASTED%s\n", RED, NONE);
		}
	}
}

void	check_state(t_game *game, int y, int x)
{
	if (game->player.prev_x != 0)
		game->map.map[game->player.prev_y][game->player.prev_x] = FLOOR;
	if (game->map.map[game->player.y + y][game->player.x + x] == COLL)
		game->player.collected++;
	if (game->map.map[game->player.y + y][game->player.x + x] == ENEMY &&
							game->player.alive == 1)
	{
		game->counter = 0;
		game->player.alive = 2;
	}
}

void	keypress_action(t_game *game, int y, int x, int dir)
{
	check_state(game, y, x);
	move_player(game, y, x, dir);
	if (game->player.x == game->map.exit.x
		&& game->player.y == game->map.exit.y && game->map.exit.open)
	{
		ft_printf("%sYOU WIN\nYour move count: %i%s\n",
			GREEN, game->player.moves, NONE);
		exit (0);
	}
}

void	car_move(t_game *game)
{
	if (game->player.move_dir == 1)
	{
		car_animation(game, game->img.player_img_ln,
			game->img.player_img_l);
		put_img(game, game->img.tracks_l, game->player.x + 1,
			game->player.y);
	}
	else if (game->player.move_dir == 2)
	{
		car_animation(game, game->img.player_img_rn,
			game->img.player_img_r);
		put_img(game, game->img.tracks_r, game->player.x - 1,
			game->player.y);
	}
	car_move2(game);
}

void	car_move2(t_game *game)
{
	if (game->player.move_dir == 3)
	{
		car_animation(game, game->img.player_img_un,
			game->img.player_img_u);
		put_img(game, game->img.tracks_u, game->player.x,
			game->player.y + 1);
	}
	else if (game->player.move_dir == 4)
	{
		car_animation(game, game->img.player_img_dn,
			game->img.player_img_d);
		put_img(game, game->img.tracks_d, game->player.x,
			game->player.y - 1);
	}
}
