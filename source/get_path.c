/*
** EPITECH PROJECT, 2017
** get_path.c
** File description:
** 
*/

int	get_index(char **path, char *soft)
{
	int x = 0;
	char *tmp;

	if (soft == NULL)
		return (-1);
	if (path == NULL)
		return;
	while (path[x]) {
		tmp = my_strcat(path[x], soft);
		if (open(tmp, O_RDONLY) != -1 )
			return (x);
		x = x + 1;
	}
	return (-1);
}

char *compute_path(char **env, int x)
{
	char *result = NULL;
	int it = 0;
	int buf = 0;
	int len = 0;

	while (env[x][it] != '=' && env[x][it] != '\0')
		it = it + 1;
	it = it + 1;
	len = my_strlen(env[x]) - it;
	result = malloc(sizeof(char)* len + 1);
	while (env[x][it] != '\0') {
		result[buf] = env[x][it];
		buf = buf + 1;
		it = it + 1;
	}
	result[buf] = '\0';
	return (result);
}

char	*get_path(char **env)
{
	char *str = NULL;
	int buf = 0;
	int it = 0;
	int x = 0;
	int len = 0;
	while (env[x]) {
		if (env[x][0]=='P' && env[x][1]== 'A' && env[x][2] == 'T' &&
		env[x][3] == 'H') {
			str = compute_path(env, x);
			return (str);
		}
		x = x + 1;
	}
	return (str);
}