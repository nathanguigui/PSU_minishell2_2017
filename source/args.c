/*
** EPITECH PROJECT, 2017
** arg.c
** File description:
** 
*/

int is_command(char chars, int status)
{
	int ret_value = 0;

	if (status == 1) {
		(chars == '>') ? ret_value = 1 : 0;
		(chars == '<') ? ret_value = 1 : 0;
		(chars == ';') ? ret_value = 1 : 0;
		(chars == '|') ? ret_value = 1 : 0;
	} else if (status == 2) {
		(chars == '>') ? ret_value = 1 : 0;
		(chars == '<') ? ret_value = 1 : 0;		
	}
	return (ret_value);	
}

int check_command(char *input, int *it)
{
	int ret_value = 0;
	ret_value = is_command(input[*it], 1);

	if (ret_value && is_command(input[*it + 1], 2))
		*it = *it + 1;
	return (ret_value);
}