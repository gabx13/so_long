/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:31:16 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/18 12:56:50 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		game->map.height = i;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_lines(line, game) == 0)
			return (free(line), 1);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}

void	get_map_size(char *name, t_game *game)
{
	int		fd;
	int		flag;

	flag = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit(1);
	flag = read_map(game, fd);
	if (flag == 1)
	{
		game->map.height = -1;
	}
}

char	**ft_map_copy(t_game *game)
{
	char	**map_cpy;
	int		i;

	map_cpy = (char **)malloc((game->map.height + 1) * sizeof(char *));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		map_cpy[i] = ft_strdup(game->map.map[i]);
		if (!map_cpy[i])
			return (free_array(map_cpy), NULL);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	map_is_playable(t_game *game)
{
	char	**map_copy;

	if (game->map.height > 80 || game->map.width > 80)
		return (ft_printf("Error\nMap is too big\n"), 0);
	map_copy = ft_map_copy(game);
	flood_fill(game, map_copy, game->player.x, game->player.y);
	free_array(map_copy);
	if (game->map.collectibles != game->player.collected)
		return (ft_printf("Error\nNot all collectibles are reachable\n"), 0);
	if (game->map.exit.open != 1)
		return (ft_printf("Error\nExit is not reachable\n"), 0);
	game->map.exit.open = 0;
	return (1);
}

int	check_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (i < 5)
		return (0);
	if (name[i - 1] == 'r' && name[i - 2] == 'e'
		&& name[i - 3] == 'b' && name[i - 4] == '.' && ft_isprint(name[i - 5]))
		return (1);
	return (0);
}
