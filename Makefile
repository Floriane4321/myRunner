##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## a Makefile that compiles my libmy, task1, day10
##

SRC	=	main.c	\
		create_window.c	\
		event.c	\
		menu.c	\
		sprite_sheet.c	\
		fct_time.c	\
		background.c	\
		fct_object.c	\
		fct_main.c	\
		obstacles.c	\
		move_cat.c	\
		jump_cat.c	\
		hitbox.c	\
		image_end.c	\
		load_file_in_mem.c	\
		read_map.c	\
		my_strlen.c	\
		my_putstr.c	\
		modif_str.c	\
		handling_map.c	\
		text.c	\
		my_getstr.c	\
		my_revstr.c	\
		initialize.c	\
		music.c	\
		pokemon_1.c	\
		pokemon_2.c	\
		pokemon_3.c	\
		animation_end.c	\
		score.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAG	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAG) -g -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

%.o:	%.c
	gcc -c $< -I include/ -g
