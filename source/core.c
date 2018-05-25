/*
** EPITECH PROJECT, 2017
** core.c
** File description:
** 
*/

int	ch_dir(char **nav, char **env)
{
	char **tmp = NULL;
	char cwd[256];

	if (my_strcmp("-", nav[1])) {
		if (find_env("OLDPWD", env) == -1) {
			my_puterr("OLDPWD is not defined.\n");
			return (1);
		}
		tmp = str_to_word_array(env[find_env("OLDPWD", env)], '=');
		nav[1] = tmp[1];
		my_putstr(tmp[1]);
		my_putchar('\n');
	}
	if (chdir(nav[1]) == -1) {
		perror(nav[1]);
	}
	env[find_env("OLDPWD", env)] = getcwd(cwd, sizeof(cwd));
	return (1);
}

int	custom_func(char **nav, char **env, char **envp)
{
	int k = 0;
	(my_strcmp(nav[0], "exit")) ? exit(0) : 1;
	(my_strcmp(nav[0], "cd")) ? k = ch_dir(nav, env) : 1;
	return (k);
}

void	start_soft(char **nav, char **env, char **envp)
{
	char *npath = envp[get_index(envp, nav[0])];
	int pid = fork();
	int status;

	if (pid == 0) {
		if (execve(my_strcat(npath, nav[0]), nav, env) == -1)
			exit(0);
		// perror("execve");
	} else if (pid > 0)
		wait(&status);
	if (status != 0 && status < 32)
		my_puterr(my_strcat(strsignal(status), "\n"));
}