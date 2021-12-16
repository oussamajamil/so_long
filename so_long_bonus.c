/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:45:30 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 14:11:22 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_img_bonus(t_data data, int i, int j, char *url)
{
	int width = 64;
	int height = 64;
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, url, &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, 40 + i * 64);
}

int ft_designe_game_bonus(t_data data)
{
	int a;
	int b;
	int i;
	int j;

	a = ft_width(data.map);
	b = ft_height(data.map);

	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			if (data.map[i][j] == '1')
				put_img_bonus(data, i, j, "./assets/images/wall.xpm");
			if (data.map[i][j] == 'P')
				put_img_bonus(data, i, j, "./assets/images/mario.xpm");
			if (data.map[i][j] == 'C')
				put_img_bonus(data, i, j, "./assets/images/Money.xpm");
			if (data.map[i][j] == 'E')
				put_img_bonus(data, i, j, "./assets/images/Homme.xpm");
			if (data.map[i][j] == 'F')
				put_img_bonus(data, i, j, "./assets/images/ghost_face.xpm");
			j++;
		}
		i++;
	}
	return (0);
}
void ft_grafic_bonnus(t_data data)
{
	data.win_ptr = mlx_new_window(data.mlx_ptr, ft_width(data.map) * 64, (ft_height(data.map) * 64) + 40, "./so_long");
	ft_designe_game_bonus(data);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 10, 0xFFFFFF, "0");
	mlx_hook(data.win_ptr, 2, (1L << 0), key_hook_bonus, &data);
	mlx_hook(data.win_ptr, 17, (1L << 0), ft_exit, &data);
	mlx_loop_hook(data.mlx_ptr, key_loop_hook, &data);
	mlx_loop(data.mlx_ptr);
}
