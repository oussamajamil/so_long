/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouvment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:23:14 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 09:33:56 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_increment_cp(t_data *data)
{
	data->cp += 1;
	printf("%d\n", data->cp);
}

void	ft_ouverx(t_data *data, int a)
{
	if (a != 0)
	{
		if (data->map[data->y][data->x + a] == 'E'
			&& cherche_map(data->map, 'C') == 0)
		{
			ft_increment_cp(data);
			data->map[data->y][data->x + a] = 'E';
			data->map[data->y][data->x] = '0';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			ft_designe_game(*data);
			find_player(data);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			exit(0);
		}
		if (data->map[data->y][data->x + a] == '0'
			|| data->map[data->y][data->x + a] == 'C')
		{
			ft_increment_cp(data);
			data->map[data->y][data->x + a] = 'P';
			data->map[data->y][data->x] = '0';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			ft_designe_game(*data);
			find_player(data);
		}
	}
}

void	ft_ouvery(t_data *data, int a)
{
	if (a != 0)
	{
		if (data->map[data->y + a][data->x] == 'E'
			&& cherche_map(data->map, 'C') == 0)
		{
			ft_increment_cp(data);
			data->map[data->y + a][data->x] = 'E';
			data->map[data->y][data->x] = '0';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			ft_designe_game(*data);
			find_player(data);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			exit(0);
		}
		if (data->map[data->y + a][data->x] == '0'
			|| data->map[data->y + a][data->x] == 'C')
		{
			ft_increment_cp(data);
			data->map[data->y + a][data->x] = 'P';
			data->map[data->y][data->x] = '0';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			ft_designe_game(*data);
			find_player(data);
		}
	}
}

int	key_hook(int key, t_data *data)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (key == D_KEY)
		ft_ouverx(data, 1);
	if (key == A_KEY)
		ft_ouverx(data, -1);
	if (key == W_KEY)
		ft_ouvery(data, -1);
	if (key == S_KEY)
		ft_ouvery(data, +1);
	return (0);
}

void	find_player(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i] != NULL)
	{
		j = 0;
		while (m->map[i][j] != '\0')
		{
			if (m->map[i][j] == 'P')
			{
				m->x = j;
				m->y = i;
			}
			j++;
		}
		i++;
	}
}
