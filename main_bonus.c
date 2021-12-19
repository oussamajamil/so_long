/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/19 11:58:56 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps_check(t_data data)
{
	if (cherche_map(data.map, 'P') != 1)
		printf("ERROR \n i need the player\n");
	else if (ft_mapfermer(data.map) == 0)
		printf("ERROER\nmap doesn't work \n");
	else if (check_mab_caracter_bonus(data.map) == -1)
		printf("ERROER\nthe caractere does not exist\n");
	else if (cherche_map(data.map, 'C') == 0)
		printf("ERROR \ni need the collectible");
	else if (cherche_map(data.map, 'E') == 0)
		printf("ERROR\ni need the map exit");
	else if (ft_width(data.map) == ft_height(data.map))
		printf("ERROR \n map doesn't work");
	else
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			printf("ERROR \n error the programme");
		find_player(&data);
		ft_grafic_bonnus(data);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		data.cp = 0;
		if (ft_strcmp(ft_strstr(argv[1], ".ber"), ".ber") == 0)
		{
			data.map = get_map(argv[1]);
			if (!data.map)
			{
				printf("ERROR\nerror maps");
				exit(0);
			}
			maps_check(data);
		}
		else
		{
			printf("ERROR \nerror maps");
			exit(0);
		}
	}
	else
		printf("ERROR \n i need the map");
	return (0);
}
