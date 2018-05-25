/*
** EPITECH PROJECT, 2017
** my_find_env.c
** File description:
** 
*/

int is_matching(char *str, char *line)
{
	unsigned int i = 0;

	if (strlen(str) > strlen(line))
		return (0);
	else {
		while (i < strlen(str)) {
			if (str[i] != line[i])
				return (0);
			i = i + 1;
		}
		if (line[i] != '=')
			return (0);
	}
	return (1);
}

int find_env(char *str, char **ev)
{
	int i = 0;

	while (ev[i]) {
		if (is_matching(str, ev[i]))
			return (i);
		i = i + 1;
	}
	return (-1);
}