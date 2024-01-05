/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:26:51 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 23:24:03 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *name, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return ;
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.map[i] = line;
		i++;
	}
	close(fd);
}
