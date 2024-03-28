CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -g
NAME = ft_printf.a

SRC = ft_look_char.c ft_look_str.c ft_print_int.c ft_print_ui.c ft_utils_conversion.c ft_utils_conversion_2.c ft_utils_create.c ft_utils_put.c ft_utils_count.c ft_utils_search.c ft_sort_int.c ft_sort_ui.c \
	   ft_look_int.c ft_look_ui.c ft_print_ptr.c ft_print_ui_hexa.c ft_sort_ptr.c ft_look_ptr_ulli.c ft_sort_ui_hexa.c ft_utils_conversion_3.c\
	   ft_look_ptr.c ft_print_char.c ft_print_str.c ft_printf.c ft_sort_char.c ft_sort_str.c ft_width.c \

OBJ = $(SRC:.c=.o)

NONE='\033[0m'
BLUE='\033[34m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
all: $(NAME)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)'s source files into .o..." $(NONE)
	@$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@ar -rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(CURSIVE)$(GREEN) "     - Static lib $(NAME) compiled -" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "	- Deleting $(NAME)'s object files..."$(NONE)
	@rm -f $(OBJ)


fclean: clean
	@echo $(CURSIVE)$(GRAY) "	- Deleting $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
