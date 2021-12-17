/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 14:40:53 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps_check(t_data data)
{
	if (cherche_map(data.map, 'P') != 1)
		perror("player exist pas");
	else if (ft_mapfermer(data.map) == 0)
		perror("maps not fermer");
	else if (check_mab_caracter_bonus(data.map) == -1)
		perror("des caracter de maps not exist");
	else if (cherche_map(data.map, 'F') != 1)
		perror("maps contiant just 1 annimation");
	else
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			perror("aups");
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
				perror("error maps");
				return (0);
			}
			maps_check(data);
		}
		else
			perror("error maps");
	}
	else
		perror("error");
}
