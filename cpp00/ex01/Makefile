NAME = phonebook
CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I./include/

SRCS_DIR = src/
SRCS = PhoneBook.cpp	\
		Contact.cpp		\
		main.cpp
OBJS_DIR = objs/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re