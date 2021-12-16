/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 13:18:49 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (cherche_map(data.map, 'P') == 1 && cherche_map(data.map, 'C') > 0 && ft_mapfermer(data.map) == 1)
			{
				find_player(&data);
				data.mlx_ptr = mlx_init();
				if (data.mlx_ptr == NULL)
					perror("aups");
				ft_grafic_bonnus(data);
				free(data.map);
			}
			else
				perror("error maps");
		}
		else
			exit(0);
	}
}
