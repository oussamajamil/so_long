#include "so_long.h"
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
		j = 0;
		if (i == 0 || i == height - 1)
		{
			while (res[i][j])
			{
				if (res[i][j] != '1')
				{

					return (0);
				}
				j++;
			}
		}
		if (res[i][0] != '1' || res[i][width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}