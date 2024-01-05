/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:57:27 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/05 16:17:47 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_init(t_game *game)
{
	game->player.collected = 0;
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/bush.xpm",
			&game->img.width, &game->img.height);
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/road.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_l = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-l.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_r = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-r.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_u = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-u.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_d = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-d.xpm",
			&game->img.width, &game->img.height);
	game->img.exit_o_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/finish.xpm",
			&game->img.width, &game->img.height);
	textures2(game);
}

void	textures2(t_game *game)
{
	game->img.exit_c_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/start.xpm",
			&game->img.width, &game->img.height);
	game->img.collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/star3.xpm",
			&game->img.width, &game->img.height);
	game->img.enemy_img1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/police-b.xpm",
			&game->img.width, &game->img.height);
	game->img.enemy_img2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/police-r.xpm",
			&game->img.width, &game->img.height);
	game->img.tracks_d = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tracks-d.xpm",
			&game->img.width, &game->img.height);
	game->img.tracks_l = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tracks-l.xpm",
			&game->img.width, &game->img.height);
	game->img.tracks_r = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tracks-r.xpm",
			&game->img.width, &game->img.height);
	textures3(game);
}

void	textures3(t_game *game)
{
	game->img.tracks_u = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tracks-u.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_ln = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-ln.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_rn = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-rn.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_un = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-un.xpm",
			&game->img.width, &game->img.height);
	game->img.player_img_dn = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/car-dn.xpm",
			&game->img.width, &game->img.height);
	game->img.fire1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire1.xpm",
			&game->img.width, &game->img.height);
	game->img.fire2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire2.xpm",
			&game->img.width, &game->img.height);
	textures4(game);
}

void	textures4(t_game *game)
{
	game->img.fire3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire3.xpm",
			&game->img.width, &game->img.height);
	game->img.fire4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire4.xpm",
			&game->img.width, &game->img.height);
	game->img.fire5 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire5.xpm",
			&game->img.width, &game->img.height);
	game->img.fire6 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire6.xpm",
			&game->img.width, &game->img.height);
	game->img.fire7 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire7.xpm",
			&game->img.width, &game->img.height);
	game->img.fire8 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/fire8.xpm",
			&game->img.width, &game->img.height);
	game->img.star_c = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/c-star.xpm",
			&game->img.width, &game->img.height);
}
