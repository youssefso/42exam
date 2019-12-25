#include "stdio.h"
#include "unistd.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return i;
}

int		check_cases(char **tab, int y, int x, int len)
{
	int i, j;

	i = x;
	j = y;
	while (j > 0)
	{
		if (tab[j - 1][i] == 'Q' || tab[j - 1][i] == 'R')
			return 1;
		if (tab[j - 1][i] == 'B' || tab[j - 1][i] == 'P')
			break;
		j--;
	}
	j = y;
	while (j < len)
	{
		if (tab[j + 1][i] == 'Q' || tab[j + 1][i] == 'R')
			return 1;
		if (tab[j + 1][i] == 'B' || tab[j + 1][i] == 'P')
			break;
		j++;
	}
	i = x;
	j = y;
	while (i < len)
	{
		if (tab[j][i + 1] == 'Q' || tab[j][i + 1] == 'R')
			return 1;
		if (tab[j][i + 1] == 'B' || tab[j][i + 1] == 'P')
			break;
		i++;
	}
	i = x;
	while (i > 0)
	{
		if (tab[j][i - 1] == 'Q' || tab[j][i - 1] == 'R')
			return 1;
		if (tab[j][i - 1] == 'B' || tab[j][i - 1] == 'P')
			break;
		i--;
	}
	////////////////////////////////////
	i = x;
	j = y;
	if (j < len && i > 0 && tab[j + 1][i - 1] == 'P')
		return 1;
	if (j < len && tab[j + 1][i + 1] == 'P')
		return 1;
	while (j > 0 && i > 0)
	{
		if (tab[j - 1][i - 1] == 'B' || tab[j - 1][i - 1] == 'Q')
			return 1;
		if (tab[j - 1][i - 1] == 'P' || tab[j - 1][i - 1] == 'R')
			break;
		j--;
		i--;
	}
	i = x;
	j = y;
	while (j < len && i > 0)
	{
		if (tab[j + 1][i - 1] == 'B' || tab[j + 1][i - 1] == 'Q')
			return 1;
		if (tab[j + 1][i - 1] == 'P' || tab[j + 1][i - 1] == 'R')
			break;
		j++;
		i--;
	}
	i = x;
	j = y;
	while (j < len && i < len)
	{
		if (tab[j + 1][i + 1] == 'B' || tab[j + 1][i + 1] == 'Q')
			return 1;
		if (tab[j + 1][i + 1] == 'P' || tab[j + 1][i + 1] == 'R')
			break;
		j++;
		i++;
	}
	i = x;
	j = y;
	while (j > 0 && i < len)
	{
		if (tab[j - 1][i + 1] == 'B' || tab[j - 1][i + 1] == 'Q')
			return 1;
		if (tab[j - 1][i + 1] == 'P' || tab[j - 1][i + 1] == 'R')
			break;
		j--;
		i++;
	}
	return 0;
}

int		check_map(char **tab)
{
	int x;
	int y;
	int len;

	len = ft_strlen(tab[1]);
	y = 1;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'K')
			{
				if (check_cases(tab, y, x, len))
				{
					return 1;
				}
				else
					break;
			}
			x++;
		}
		y++;
	}
	return 0;
}

int main(int ac, char **av)
{
	int a;
	char **tab;

	if (ac > 1)
	{
		if (check_map(av))
			write(1, "Fail\n", 5);
		else
			write(1, "Succes\n", 7);
	}
	else
		write(1, "\n", 1);
}
