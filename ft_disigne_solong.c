/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disigne_solong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:03:46 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/11 11:12:51 by ojamil           ###   ########.fr       */
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
