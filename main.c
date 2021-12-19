/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:19:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/19 11:57:21 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	grafice(t_data data)
{
	data.win_ptr = mlx_new_window(data.mlx_ptr, ft_width(data.map) * 64,
			ft_height(data.map) * 64, "./so_long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		printf("ERROR \n error the programme");
	}
	ft_designe_game(data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, (1L << 0), ft_exit, &data);
	mlx_loop(data.mlx_ptr);
}

void	maps_checked(t_data data)
{
	if (ft_width(data.map) == ft_height(data.map))
		printf("ERROR \n maps");
	else if (cherche_map(data.map, 'P') != 1)
		printf("ERROR \n i need the player\n");
	else if (ft_mapfermer(data.map) == 0)
		printf("ERROR \nmap not work\n");
	else if (check_mab_caracter(data.map) == -1)
		printf("ERROR \nthe caractere does not exist\n");
	else if (cherche_map(data.map, 'E') == 0)
		printf("ERROR\ni need the map exit");
	else if (cherche_map(data.map, 'C') == 0)
		printf("ERROR \ni need the collectible\n");
	else
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
		{
			printf("ERROR \n error the programme");
			exit(0);
		}
		find_player(&data);
		grafice(data);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*url;

	if (argc == 2)
	{
		data.cp = 0;
		url = argv[1];
		if (ft_strcmp(ft_strstr(url, ".ber"), ".ber") == 0)
		{
			data.map = get_map(url);
			if (!data.map)
				printf("ERROR\nerror the programme");
			maps_checked(data);
		}
		else
		{
			printf("ERROR\n file finished .ber");
			exit(0);
		}
	}
	else
		printf("ERROR \nmap doesn't work ");
	return (0);
}
