/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_libft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:11:20 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 16:22:18 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(char *str, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == s[j])
		{
			if (s[j + 1] == 0)
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *result)
{
	int	i;

	if (result == NULL)
		return (0);
	i = 0;
	while (result[i])
		i++;
	return (i);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	exit(0);
	return (0);
}

int	cherche_map(char **res, char c)
{
	int	i;
	int	j;
	int	cp;

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
