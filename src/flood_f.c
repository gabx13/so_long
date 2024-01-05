/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:32:20 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 23:15:36 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == COLL)
		game->player.collected++;
	if (map[y][x] == EXIT)
		game->map.exit.open = 1;
	map[y][x] = '.';
	if (y - 1 > 0 && (map[y - 1][x] == FLOOR || map[y - 1][x] == COLL
		|| map[y - 1][x] == EXIT))
		flood_fill(game, map, x, y - 1);
	if ((y < game->map.height - 1) && (map[y + 1][x] == FLOOR
		|| map[y + 1][x] == COLL || map[y + 1][x] == EXIT))
		flood_fill(game, map, x, y + 1);
	if (x > 0 && ((map[y][x - 1] == FLOOR) || (map[y][x - 1] == COLL
		|| map[y][x - 1] == EXIT)))
		flood_fill(game, map, x - 1, y);
	if ((x < game->map.width - 1) && ((map[y][x + 1] == FLOOR)
		|| (map[y][x + 1] == COLL) || map[y][x + 1] == EXIT))
		flood_fill(game, map, x + 1, y);
}
