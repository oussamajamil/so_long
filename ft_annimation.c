/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annimation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:51:15 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 12:55:01 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int ft_x_position(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'F')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}
int ft_y_position(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'F')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int key_loop_hook(t_data *data)
{
	int i;
	int j;
	char *a;

	a = ft_itoa(data->cp);
	i = ft_y_position(data);
	j = ft_x_position(data);
	if (data->left_orright_annimation == 0)
	{
		if (data->map[i][j - 1] == 'P')
		{
			data->map[i][j] = 'F';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, a);
			ft_designe_game_bonus(*data);
			ft_exit(data);
		}
		if (data->map[i][j - 1] == '0')
		{
			data->map[i][j] = '0';
			data->map[i][j - 1] = 'F';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, a);
			ft_designe_game_bonus(*data);
		}
		else
			data->left_orright_annimation = 1;
	}

	if (data->left_orright_annimation == 1)
	{
		if (data->map[i][j + 1] == 'P')
		{
			data->map[i][j] = 'F';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, a);
			ft_designe_game_bonus(*data);
			ft_exit(data);
		}
		if (data->map[i][j + 1] == '0')
		{
			data->map[i][j] = '0';
			data->map[i][j + 1] = 'F';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, a);
			ft_designe_game_bonus(*data);
		}
		else
			data->left_orright_annimation = 0;
	}
	free(a);
	return (0);
}