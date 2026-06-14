NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./

RM = rm -rf

SRCS_CHAR = ft_isalnum.c  ft_isascii.c  ft_isprint.c  ft_toupper.c \
ft_isalpha.c  ft_isdigit.c  ft_tolower.c

SRCS_FD = ft_putchar_fd.c  ft_putnbr_fd.c  get_next_line.c ft_putendl_fd.c \
ft_putstr_fd.c ft_long_to_hex.c ft_printf.c ft_putnbr_base.c

SRCS_MEM = ft_bzero.c   ft_memchr.c  ft_memcpy.c   ft_memset.c \
ft_calloc.c  ft_memcmp.c  ft_memmove.c

SRCS_NB = ft_atoi.c  ft_itoa.c ft_swap.c

SRCS_STR = ft_split.c   ft_striteri.c  ft_strlcpy.c  ft_strncmp.c  ft_strtrim.c \
ft_strchr.c  ft_strjoin.c   ft_strlen.c   ft_strnstr.c  ft_substr.c \
ft_strdup.c  ft_strlcat.c   ft_strmapi.c  ft_strrchr.c

SRCS_LST = ft_lstadd_back.c   ft_lstclear.c   ft_lstiter.c  ft_lstmap.c  ft_lstsize.c \
ft_lstadd_front.c  ft_lstdelone.c  ft_lstlast.c  ft_lstnew.c

SRCS_ALG = vec_algebra.c matrix_algebra.c transformations.c

SRCS_NAME = $(addprefix libchar/, $(SRCS_CHAR)) \
			$(addprefix libfd/, $(SRCS_FD)) \
			$(addprefix libmem/, $(SRCS_MEM)) \
			$(addprefix libnb/, $(SRCS_NB)) \
			$(addprefix libstr/, $(SRCS_STR)) \
			$(addprefix t_lst/, $(SRCS_LST)) \
			$(addprefix vec_algebra/, $(SRCS_ALG))

OBJ_NAME = $(SRCS_NAME:.c=.o)

SRC_PATH = src

OBJ_PATH = obj

OBJ_DIRS = libchar libfd libmem libnb libstr t_lst vec_algebra

SRCS = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null
	mkdir -p $(addprefix $(OBJ_PATH)/, $(OBJ_DIRS)) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	: $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
