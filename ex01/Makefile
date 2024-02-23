CC = c++
NAME =	serial
SRCS =	main.cpp			\
		Serializer.cpp
OBJS =	$(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
%.o : %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re