/*
** EPITECH PROJECT, 2018
** str_to_word_array
** File description:
** str_to_word_array
*/

#include "my.h"

int count_words(char *str, char delim)
{
	int i = 0;
	int count = 0;
	int is_char = 0;
	char d2 = (delim == ' ' ? '\t' : delim);

	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i + 1] != '\0') {
		if (str[i] != delim && str[i] != d2)
			is_char = 1;
		else if ((str[i] == delim || str[i] == d2) && str[i + 1] != d2
			&& str[i + 1] != delim && str[i + 1] != '\0' && is_char)
			count = count + 1;
		i = i + 1;
	}
	return (count + 1);
}

char *get_word(char *str, int nb, char del, char d2)
{
	int i = 0;
	int le = 0;
	int count = 0;
	char *res = NULL;

	for (int is_char = 0; str[i + 1] && (count < nb || !is_char); i++) {
		if (str[i] != del && str[i] != d2)
			is_char = 1;
		else if ((str[i] == del || str[i] == d2) && str[i + 1] != d2
			&& str[i + 1] != del && str[i + 1] != '\0' && is_char)
			count = count + 1;
	}
	(nb == 0 && i != 0 ? i-- : i);
	for (; str[i + le] != del && str[i + le] != d2 && str[i + le]; le++);
	res = malloc(sizeof(char) * (le + 1));
	res[le] = '\0';
	for (int a = 0; str[i + a] && str[i + a] != del &&
		str[i + a] != d2; a = a + 1)
		res[a] = str[i + a];
	return (res);
}

char **str_to_word_array(char *str, char delim)
{
	int nb = count_words(str, delim);
	char **res = NULL;
	int i = 0;
	char delim2 = (delim == ' ' ? delim : delim);

	if (str == NULL)
		return (NULL);
	res = malloc(sizeof(char *) * (nb + 1));
	while (i < nb) {
		res[i] = get_word(str, i, delim, delim2);
		i = i + 1;
	}
	res[i] = NULL;
	return (res);
}
