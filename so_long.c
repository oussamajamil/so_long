/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:07:28 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/13 12:40:20 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_designe_game(t_data data)
{
	int a;
	int b;
	int i;
	int j;

	a = ft_width(data.map);
	b = ft_height(data.map);
	int width = 64;
	int height = 64;
	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			if (data.map[i][j] == '1')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/wall.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			if (data.map[i][j] == 'P')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/mario.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			if (data.map[i][j] == 'C')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/Money.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			if (data.map[i][j] == 'E')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/Homme.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
	return (0);
}