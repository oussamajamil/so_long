/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:19:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 18:58:28 by ojamil           ###   ########.fr       */
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
		perror("error");
	}
	ft_designe_game(data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, (1L << 0), ft_exit, &data);
	mlx_loop(data.mlx_ptr);
}

void	maps_checked(t_data data)
{
	if (ft_width(data.map) == ft_height(data.map))
		perror("ERROR \n maps");
	else if (cherche_map(data.map, 'P') != 1)
		perror("player exist pas\n");
	else if (ft_mapfermer(data.map) == 0)
		perror("maps not fermer\n");
	else if (check_mab_caracter(data.map) == -1)
		perror("des caracter de maps not exist\n");
	else if (cherche_map(data.map, 'E') == 0)
		perror("error game\n");
	else if (cherche_map(data.map, 'C') == 0)
		perror("error game\n");
	else
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			perror("error maps");
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
				perror("error maps");
			maps_checked(data);
		}
		else
			perror("file trminer .ber");
	}
	else
		perror("maps inconner");
}
