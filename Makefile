NAME		= push_swap
NAME_CHK	= checker

#Sources
PATH_SRCS	= srcs/
SRCS		=							\
				main.c					\
				parsing.c				\
				operations.c			\
				resolve.c				\
				few_integers.c			\
				chunk.c					\
				radix.c					\
				utils.c					\

SRCS_CHK	=							\
				checker.c				\
				parsing.c				\
				operations_checker.c	\
				utils.c					\

#Includes
PATH_INC	= includes/
HEADER		= $(addprefix $(PATH_INC), push_swap.h)

#Lib
LIBFT		= libft.a

#Objects
PATH_OBJS	= objs/
OBJS		= $(addprefix $(PATH_OBJS), $(SRCS:.c=.o))
OBJS_CHK	= $(addprefix $(PATH_OBJS), $(SRCS_CHK:.c=.o))

#Other
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3

all:	libs $(NAME)

bonus:	all $(NAME_CHK)

$(PATH_OBJS)%.o:		$(PATH_SRCS)%.c	$(HEADER)
			@mkdir -p $(dir $@)
			gcc $(CFLAGS) -c $< -o $@ -I $(PATH_INC)

$(NAME):	$(OBJS) $(LIBFT)
			gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -I $(PATH_INC)

$(NAME_CHK):$(OBJS_CHK) $(LIBFT)
			gcc $(CFLAGS) $(OBJS_CHK) $(LIBFT) -o $(NAME_CHK) -I $(PATH_INC)

libs:
			$(MAKE) -C libft
			ln -sf libft/$(LIBFT) .

clean:
			$(MAKE) clean -C libft
			rm -f $(OBJS) $(OBJS_CHK)

fclean:
			$(MAKE) fclean -C libft
			rm -f $(OBJS) $(OBJS_CHK) $(NAME) $(NAME_CHK) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re libs