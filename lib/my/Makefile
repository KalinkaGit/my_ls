##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = ./my_compute_power_rec.c \
	  ./my_put_nbr.c \
	  ./my_putchar.c \
	  ./my_putstr.c \
	  ./my_realloc.c \
	  ./my_revstr.c \
	  ./my_strcat.c \
	  ./my_strcmp.c \
	  ./my_strcpy.c \
	  ./my_strlen.c \
	  ./printf/my_printf.c \
	  ./printf/check.c \
	  ./printf/lib/my/my_get_nbr_len.c \
	  ./printf/lib/my/my_put_a.c \
	  ./printf/lib/my/my_put_binary.c \
	  ./printf/lib/my/my_put_float.c \
	  ./printf/lib/my/my_put_g.c \
	  ./printf/lib/my/my_put_hexa.c \
	  ./printf/lib/my/my_put_length.c \
	  ./printf/lib/my/my_put_octal.c \
	  ./printf/lib/my/my_put_percent.c \
	  ./printf/lib/my/my_put_pointer.c \
	  ./printf/lib/my/my_put_scient.c \
	  ./printf/lib/my/my_put_unbr.c \
	  ./printf/lib/my/my_put_uoctal.c \
	  ./printf/lib/my/my_putstr_special.c

OBJ = $(SRC:.c=.o)
LIB = compile

all: $(LIB)

$(LIB): $(OBJ)
		ar rc libmy.a $(OBJ)
	  	cp ./printf/lib/my/my.h ../../include
		cp libmy.a ../
		cp my.h ../../include/
		make clean

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(LIB)

re: 	fclean all
