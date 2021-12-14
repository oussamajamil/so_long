#include "so_long.h"

char *ft_strstr(char *str, char *s)
{
	int i;
	int j;

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

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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