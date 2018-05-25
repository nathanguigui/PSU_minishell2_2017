/*
** EPITECH PROJECT, 2017
** args.h
** File description:
** 
*/

#ifndef ARGS_H
#define ARGS_H

typedef struct args_s
{
	char **argv;
	int next;
	struct args_s *prev;
} args_t;

//args_tool.c
int count_args(args_t *ARGS);
void show_args_t(args_t*);
char **rem_on_args(args_t**);
void tab_on_args(char**, args_t**, int);
args_t *rev_args(args_t *ARGS);
//args_tool.c
//get_args.c
args_t *init_args(void);
char *cut_rest_from(char *input, int from);
char *cut_fromto(char *input, int from, int to);
void get_args(char *input, args_t *ARGS, char **env);
//get_args.c
//save_args.c
void save_args(args_t *ARGS, char *input, int last, int i);
//save_args.c

#endif