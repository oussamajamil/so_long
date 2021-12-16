/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:07:28 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 16:35:52 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void put_img(t_data data, int i, int j, char *url)
{
	int width = 64;
	int height = 64;
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, url, &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
}
int ft_designe_game(t_data data)
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
				put_img(data, i, j, "./assets/images/wall.xpm");
			if (data.map[i][j] == 'P')
				put_img(data, i, j, "./assets/images/mario.xpm");
			if (data.map[i][j] == 'C')
				put_img(data, i, j, "./assets/images/Money.xpm");
			if (data.map[i][j] == 'E')
				put_img(data, i, j, "./assets/images/Homme.xpm");
			j++;
		}
		i++;
	}
	return (0);
}