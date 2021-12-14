/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:19:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/14 13:08:01 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int main(int argc, char *argv[])
{
	t_data data;
	char *url;
	if (argc == 2)
	{
		url = argv[1];
		if (ft_strcmp(ft_strstr(url, ".ber"), ".ber") == 0)
		{
			data.map = get_map(url);
			if (cherche_map(data.map, 'P') == 1 && cherche_map(data.map, 'C') > 0 && ft_mapfermer(data.map) == 1)
			{
				find_player(&data);
				data.mlx_ptr = mlx_init();
				if (data.mlx_ptr == NULL)
					return (0);
				data.win_ptr = mlx_new_window(data.mlx_ptr, ft_width(data.map) * 64, ft_height(data.map) * 64, "./so_long");
				ft_designe_game(data);
				mlx_key_hook(data.win_ptr, key_hook, &data);
				mlx_loop(data.mlx_ptr);
			}
			else
				perror("error maps");
		}
		else
			exit(0);
	}
}
