##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make build
##

SRC	=	*.c

NAME	=	my_hunter

ERROR = -W -Wall -Wextra

SFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-network

all:
	gcc -no-pie -o $(NAME) $(SRC) $(SFML) $(ERROR) -lm
clean:
	rm -f $(CRITO) $(CRITA) unit-tests

fclean:
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit-tests ./lib/my/*.c ./tests/*.c $(SRC) -lcriterion --coverage
	./unit-tests
