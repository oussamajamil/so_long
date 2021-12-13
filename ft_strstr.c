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