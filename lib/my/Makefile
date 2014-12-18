##
## Makefile for  in /home/bertra_v/rendu/Piscine_C_J11
##
## Made by Bertrand Florent
## Login   <bertra_v@epitech.net>
##
## Started on  Mon Oct 20 09:25:22 2014 Bertrand Florent
## Last update Tue Oct 21 10:14:54 2014 Bertrand Florent
##

NAME	= libmy

SRC	=	my_putchar.c \
		my_isneg.c \
		my_put_nbr.c \
		my_swap.c \
		my_putstr.c \
		my_strlen.c \
		my_getnbr.c \
		my_sort_in_tab.c \
		my_power_rec.c \
		my_square_root.c \
		my_is_prime.c \
		my_find_prime_sup.c \
		my_strcpy.c \
		my_strncpy.c \
		my_revstr.c \
		my_strstr.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strupcase.c \
		my_strlowcase.c \
		my_strcapitalize.c \
		my_str_isalpha.c \
		my_str_isnum.c \
		my_str_islower.c \
		my_str_isupper.c \
		my_str_isprintable.c \
		my_showstr.c \
		my_showmem.c \
		my_strcat.c \
		my_strncat.c \
		my_is_alnum.c \
		my_strlcat.c \
		my_str_to_wordtab.c \
		my_show_wordtab.c \
		my_strdup.c

OPT	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OPT)
	@ar rc $(NAME).a $(OPT)
	@ranlib $(NAME).a
	@cp $(NAME).a ../
	@mkdir -p ../../include
	@cp my.h ../../include

clean:
	$(RM) $(OPT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
