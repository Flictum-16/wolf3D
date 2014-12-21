##
## Makefile for  in /home/bertra_v/tek_1/Igraph/MUL_2014_fdf
##
## Made by Florent Bertrand
## Login   <bertra_v@epitech.net>
##
## Started on  Sun Nov  2 17:11:06 2014 Florent Bertrand
## Last update Sun Dec 21 17:06:18 2014 Florent Bertrand
##

NAME= wolf3D

SRC= 	my_put_pixel_in_image.c\
	utils.c\
	wolf3D.c


OBJ= $(SRC:.c=.o)

LDFLAGS= -L ./lib/my -lmy  -L. -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm -lxkbfile
CFLAGS= -I ./include/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: fclean all
