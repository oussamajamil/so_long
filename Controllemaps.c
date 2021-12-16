/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controllemaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:03:46 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 15:27:20 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width(char **result)
{
	return (ft_strlen(result[0]));
}

int	ft_height(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		i++;
	return (i);
}

int	check_mab_caracter(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] != '0' && res[i][j] != '1' && res[i][j] != 'P' &&
				res[i][j] != 'E' && res[i][j] != 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_mab_caracter_bonus(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] != '0' && res[i][j] != '1' && res[i][j] != 'P'
			&& res[i][j] != 'F' && res[i][j] != 'E' && res[i][j] != 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_mapfermer(char **res)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = ft_height(res);
	width = ft_width(res);
	i = -1;
	while (res[++i])
	{
		if (width == ft_width(&res[i]))
		{
			j = -1;
			if (i == 0 || i == height - 1)
				while (res[i][++j])
					if (res[i][j] != '1')
						return (0);
			if (res[i][0] != '1' || res[i][width - 1] != '1')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
