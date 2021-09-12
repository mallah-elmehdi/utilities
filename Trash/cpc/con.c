/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:32:12 by emallah           #+#    #+#             */
/*   Updated: 2020/01/19 18:47:34 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int big(int c, int out, int *lst)
{
	int i;

	i = 0;
	while (i < c)
	{
		if (lst[i] >= out)
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	int c;
	int i;
	int h;
	int out;

	scanf("%d", &c);
	int lst[c];
	i = 0;
	out = 1;
	while (i < c)
	{
		scanf("%d", &lst[i]);
		i++;
	}
	i = 0;
	h = 0;
	while (1)
	{
		if (lst[i] == out)
		{
			lst[i] = lst[i] - out;
			out++;
			h = 0;
		}
		i++;
		if (i == c && (++h) && (!(i = 0)) && big(c, out, lst))
			break;
	}
	printf ("%d", (out-1));
}
