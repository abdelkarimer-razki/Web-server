NAME = webserv

CFLAGS =  -std=c++98

CC = c++

GREEN=\033[0;32m

NC=\033[0m

FILES = main.cpp webserv.cpp routes.cpp

HEADERS = headers/*.hpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)
	@echo "$(GREEN)✔$(NC) Compiled."

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

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

