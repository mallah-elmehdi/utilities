/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:53:06 by emallah           #+#    #+#             */
/*   Updated: 2020/01/22 20:03:23 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// ========= Fun-2 : Checking if we made the last case  ========= //

int		done_yet(char *lst, int n)
{

	while (n >= 0)
	{
		if (lst[n] == '1')
			return (1);
		n--;
	}
	return (0);
}

// ========= Fun-3 : lst init  ========= //

void	i_lst(char **lst, int n)
{
	*lst = (char*)malloc(sizeof(char) * (n + 1));
	lst[0][n] = '\0';
	while (n--)
		lst[0][n] = '1';
}

// ========= Fun-4 : Comparing the intput with the made calc  ========= //

/*int	check(int *pizza_type, char *lst, int m)
{
	int max;
	int i;

	max = 0;
	i = 0;
	while (lst[i] != '\0')
	{
		if (lst[i] == '1')
			max += pizza_type[i];
		i++;
	}
	if (max == m)
		return (1);
	return (0);
}*/
// ========= Fun-1 : Generate cases  ========= //

char	*bin_lst(int *pizza_type, int n, int m)
{
	char *lst;
	int i;
	int max;
	int hold = 0;
	char *lsthold;

	i_lst(&lst, n);
	while (done_yet(lst, n - 1))
	{
		i = n - 1;
		max = 0;
		while (i >= 0)
		{
			if (lst[i] == '0')
				lst[i] = '1';
			else if (lst[i] == '1')
			{
				lst[i] = '0';
				break;
			}
			i--;
		}
		i = n - 1;
		while (lst[i] != '\0')
		{
			if (lst[i] == '1')
				max += pizza_type[i];
			i--;
		}
		if (max == m)
			return (lst);
		if (max < m && max > hold)
		{
			hold = max;
			lsthold = lst;
		}
	}
	return (lsthold);
}
int main()
{
	int fd;
	FILE *fp;
	int m;
	int n;
	int i;
	int num;
	int *pizza_type;
	char *hold;

	m = 0;
	n = 0;
	i = 0;
	num = 0;
	fp = fopen ("out.txt","w");
	hold = (char*)malloc(sizeof(char) * 2);
	hold[1] = 0;
	
	fd = open("c_medium.in", O_RDONLY);
	while (read(fd, hold, 1) && *hold != ' ')
		m = (m * 10) + (*hold - 48);
	while (read(fd, hold, 1) && *hold != '\n')
		n = (n * 10) + (*hold - 48);
	pizza_type = (int*)malloc(sizeof(int) * n);
	while (read(fd, hold, 1))
	{
		if (*hold == ' ' || *hold == '\n')
		{
			pizza_type[i] = num;
			i++;
			num = 0;
		}
		else
			num = (num * 10) + (*hold - 48);
	}
	i = 0;
	hold = bin_lst(pizza_type, n, m);
	n = 0;
	while (hold[i] != '\0')
	{
		if (hold[i] == '1')
			n++;
		i++;
	}
	i = 0;
	fprintf (fp, "%d\n", n);
	while (hold[i] != '\0')
	{
		if (hold[i] == '1')
			fprintf (fp, "%d ", i);
		i++;
	}
	printf("Done!!\n");
	return (0);
}
