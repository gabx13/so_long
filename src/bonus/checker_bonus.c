/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:29:30 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/18 12:59:42 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.map[0][i] != WALL
			|| game->map.map[game->map.height - 1][i] != WALL)
			return (ft_printf("Error\nWall error\n"), 0);
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.map[i][0] != WALL
			|| game->map.map[i][game->map.width - 1] != WALL)
			return (ft_printf("Error\nWall error\n"), 0);
		i++;
	}
	return (1);
}

int	check_player_exit_col(t_game *game)
{
	if (game->player.count != 1)
		return (ft_printf("Error\nPlayer error\n"), 0);
	if (game->map.exit.count != 1)
		return (ft_printf("Error\nExit error\n"), 0);
	if (game->map.collectibles < 1)
		return (ft_printf("Error\nNot enough collectibles\n"), 0);
	return (1);
}

void	get_player_ex_coll(t_game *game, char c, int i)
{
	if (c == PLAYER)
	{
		game->player.x = i;
		game->player.y = game->map.height;
		game->player.count++;
	}
	if (c == EXIT)
	{
		game->map.exit.x = i;
		game->map.exit.y = game->map.height;
		game->map.exit.count++;
	}
	if (c == COLL)
		game->map.collectibles++;
}

int	check_lines(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != WALL && line[i] != FLOOR
			&& line[i] != COLL && line[i] != ENEMY
			&& line[i] != EXIT && line[i] != PLAYER && line[i] != '\n')
			return (ft_printf("Error\nWrong symbol\n"), 0);
		get_player_ex_coll(game, line[i], i);
		i++;
	}
	if (game->map.width == -1)
		game->map.width = i - 1;
	else if (game->map.width != i - 1)
		return (ft_printf("Error\nWrong line lenght\n"), 0);
	return (1);
}

int	check_input(char *argv, t_game *game)
{
	initialize(game);
	if (!check_name(argv))
		return (ft_printf("Error\nFile name is NOT correct\n"), 1);
	get_map_size(argv, game);
	if (game->map.height == -1)
		return (1);
	if (game->map.height < 3 || game->map.width < 3
		|| game->map.height * game->map.width < 15)
		return (ft_printf("Error\nMap size error\n"), 1);
	if (check_player_exit_col(game) == 0)
		return (1);
	parse_map(argv, game);
	if (check_walls(game) == 0)
		return (free_map(game), 1);
	if (!map_is_playable(game))
		return (free_map(game), 1);
	return (ft_printf("%sLETS GOO%s!\n", GREEN, NONE), 0);
}
