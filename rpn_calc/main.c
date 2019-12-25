#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"


void	b_zero(int s[5])
{
	int i;

	i = 0;
	while (i < 5)
		s[i++] = 0;
}

int	f_isnum(char c)
{
	if (c >= '0' && c <= '9')
	   return 1;	
	return 0;
}
int	f_isop(char c)
{
	if (c == '%' ||c == '-' ||c == '+' ||c == '*' ||c == '/')
		return 1;
	return 0;
}
int	do_op(int s[5], int *j, char c)
{
	int i, num;

	i = *j;
	if (c == '*')	
		s[i - 2] = s[i - 1] * s[i - 2];
	if (c == '%')	
	{
		if (s[i - 1] == '0') return 1;
		s[i - 2] = s[i - 1] % s[i - 2];
	}
	if (c == '/')	
	{
		if (s[i - 1] == '0') return 1;
		s[i - 2] = s[i - 1] / s[i - 2];
	}
	if (c == '-')	
		s[i - 2] = s[i - 1] - s[i - 2];
	if (c == '+')	
		s[i - 2] = s[i - 1] + s[i - 2];
	s[i - 1] = 0;
	*j = *j - 1;
	return 0;
}

int	check_nprint(int s[5])
{
	if (s[1] == 0 && s[2] == 0 && s[3] == 0)
	{
		printf("%d\n", s[0]);
		return 0;
	}
	return 1;
}

int	rpn_calc(char *str)
{
	int stack[5];
	int i,j,check;

	b_zero(stack);
	i = 0;
	j = 0;
	check = 0;
	while (str[i])
	{
		if (f_isnum(str[i]))
		{
			stack[j++] = atoi(str + i);
			while (str[i] && str[i] != ' ')
			i++;
		}
		if (f_isop(str[i]))
		{
			check = 1;
			if (j < 2 || do_op(stack, &j, str[i]))
				return 1;
		}
		if (str[i] != 0)
			i++;
	}
	if (!check || j > 1 || check_nprint(stack))
		return 1;
	return 0;
}
int main(int ac, char **av)
{
	if (ac != 2)
		printf("Error\n");
	else
		if (rpn_calc(av[1]))
			printf("Error\n");
	return 0;
}
