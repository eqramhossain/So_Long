SOURCE = ft_memset.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putnbr_fd.c

SOURCE_GET_NEXT_LINE = ${shell find ./get_next_line -name "*.c"}

SOURCE_FT_PRINTF = ${shell find ./ft_printf -name "*.c"}

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME = libft.a
OBJECT = ${SOURCE:.c=.o}
OBJECT_GET_NEXT_LINE = ${SOURCE_GET_NEXT_LINE:.c=.o}
OBJECT_FT_PRINTF = ${SOURCE_FT_PRINTF:.c=.o}
OBJECT_BONUS = ${BONUS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) $(OBJECT_FT_PRINTF) $(OBJECT_GET_NEXT_LINE)
	@ar rcs $(NAME) $(OBJECT) $(OBJECT_FT_PRINTF) $(OBJECT_GET_NEXT_LINE)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@rm -f $(OBJECT) $(OBJECT_BONUS) $(OBJECT_FT_PRINTF) $(OBJECT_GET_NEXT_LINE)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus : $(OBJECT) $(OBJECT_BONUS)
	@ar rcs  $(NAME) $(OBJECT_BONUS) $(OBJECT)

.PHONY: clean fclean re all
