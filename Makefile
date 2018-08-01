NAME	= fdf

SRCS	=	main.c\
		 	ft_draw_tab.c\
		 	ft_free.c\
		 	ft_init_color.c\
		 	ft_init_pack.c\
		 	ft_print_image.c\
		 	ft_rot.c\
		 	ft_set_end.c\
		 	ft_tools.c\
		 	ft_turn.c\
		 	get_next_line.c\
		 	ft_strjoin.c\
		 	ft_strsub.c\
		 	ft_atoi.c\
		 	ft_memchr.c\
		 	ft_memdel.c\
		 	ft_memmove.c\
		 	ft_strcat.c\
		 	ft_strcpy.c\
		 	ft_strlen.c\
		 	ft_isdigit.c\
			ft_allocate.c\
			ft_test_line.c\
			ft_putstr.c\
			ft_putchar.c\
			ft_exit.c\
			ft_check_tab.c

OBJS	=	$(SRCS:.c=.o)
FLAGS	=	-Wall -Wextra -Werror

all		: $(NAME)

$(NAME) : $(OBJS)
		gcc -o $(NAME) $(OBJS) -I libft -lmlx -framework OpenGL -framework AppKit

%.o		: %.c
		gcc -c $(FLAGS) $(SRCS) -I libft

clean	:
		rm -f $(OBJS)

fclean	: clean
		rm -f $(NAME)

re		: fclean all

.PHONY: all clean fclean re
