/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:07:28 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/11 13:24:35 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **get_map(char *url)
{
	int fd;
	char **res;
	char *file;

	fd = open(url, O_RDONLY);
	file = get_file(fd);
	if (fd < 0)
		return (NULL);
	res = ft_split(file, '\n');
	return (res);
}
// int key_hook(int key, t_data *data)
// {

// 	if (key == W_KEY)
// 		data->rec.y -= w;
// 	// if (key == S_KEY)
// 	// data->rec.y += 10;
// 	// if (key == A_KEY)
// 	// data->rec.x -= 10;
// 	// if (key == D_KEY)
// 	// data->rec.x += 10;

//  	ft_designe_game()
//  return (0);

// }

int ft_designe_game(t_data data, char **res)
{
	int a;
	int b;
	int i;
	int j;

	a = ft_width(res);
	b = ft_height(res);
	int width = 64;
	int height = 64;
	i = 0;
	while (i < b)
	{
		j = 0;
		while (j < a)
		{
			if (res[i][j] == '1')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/wall.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			if (res[i][j] == 'P')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/mario.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			if (res[i][j] == 'C')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/images/Money.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, j * 64, i * 64);
			}
			if (res[i][j] == 'E')
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