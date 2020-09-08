
SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

NASM_FLAGS	=	-f elf64
GCC_FLAGS 	=	-Wall -Werror -Wextra -no-pie
NAME		=	libasm.a
TEST		=	test

%.o:			%.s
				nasm $(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(TEST)

test:			$(NAME)
				gcc $(GCC_FLAGS) -o $(TEST) main.c $(NAME)
				./$(TEST)	

re:				fclean $(NAME)

.PHONY:			clean fclean re test
