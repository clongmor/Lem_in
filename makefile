SRCS =	./srcs/env.c \
		./srcs/links.c \
		./srcs/rooms.c \
		./srcs/main.c \
		./srcs/parser.c \
		./srcs/helper.c \
		./srcs/queue.c \
		./srcs/pathing.c \
		./srcs/flow.c

EXECUTABLE = lemon
LIBRARY = lib_ft
CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = lem-in
LINKER = -L./libft -lft

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIBRARY)
	$(CC) $(SRCS) -o $(NAME) $(LINKER) $(FLAGS)

$(LIBRARY):
	make re -C libft
	make clean -C libft
	
re: clean all

clean:
	rm -f $(NAME)