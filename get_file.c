/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdelmo <aabdelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:36:05 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/12 20:38:29 by aabdelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *result)
{
	int i;

	if (result == NULL)
		return (0);
	i = 0;
	while (result[i])
		i++;
	return (i);
}
void ft_join(char *str, char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;

	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	ft_join(str, s1, s2);
	free(s1);
	return (str);
}
char *get_file(int fd)
{
	char *line = NULL;
	char *buffer = NULL;
	int a;

	buffer = (char *)malloc(sizeof(char) * 2);
	if (!buffer)
		return (NULL);
	while (1)
	{
		a = read(fd, buffer, 1);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (a == 0)
			break;
		buffer[1] = 0;
		if (buffer[0] == '\0')
			break;
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}
char **get_map(char *url)
{
	int fd;
	char **res;
	char *file;

	fd = open(url, O_RDONLY);
	file = get_file(fd);
	if (fd < 0)
		return (NULL);
	res = ft_split(file, '\n');
	return (res);
}