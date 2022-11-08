NAME = webserv

CFLAGS =  -std=c++98

CC = c++

GREEN=\033[0;32m

NC=\033[0m

FILES = cppfiles/main.cpp  cppfiles/webserv.cpp  cppfiles/routes.cpp

HEADERS = headers/*.hpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)
	@echo "$(GREEN)✔$(NC) Compiled."
	@mv cppfiles/*.o fobjs

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	@rm -f $(NAME)

fclean : clean
	@rm -f fobjs/*.o
	@echo "$(GREEN)✔$(NC) Cleaned."

run :
	@make re && ./$(NAME) $(Arg)

re : fclean all

