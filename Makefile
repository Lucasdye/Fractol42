NAME = fractol
SRC = handling_mouse.c fractol.c parsing.c color.c algos.c init.c palette.c handling_key.c
STATICLIBFT = libft/libft.a
STATICPRINTF = ft_printf/ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
RM = rm -rf
OBJ = $(SRC:.c=.o)
MAKEFCLEANLIBFT = $(MAKE) fclean -C libft
MAKEFCLEANPRINTF = $(MAKE) fclean -C ft_printf
MAKECLEANLIBFT = $(MAKE) clean -C libft
MAKECLEANPRINTF = $(MAKE) clean -C ft_printf

MLX = ./minilibx-linux/libmlx.a
MFLAG = -lX11 -lXext -lm

NONE='\033[0m'
WHITE = '\033[37m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
all: $(NAME)

ft_printf:
	@$(MAKE) -C ft_printf

libft:
	@$(MAKE) -C libft


$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     Compiling libft.a" $(NONE)
	@$(MAKE) -C libft
	@echo $(CURSIVE)$(GRAY) "     Compiling ft_printf.a" $(NONE)
	@$(MAKE) -C ft_printf
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $^


$(MLX):
	@git clone https://github.com/42Paris/minilibx-linux
	@make -C ./minilibx-linux

	
$(NAME): $(MLX) $(OBJ) 
	@echo $(CURSIVE)$(GRAY) "     Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(OBJ) $(STATICPRINTF) $(STATICLIBFT) -I. $(MLX) -I. -L/usr/local/lib  -L/usr/lib  -Imlx_linux -lXext -lX11 -lm -o $(NAME)
	@echo $(CURSIVE)$(GREEN) "     - fractol compiled -" $(NONE)









fcleanlibft:
	@echo $(CURSIVE)$(GRAY) "	- Cleaning .o and .a libft" $(NONE)
	@$(MAKEFCLEANLIBFT) 

fcleanprintf: fcleanlibft
	@echo $(CURSIVE)$(GRAY) "	- Cleaning .o and .a printf" $(NONE)
	@$(MAKEFCLEANPRINTF) 

cleanlibft:
	@echo $(CURSIVE)$(GRAY) "	- Cleaning .o and .a printf" $(NONE)
	@$(MAKECLEANPRINTF)

cleanprintf: cleanlibft
	$(MAKECLEANPRINTF)

clean:
	@echo $(CURSIVE)$(GRAY) "	Cleaning all object files..." $(NONE)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf
	@echo $(CURSIVE)$(GRAY) "	- Deleting $(NAME)'s object files..." $(NONE)
	@$(RM) $(OBJ)
	@echo $(CURSIVE)$(WHITE) "	- Cleaned -" $(NONE)


fclean: clean
	@echo $(CURSIVE)$(GRAY) "	Cleaning object files, libraries & $(NAME)..." $(NONE)
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf
	@$(RM) $(NAME)
	@$(RM) $(OBJ) 
	@$(RM) ./minilibx-linux
	@echo $(CURSIVE)$(WHITE) "	- Full cleaned -" $(NONE)

re: fclean all

.PHONY: all clean fclean re libft.a libft ft_printf ft_printf.a
