##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

SRC		=	sources/

SRC_C	=	extrafunctions.c 		\
			sprites1.c 				\
			sprites2.c 				\
			sprites3.c 				\
			character_funcs.c		\
			my_runner.c 			\
			print1.c		 		\
			print2.c		 		\
			clock_and_pos.c 		\
			window.c				\
			my_revstr.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./include

NAME = my_runner

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
