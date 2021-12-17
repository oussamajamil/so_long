/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:56:38 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/17 09:14:07 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_remplir(char *str, long cp, int count)
{
	if (cp == 0)
	{
		str[0] = '0';
		str[1] = 0;
	}
	if (cp < 0)
	{
		str[0] = '-';
		cp *= -1;
	}
	str[count] = 0;
	while (count - 1 >= 0 && str[count - 1] != '-')
	{
		str[count-- - 1] = '0' + (cp % 10);
		cp /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	long	cp;
	char	*str;

	cp = n;
	count = ft_count(n);
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	ft_remplir(str, cp, count);
	return (str);
}
