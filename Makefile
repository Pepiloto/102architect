##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for 102 architect
##

############ SOURCES ###########
SRC	=	src/main.c		\
		src/function.c		\
		src/architect.c
################################

############ FLAGS #############
CPPFLAGS	+= -lm -I include
CFLAGS	+=	-Wall -Wextra
################################

############ BINARY ############
NAME	=	102architect
################################

.PHONY: all
all:	$(NAME)
$(NAME):
	clang -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS)

.PHONY: debug
debug: CPPFLAGS += -g3
debug: $(NAME)

.PHONY:
clean:
	rm -f *~
.PHONY:
fclean: clean
	rm -f $(NAME)

.PHONY:
re:	fclean all
