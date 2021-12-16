/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mouvement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:30:20 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 16:14:32 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_mouvement_bonus(t_data *data, int a, int b)
{
	char *c;
	if (a != 0)
	{
		data->cp += 1;
		c = ft_itoa(data->cp);
		data->map[data->y][data->x + a] = 'P';
		data->map[data->y][data->x] = '0';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, c);
		ft_designe_game_bonus(*data);
		find_player(data);
	}
	if (b != 0)
	{
		data->cp += 1;
		c = ft_itoa(data->cp);
		data->map[data->y + b][data->x] = 'P';
		data->map[data->y][data->x] = '0';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, c);
		ft_designe_game_bonus(*data);
		find_player(data);
	}
	free(c);
}

void ft_ouverx(t_data *data, int a)
{
	if (a != 0)
	{
		if ((data->map[data->y][data->x + a] == 'E' && cherche_map(data->map, 'C') == 0) || data->map[data->y + a][data->x] == 'F')
		{
			ft_mouvement_bonus(data, a, 0);
			ft_exit(data);
		}
		if (data->map[data->y][data->x + a] == '0' || data->map[data->y][data->x + a] == 'C')
			ft_mouvement_bonus(data, a, 0);
	}
}
void ft_ouvery(t_data *data, int a)
{
	if (a != 0)
	{
		if ((data->map[data->y + a][data->x] == 'E' && cherche_map(data->map, 'C') == 0) || data->map[data->y + a][data->x] == 'F')
		{
			ft_mouvement_bonus(data, 0, a);
			ft_exit(data);
		}
		if (data->map[data->y + a][data->x] == '0' || data->map[data->y + a][data->x] == 'C')
			ft_mouvement_bonus(data, 0, a);
	}
}

int key_hook_bonus(int key, t_data *data)
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

void find_player(t_data *m)
{
	int i;
	int j;

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