/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** realloc_array
*/

#include "my.h"

void realloc_tab(void ***tab, void *new)
{
	int i = 0;
	void **res;

	if (*tab != NULL)
		for (i = 0; (*tab)[i] != NULL; i = i + 1);
	res = malloc(sizeof(void *) * (i + 2));
	for (int a = 0; a < i; a = a + 1)
		res[a] = (*tab)[a];
	res[i] = new;
	res[i + 1] = NULL;
	free(*tab);
	*tab = res;
}

