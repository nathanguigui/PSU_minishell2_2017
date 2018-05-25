/*
** EPITECH PROJECT, 2017
** my_unset_env.c
** File description:
** 
*/

char	**rem_env(char **env, char *str, int i)
{
	char **new_env = malloc(sizeof(char *) * nb_env(env));

	while (env[i+1]) {
		env[i] = NULL;
		new_env[i] = env[i + 1];
		i = i + 1;
	}
	return (new_env);
}

char	**unset_env(char **env, char *str)
{
	char **new_env = malloc(sizeof(char *) * nb_env(env));
	int i = 0;

	while (env[i]) {
		if (my_strcmp(env[i], str))
			env = rem_env(env, str, i);
		i = i + 1;
	}
}