##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

PREFIX	=	source/

FILES	=	main.c \
		core.c \
		get_path.c \
		my_env.c \
		my_unset_env.c \
		my_path_to_word_array.c \
		find_env.c \
		args.c \
		get_args.c \
		args_tool.c \
		my_show_word_array.c \
		save_args.c

SRC	=	$(addprefix $(PREFIX), $(FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	+=	-W -Wall -Wextra -I include -g -include mysh.h

LDFLAGS	+=	-L library/ -l my -lc_graph_prog

all:	my	$(NAME)

YELLOW          =       \033[0;103m
RED             =       \033[0;31m
GREEN           =       \033[0;32m
NC              =       \033[0m
GREY            =       \033[90m
BLUE            =       \033[0;94m
PURPLE          =       \033[0;95m
BG_COLOR        =       \033[46m####\033[m
IRED            =       \033[0;91m

$(NAME):	$(OBJ)
	@echo -e '${NC}${BG_COLOR}Libs: $(LDFLAGS)${NC}'
	@echo -e '${BG_COLOR}Flags: $(CFLAGS)${NC}'
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 2>>errors_build.txt\
		&& echo -e '${BLUE}Create${NC}: ${YELLOW}${GREY}./$(NAME)${NC}'\
		|| echo -e '${RED}[ FAILED ]${NC}: __Create__${GREY} ./$(NAME)${NC}'

my:
	@make --no-print-directory -C library/my

%.o:            %.c
	@-$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS) 2>>errors_build.txt\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'\
		&& echo -ne '${PURPLE}' && grep  $< errors_build.txt |\
		grep warning |cut -d':' -f2- |cut -d'[' -f-1\
		&& echo -ne '${IRED}' && grep  $< errors_build.txt |\
		grep error |cut -d':' -f2-\
		||:
	@echo -ne '${NC}'

tests_run:	fclean	$(OBJ_T)	my
	$(CC) $(SRCT) $(OBJ_T) -l criterion --coverage -g -o crit -l gcov $(LDFLAGS) $(CFLAGS)
	./crit

clean:
	@make -C library/my clean
	@find . -name "*~" -delete -o -name "#*#" -delete
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@echo -e '${BLUE}Clean${NC} : OK'


fclean:         clean
	@rm -rf crit
	@rm -rf errors_build.txt 2>/dev/null
	@rm -rf $(NAME)
	@make -C library/my fclean
	@echo -e '${BLUE}Fclean${NC}: ./$(NAME) removed'

re:	fclean	all

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

#A phony target should not be a prerequisite of a real target file;
#if it is, its recipe will be run every time make goes to update that file.
.PHONY:	all	$(NAME)	my	clean	fclean	re
