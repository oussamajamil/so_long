/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annimation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:51:15 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 13:59:58 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_x_position(t_data *data)
{
	int	i;
	int	j;

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

int	ft_y_position(t_data *data)
{
	int	i;
	int	j;

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

int	ft_rermplir_gams_animation(t_data *data, int a, int i, int j)
{
	char	*k;

	k = ft_itoa(data->cp);
	if (data->map[i][j + a] == 'P')
	{
		data->map[i][j + a] = 'F';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, k);
		ft_designe_game_bonus(*data);
		usleep(50000);
		ft_exit(data);
	}
	if (data->map[i][j + a] == '0')
	{
		data->map[i][j] = '0';
		data->map[i][j + a] = 'F';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, k);
		ft_designe_game_bonus(*data);
		usleep(50000);
		return (-1);
	}
	free(k);
	return (0);
}

int	key_loop_hook(t_data *data)
{
	int	i;
	int	j;

	i = ft_y_position(data);
	j = ft_x_position(data);
	if (data->left_orright_annimation == 0)
	{
		if (ft_rermplir_gams_animation(data, -1, i, j) == -1)
			return (0);
		else
			data->left_orright_annimation = 1;
	}
	if (data->left_orright_annimation == 1)
	{
		if (ft_rermplir_gams_animation(data, 1, i, j) == -1)
			return (0);
		else
			data->left_orright_annimation = 0;
	}
	return (0);
}
