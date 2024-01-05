/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:44:54 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/16 19:31:16 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (check_input(argv[1], &game))
			return (1);
		make_map(&game);
		free_map(&game);
	}
	else
		ft_printf("Not correct number of files provided\n");
	return (0);
}
