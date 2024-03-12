##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##


SRC	=	./main.c							\
		./server/server.c					\
		./server/error_handling.c			\
		./server/init.c						\
		./server/client_cli.c				\
		./server/my_str_to_word_array.c		\
		./server/commands/user_cmd.c		\
		./server/commands/pass_cmd.c		\
		./server/commands/pwd_cmd.c			\
		./server/commands/cwd_cmd.c			\
		./server/commands/help_cmd.c		\
		./server/commands/quit_cmd.c		\
		./server/commands/noop_cmd.c		\
		./server/commands/cdup_cmd.c		\

OBJ	=	$(SRC:.c=.o)

COMP = -I./include

NAME = myftp

all:	$(OBJ)
	gcc -g -Wall -Wextra -W -o $(NAME) $(OBJ) $(COMP)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

tests_run: clean

re:	fclean / all
