NAME = webserv

CFLAGS = -Wall -Werror -Wextra -std=c++98

CC = c++

GREEN=\033[0;32m

NC=\033[0m

FILES = main.cpp 

HEADERS = main.hpp

OBJS = $(FILES:.cpp=.o)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $<

all : $(NAME)
	@echo "$(GREEN)✔$(NC) Compiled."

$(NAME) : $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	@rm -f $(NAME)

fclean : clean
	@rm -f $(OBJS)
	@echo "$(GREEN)✔$(NC) Cleaned."

run :
	@make re && ./$(NAME) $(Arg)

re : fclean all
