SRCS =	./srcs/env.c \
		./srcs/links.c \
		./srcs/rooms.c \
		./srcs/main.c \
		./srcs/parser.c \
		./srcs/helper.c \
		./srcs/queue.c \
		./srcs/pathing.c

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = lem_in
LINKER = -L./libft -lft

all:
	$(CC) $(SRCS) -o $(NAME) $(LINKER)

re: clean all

clean:
	rm -f $(NAME)