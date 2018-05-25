/*
** EPITECH PROJECT, 2017
** my_env.c
** File description:
** 
*/

int	nb_env(char **env)
{
	int i = 0;

	while (env[i])
		i = i + 1;
	return (i);
}

char	**set_env(char **env, char *str)
{
	char **new_env = malloc(sizeof(char *) * nb_env(env) + 2);
	int i = 0;

	while (env[i]) {
		new_env[i] = malloc(sizeof(char) * my_strlen(env[i]));
		new_env[i] = env[i];
		i = i + 1;
	}
	new_env[i] = str;
	new_env[i + 1] = '\0';
	return (new_env);
}

char	**env_func(char **nav, char **env, char **envp)
{
	if (my_strcmp(nav[0], "setenv"))
		env = set_env(env, nav[1]);
	if (my_strcmp(nav[0], "unsetenv"))
		env = unset_env(env, nav[1]);
	return (env);
}