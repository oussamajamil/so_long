/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:07:28 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 11:41:10 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data data, int i, int j, char *url)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, url, &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr,
		j * 64, i * 64);
	mlx_destroy_image(data.mlx_ptr, data.img_ptr);
}

int	ft_designe_game(t_data data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ft_height(data.map))
	{
		j = -1;
		while (++j < ft_width(data.map))
		{
			if (data.map[i][j] == '1')
				put_img(data, i, j, "./assets/images/wall.xpm");
			else if (data.map[i][j] == 'P')
				put_img(data, i, j, "./assets/images/mario.xpm");
			else if (data.map[i][j] == 'C')
				put_img(data, i, j, "./assets/images/Money.xpm");
			else if (data.map[i][j] == 'E')
				put_img(data, i, j, "./assets/images/Homme.xpm");
		}
	}
	return (0);
}
