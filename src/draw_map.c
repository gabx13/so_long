/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:44:30 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 19:29:10 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_text(t_game *game)
{
	char	*str;
	char	*str1;

	str1 = "Moves: ";
	str = ft_itoa(game->player.moves);
	put_img(game, game->img.star_c, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 33, 0xFFFFFF, str1);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 28, 46, 0xFFFFFF, str);
	free(str);
	return (1);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		close_program(game);
	if (keysym == KEY_A || keysym == KEY_LEFT)
		keypress_action(game, 0, -1, 1);
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		keypress_action(game, 0, 1, 2);
	else if (keysym == KEY_W || keysym == KEY_UP)
		keypress_action(game, -1, 0, 3);
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		keypress_action(game, 1, 0, 4);
	put_img(game, game->img.star_c, 0, 0);
	draw_text(game);
	return (1);
}

void	put_right_image(t_game *game, char c, int j, int i)
{
	if (c == WALL)
		put_img(game, game->img.wall_img, j, i);
	else if (c == FLOOR)
		put_img(game, game->img.floor_img, j, i);
	else if (c == PLAYER)
		car_move(game);
	else if (c == COLL)
		put_img(game, game->img.collectible_img, j, i);
	else if (c == ENEMY)
		enemy_loop(game, j, i);
	if (game->map.map[game->map.exit.y][game->map.exit.x] != PLAYER)
	{
		game->map.map[game->map.exit.y][game->map.exit.x] = EXIT;
		if (game->map.exit.open)
			put_img(game, game->img.exit_o_img, game->map.exit.x,
				game->map.exit.y);
		else
			put_img(game, game->img.exit_c_img, game->map.exit.x,
				game->map.exit.y);
	}
}

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	game->map.map[0][0] = 'a';
	i = 0;
	while (i < game->map.height && game->player.alive == 1)
	{
		j = 0;
		while (j < game->map.width)
		{
			put_right_image(game, game->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
	if (game->map.collectibles == game->player.collected)
		game->map.exit.open = 1;
	if (game->player.alive == 0)
	{
		explosion_loop(game, game->player.x, game->player.y);
		explosion_loop(game, game->player.prev_x, game->player.prev_y);
	}
	counter(game);
	return (1);
}

void	make_map(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, IMG_SIZE * game->map.width,
			IMG_SIZE * game->map.height, "so_long_so_furious");
	textures_init(game);
	mlx_hook(game->win_ptr, 12, 1L << 15, draw_text, game);
	mlx_hook(game->win_ptr, 2, 1, handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 0, close_program, game->mlx_ptr);
	mlx_loop_hook(game->mlx_ptr, draw_map, (void *)game);
	mlx_loop(game->mlx_ptr);
}
