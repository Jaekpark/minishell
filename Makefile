#Input header file name
INCS				=	minishell.h
#Input source files name
SRCS				=	main.c error.c ft_utils.c init.c make_struct.c free.c
OBJS				=	$(patsubst %.c, %.o, $(SRCS))

SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/
INCS_DIR		=	./includes/

SRCS_FILE		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS_FILE		=	$(addprefix $(OBJS_DIR), $(OBJS))
INCS_FILE		= 	$(addprefix $(INCS_DIR), $(INCS))

LIBFT			=	./libs/libft.a
LIBFT_DIR		=	./libs
LIBFT_INCS		=	./libs/includes/libft.h

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address
HEADER_FLAG		=	-I$(INCS_DIR) -I$(LIBFT_INCS) -I/Users/jaekpark/.brew/opt/readline/include
LIB_FLAG		=	-lft -L$(LIBFT_DIR) -L/Users/jaekpark/.brew/opt/readline/lib -lreadline -lncurses
NAME			=	minishell

BLACK			=	"\033[1;30m"
RED				=	"\033[1;31m"
GREEN			=	"\033[1;32m"
YELLOW			=	"\033[1;33m"
BLUE			=	"\033[1;34m"
CYAN			=	"\033[1;35m"
PURPLE			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
EOC				=	"\033[0;0m"


all:			$(NAME)

$(LIBFT):
				@make -C ./libs

$(NAME):		$(LIBFT) $(OBJS_DIR) $(OBJS_FILE)
				@echo $(YELLOW) " - Compiling $@"
				@$(CC) $(CFLAGS) $(LIB_FLAG) $(HEADER_FLAG) $(OBJS_FILE) -o $@
				@echo $(GREEN) " - OK" $(EOC)

$(OBJS_DIR) :
					@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(INCS_FILE)
					@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $< -o $@

norm:			$(SRCS_FILE) $(INCS_FILE)
				@echo $(CYAN) " - minishell norm check"$(EOC)
				@norminette $(SRCS_FILE) $(INCS_FILE)
				@make norm -C $(LIBFT_DIR)

# leaks:
# 	@osascript -e 'tell app "Terminal" to do script "while true; do leaks push_swap; sleep 2; clear; done"'
# 	@osascript -e 'tell app "Terminal" to do script "while true; do leaks checker; sleep 2; clear; done"'
# 	@./utils/leaks.sh

clean:
				@make clean -C $(LIBFT_DIR)
				@echo $(YELLOW) " - clean push_swap" $(EOC)
				@$(RM) $(OBJS_FILE) 
				@echo $(GREEN) " - OK" $(EOC)

fclean:
				@make fclean -C $(LIBFT_DIR)
				@echo $(YELLOW) " - fclean minitalk" $(EOC)
				@$(RM) $(NAME) $(OBJS_DIR) 
				@echo $(GREEN) " - OK" $(EOC)

re:				fclean $(NAME) $(CLIENT)

.PHONY:			all clean fclean re norm
