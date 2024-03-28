CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libft.a

SRC = ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isascii.c ft_atoi.c \
 	ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
 	ft_bzero.c ft_isprint.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
 	ft_calloc.c ft_itoa.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
 	ft_isalnum.c ft_memmove.c ft_strlcpy.c ft_strtrim.c ft_isalpha.c \
 	ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_lstclear.c ft_lstsize.c ft_lstlast.c \
    ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c \
# ft_lstiter.c
# ft_lstmap.c
# ft_lstdelone.c
OBJ = $(SRC:.c=.o)

NONE='\033[0m'
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
	@echo $(CURSIVE)$(GREEN) "     - Static lib $(NAME) compiled -" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "       - Deleting $(NAME)'s object files..." $(NONE)
	@rm -f $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "       - Deleting $(NAME)..." $(NONE)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
