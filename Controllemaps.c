/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controllemaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:03:46 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/15 14:07:01 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int ft_width(char **result)
{
	return (ft_strlen(result[0]));
}
int ft_height(char **result)
{
	int i;
	i = 0;
	while (result[i])
		i++;
	return (i);
}
int ft_mapfermer(char **res)
{
	int i;
	int j;
	int height;
	int width;

	height = ft_height(res);
	width = ft_width(res);
	i = 0;
	while (res[i])
	{
		if (width == ft_width(&res[i]))
		{
			j = 0;
			if (i == 0 || i == height - 1)
			{
				while (res[i][j])
				{
					if (res[i][j] != '1')
						return (0);
					j++;
				}
			}

			if (res[i][0] != '1' || res[i][width - 1] != '1')
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int cherche_map(char **res, char c)
{
	int i;
	int j;
	int cp;

	cp = 0;
	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] == c)
				cp++;
			j++;
		}
		i++;
	}
	return (cp);
}