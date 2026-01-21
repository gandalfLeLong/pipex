# -----------------------------------Makefile------------------------------------
NAME	= libft.a

# -----------------------------------Sources-------------------------------------

HEADER	= includes/libft.h

LIBFT_SRCS	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_free_tab.c \

LIBFT_SRC	= ${addprefix libft_sources/, ${LIBFT_SRCS}}


GNL_SRCS	=	get_next_line.c \
			get_next_line_utils.c \

GNL_SRC		= ${addprefix gnl_sources/, ${GNL_SRCS}}


PRINTF_SRCS	=	ft_printf.c \
			ft_printf_utils.c \

PRINTF_SRC	= ${addprefix printf_sources/, ${PRINTF_SRCS}}

ALL_SRC		= ${LIBFT_SRC} ${GNL_SRC} ${PRINTF_SRC}

OBJS	= ${ALL_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

CC		= cc

FLAGS	= -Wall -Wextra -Werror

LIB		= ar -rc

RM		= rm -f

# -----------------------------------Libraries--------------------------------------

INCLUDES = -I ./includes

# -----------------------------------Rules------------------------------------------

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
		${LIB} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${FLAGS} -c ${INCLUDES} $< -o $@

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re
