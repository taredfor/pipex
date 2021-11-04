NAME			=	pipex

SRCS_FILES		=	${shell find ./srcs -name "*.c"}
BONUS_FILES		=	${shell find ./srcs_bonus -name "*.c"}

SRCS			=	$(SRCS_FILES)
OBJS 			=	$(SRCS:.c=.o)

SRCS_BONUS		=	$(BONUS_FILES)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)



LIB_DIR			=	./libft
INCLUDES		=	includes
INC_LIBFT 		=   libft

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

%.o: %.c
			$(CC) $(CFLAGS) -c -I$(INCLUDES) -I$(INC_LIBFT)  $< -o $@

all:		$(NAME)

${NAME}:	$(OBJS) includes/pipex.h
			@echo "\033[33m----Compiling libft----"
			make -C $(LIB_DIR)
			$(CC) $(CFLAGS) -I$(INCLUDES) $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)
			@#clear
			@echo "pipe is ready!!!"

bonus:		$(OBJS_BONUS) includes/pipex_bonus.h
			@echo "\033[33m----Compiling libft----"
			make -C $(LIB_DIR)
			$(CC) $(CFLAGS) -I$(INCLUDES) $(LIB_DIR)/libft.a $(OBJS_BONUS) -o $(NAME)
			@#clear
			@echo "many pipes are ready!!!"

clean:
			make clean -C ${LIB_DIR}
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

fclean:		clean
			make fclean -C ${LIB_DIR}
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus


