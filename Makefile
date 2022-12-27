##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC = 	my_ls.c
FILES = my_ls.c handle_args.c handle_options.c printer.c utils.c l_opt.c \
		l_opt_2.c
OBJ = 	$(SRC:.c=.o)

all: compile

compile:
		 cd ./lib/my/ && make && cd ../../
		 gcc -o my_ls $(FILES) error_handling.c -I./include -L./lib -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
