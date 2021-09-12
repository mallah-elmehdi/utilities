/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:12:37 by emallah           #+#    #+#             */
/*   Updated: 2020/01/19 15:41:55 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *s = calloc(51, 51);
	int i;
	int As;

	i = 0;
	As = 0;
	scanf("%s", s);
	while (s[i] != 0)
	{
		if (s[i] == 'a')
			As++;
		i++;
	}
	while (i / 2 >= As)
		i--;
	printf("%d\n", i);
	return (0);
}
