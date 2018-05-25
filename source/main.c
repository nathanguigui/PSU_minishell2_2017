/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** 
*/

void	start_shell(char **env, char *input)
{
	char **nav = str_to_word_array(input, ' ');
	char cwd[256];
	char *path = my_strcat(get_path(env), ":");
	path = my_strcat(path, getcwd(cwd, sizeof(cwd)));
	char **envp = my_path_to_word_array(path);
	int nb = custom_func(nav, env, envp);

	if (get_index(envp, nav[0]) != -1)
		start_soft(nav, env, envp);
	env = env_func(nav, env, envp);
	if (nav[0] != NULL && get_index(envp, nav[0]) == -1 && nb != 1)
		my_puterr(my_strcat(nav[0], ": Command not found.\n"));
}

int	main(int ac, char **av, char **env)
{
	char *input = NULL;
	char **nav = NULL;

	args_t *ARGS = init_args();

	my_putstr("$>");
	while (input = get_next_line(0)) {
		// start_shell(env, input);
		get_args(input, ARGS, env);
		my_putstr("$>");
	}
	if (input == NULL)
		my_putstr("exit\n");
	return (0);
}