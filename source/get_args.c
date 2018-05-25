/*
** EPITECH PROJECT, 2017
** get_pile.c
** File description:
** 
*/

args_t *init_args(void)
{
	args_t *RESULT = malloc(sizeof(args_t));
	RESULT->argv = NULL;
	RESULT-> next = -1;
	RESULT->prev = NULL;
	return (RESULT);
}

int argstat(char *input, int where)
{
	return (666);
}

char *cut_rest_from(char *input, int from)
{
	int len = 0;
	int i = from;
	char *result = NULL;

	for (int i = from; input[i]; i++)
		len = len + 1;
	result = malloc(sizeof(char) * len + 1);
	len = 0;
	for (i = from; input[i]; i++) {
		result[len] = input[i];
		len ++;
	}
	result[len] = '\0';
	return (result);
}

char *cut_fromto(char *input, int from, int to)
{
	int len = to - from;
	char *result = malloc(sizeof(char) * len + 1);
	int i = 0;

	while (from + i < to) {
		result[i] = input[from + i];
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}

void get_args(char *input, args_t *ARGS, char **env)
{
	int i = 0;
	int count = 0;
	int last = 0;

	if (!input || input == NULL)
		return;
	while (input[i]) {
		if (is_command(input[i], 1)) {
			save_args(ARGS, input, last, i);
			check_command(input, &i);
			last = i;
			// input = cut_rest_from(input, i);
			// my_putstr(input);
			// get_args(input, ARGS);
			count = count + 1;
		}
		i = i + 1;
	}
	(count == 0) ? start_shell(env, input) : 1;
}
