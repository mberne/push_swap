NAME		= push_swap
NAME_CHK	= checker

#Sources
PATH_SRCS	= srcs/
SRCS		= $(addprefix $(PATH_SRCS), main.c parsing.c operations.c resolve.c chunk.c radix.c utils.c)

#Includes
PATH_INC	= includes/
HEADER		= $(addprefix $(PATH_INC), push_swap.h)

#Lib
LIBFT		= libft.a

#Other
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
RM			= rm -f

all bonus:	libs $(NAME) $(NAME_CHK)

$(NAME):	$(OBJS) $(LIBFT)
			gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -I $(PATH_INC)

$(NAME_CHK):$(OBJS) $(LIBFT)
			gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME_CHK) -I $(PATH_INC)

libs:
			$(MAKE) -C libft
			ln -sf libft/$(LIBFT) .

%.o:		%.c	$(HEADER)
			gcc $(CFLAGS) -c $< -o ${<:.c=.o} -I $(PATH_INC)

clean:
			${MAKE} clean -C libft
			$(RM) $(OBJS)

fclean:		
			${MAKE} fclean -C libft
			$(RM) $(OBJS) $(NAME) $(NAME_CHK) $(LIBFT)
re:			fclean all

.PHONY:		all clean fclean re libs