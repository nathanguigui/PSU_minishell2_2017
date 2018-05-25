/*
** EPITECH PROJECT, 2017
** args_tool.c
** File description:
** 
*/

int count_args(args_t *RESULT)
{
	int i = 0;

	while (RESULT) {
		i = i + 1;
		RESULT = RESULT->prev;
	}
	return (i);
}

void show_args(args_t *RESULT)
{
	while (RESULT) {
		my_putstr("argv:\n\n");
		my_show_word_array(RESULT->argv);
		my_putstr("\nid:");
		my_putnbr(RESULT->next);
		my_putstr("\n\n\n");
		RESULT = RESULT->prev;
	}
}

char **rem_on_args(args_t **RESULT)
{
	char **rem_var;
	args_t *tmp;
	if (!*RESULT) 
		return (NULL);
	tmp = (*RESULT)->prev;
	rem_var = (*RESULT)->argv;
        free(*RESULT);
        *RESULT = tmp;

        return (rem_var);
}

void tab_on_args(char **tab, args_t **RESULT, int next)
{
        args_t *element = malloc(sizeof(args_t));
        if(!element) 
        	return;
        element->argv = tab;
        element->next = next;
        element->prev = *RESULT;
        *RESULT = element;
}

args_t *rev_args(args_t *RESULT)
{
	args_t *new_pile = NULL;

	while (RESULT) {
		tab_on_args(RESULT->argv, &new_pile, RESULT->next);
		RESULT = RESULT->prev;
	}
	return (new_pile);
}