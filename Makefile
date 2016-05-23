##
## Makefile for 	Makefile in /home/rousse_i/rendu/Piscine_C_J12/cat
## 
## Made by mathis rousselot
## Login   <rousse_i@epitech.net>
## 
## Started on  Tue Oct 13 22:25:43 2015 mathis rousselot
## Last update Sun Feb 28 17:59:57 2016 mathis rousselot
##

CC		=	gcc

CFLAGS 		=	-Werror -Wextra -Wall -I ./include/

RM		=	rm -f

NAME		=	sudoku-bi

SRCS    	=	src/main.c \
			src/free_array.c \
			src/parsing/check_validity.c \
			src/parsing/check_tab.c \
			src/parsing/getnextline.c \
			src/parsing/get_table.c \
			src/parsing/print_tab.c \
			src/algo/algo.c \
			src/algo/proba.c

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAG) -lm

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
