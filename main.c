/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:19:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 16:51:56 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void grafice(t_data data)
{
	data.win_ptr = mlx_new_window(data.mlx_ptr, ft_width(data.map) * 64, ft_height(data.map) * 64, "./so_long");
	ft_designe_game(data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, (1L << 0), ft_exit, &data);
	mlx_loop(data.mlx_ptr);
}

int main(int argc, char *argv[])
{
	t_data data;
	char *url;

	data.cp = 0;
	if (argc == 2)
	{
		url = argv[1];
		if (ft_strcmp(ft_strstr(url, ".ber"), ".ber") == 0)
		{
			data.map = get_map(url);
			if (!data.map)
				perror("error maps");
			if (cherche_map(data.map, 'P') == 1 && cherche_map(data.map, 'C') > 0 && ft_mapfermer(data.map) == 1 && cherche_map(data.map, 'E') > 0 && check_mab_caracter(data.map) == 1)
			{
				find_player(&data);
				data.mlx_ptr = mlx_init();
				if (data.mlx_ptr == NULL)
					perror("error maps");
				grafice(data);
			}
			else
				perror("error maps");
		}
		else
			exit(0);
	}
}
