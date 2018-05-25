/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** 
*/

void	my_show_word_array(char **tab)
{
	int i = 0;
	int j = 0;

	if (tab == NULL || (!tab))
		return;
	while (tab[i]) {
		j = 0;
		while (tab[i][j]) {
			my_putchar(tab[i][j]);
			j = j + 1;
		}
		my_putchar('\n');
		i = i + 1;
	}
}