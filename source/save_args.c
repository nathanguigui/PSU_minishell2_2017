/*
** EPITECH PROJECT, 2017
** save_args.c
** File description:
** 
*/

void save_args(args_t *ARGS, char *input, int last, int i)
{
	char *s_argv = cut_fromto(input, last, i);
	my_putstr(s_argv);	
}