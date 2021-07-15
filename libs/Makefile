NAME			=	libft.a
NAME_DEBUG		=	libft_debug.a
INCS			=	libft.h
SRCS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memccpy.c \
					ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
					ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_gnl.c ft_utoa.c ft_uitoa.c \
					ft_isnum.c ft_strcmp.c ft_strnrcmp.c ft_atol.c ft_memfree.c ft_numlen.c ft_is_all_num.c

OBJS			=	$(patsubst %.c, %.o, $(SRCS))

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	includes/
DEBUG_OBJS_DIR	=	objs_debug/

DEBUG_OBJS_FILE	=	$(addprefix $(DEBUG_OBJS_DIR), $(OBJS))
SRCS_FILE		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS_FILE		=	$(addprefix $(OBJS_DIR), $(OBJS))
INCS_FILE		= 	$(addprefix $(INCS_DIR), $(INCS))

CC				=	gcc
AR				=	ar rcs
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
DEBUG_FLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
HEADER_FLAG		=	-I$(INCS_DIR)

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

debug:			$(NAME_DEBUG)

$(NAME):		$(OBJS_DIR) $(OBJS_FILE)
				@echo $(CYAN) "`date +%y/%m/%d_%H:%M:%S`:: Compiling $@ "$(EOC)
				@$(AR) libft.a $(OBJS_FILE)
				@echo $(GREEN) "`date +%y/%m/%d_%H:%M:%S`:: OK"$(EOC)

$(OBJS_DIR) :
					@mkdir -p $(OBJS_DIR)	

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c 
					@$(CC) -c $(CFLAGS) $(HEADER_FLAG) $< -o $@

$(NAME_DEBUG):	$(DEBUG_OBJS_DIR) $(DEBUG_OBJS_FILE)
				@echo $(CYAN) "`date +%y/%m/%d_%H:%M:%S`:: Compiling $@" $(EOC)
				@$(AR) $(NAME_DEBUG) $(DEBUG_OBJS_FILE)
				@echo $(GREEN) "`date +%y/%m/%d_%H:%M:%S`:: OK"$(EOC)

$(DEBUG_OBJS_DIR) :
				@mkdir -p $(DEBUG_OBJS_DIR)

$(DEBUG_OBJS_DIR)%.o :	$(SRCS_DIR)%.c
				@$(CC) -c $(DEBUG_FLAGS) $(HEADER_FLAG) $< -o $@

norm:			
				@echo $(CYAN) "`date +%y/%m/%d_%H:%M:%S`:: Libft norm check" $(EOC)
				@norminette $(SRCS_FILE) $(INCS_FILE)

clean:
				@echo $(CYAN) "`date +%y/%m/%d_%H:%M:%S`:: clean libft" $(EOC)
				@$(RM) $(OBJS_FILE) $(DEBUG_OBJS_FILE)
				@echo $(GREEN) "`date +%y/%m/%d_%H:%M:%S`:: OK" $(EOC)

fclean:			
				@echo $(CYAN) "`date +%y/%m/%d_%H:%M:%S`:: fclean libft" $(EOC)
				@$(RM) $(NAME_DEBUG) $(NAME) $(OBJS_DIR) $(DEBUG_OBJS_DIR)
				@echo $(GREEN) "`date +%y/%m/%d_%H:%M:%S`:: OK"$(EOC)

re:				fclean $(NAME)

redebug:		fclean $(NAME_DEBUG)

.PHONY:			all clean fclean re norm redebug debug
