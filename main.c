/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:19:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/13 15:04:32 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int cherche_map(char **res, char c)
{
	int i;
	int j;

	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (-1);
}
void ft_ouvery(t_data *data, int a)
{
	if (a != 0)
	{
		printf("%d\n", cherche_map(data->map, 'C'));
		if (data->map[data->y - a][data->x] == '0' || data->map[data->y - a][data->x] == 'E' || data->map[data->y - a][data->x] == 'C')
		{
			if (data->map[data->y - a][data->x] == '0' || data->map[data->y - a][data->x] == 'C')
			{
				data->map[data->y - a][data->x] = 'P';
				data->map[data->y][data->x] = '0';
				mlx_clear_window(data->mlx_ptr, data->win_ptr);
				ft_designe_game(*data);
				find_player(data);
			}
			if (data->map[data->y][data->x] == 'E' && cherche_map(data->map, 'C') == -1)
			{
				data->map[data->y - a][data->x] = 'P';
				data->map[data->y][data->x] = '0';
				mlx_clear_window(data->mlx_ptr, data->win_ptr);
				ft_designe_game(*data);
				find_player(data);
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
				exit(0);
			}
		}
	}
}
void ft_ouverx(t_data *data, int a)
{
	if (a != 0)
	{
		printf("%d\n", cherche_map(data->map, 'C'));
		if (data->map[data->y][data->x + a] == '0' || data->map[data->y][data->x] == 'E' || data->map[data->y][data->x + a] == 'C')
		{
			if (data->map[data->y][data->x + a] == '0' || data->map[data->y][data->x + a] == 'C')
			{
				data->map[data->y][data->x] = '0';
				mlx_clear_window(data->mlx_ptr, data->win_ptr);
				ft_designe_game(*data);
				find_player(data);
			}
			if (data->map[data->y][data->x] == 'E' && cherche_map(data->map, 'C') == -1)
			{
				data->map[data->y][data->x] = '0';
				mlx_clear_window(data->mlx_ptr, data->win_ptr);
				ft_designe_game(*data);
				find_player(data);
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
				exit(0);
			}
		}
	}
}
int key_hook(int key, t_data *data)
{
	int a;
	int p;
	char **res;
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
		ft_ouvery(data, 1);
	if (key == S_KEY)
		ft_ouvery(data, -1);
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

int main(int argc, char *argv[])
{
	t_data data;
	char *url;
	if (argc == 2)
	{
		url = argv[1];
		if (ft_strcmp(ft_strstr(url, ".ber"), ".ber") == 0)
		{
			data.map = get_map(url);
			find_player(&data);
			if (ft_mapfermer(data.map) == 1)
			{
				data.mlx_ptr = mlx_init();
				if (data.mlx_ptr == NULL)
					return (0);
				data.win_ptr = mlx_new_window(data.mlx_ptr, ft_width(data.map) * 64, ft_height(data.map) * 64, "./so_long");
				ft_designe_game(data);
				mlx_key_hook(data.win_ptr, key_hook, &data);
				mlx_loop(data.mlx_ptr);
			}
			else
			{
				printf("%s", "error");
			}
		}
		else
			exit(0);
	}
}
