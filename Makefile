NAME	:= minirt

#Compiler options#

CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./lib/MLX42
SRCDIR  := ./src

#Libft#

#LIBFT_DIR	:= ./lib/libft/
#LIBFT		:= $(LIBFT_DIR)/libft.a

HEADERS	:= -I ./inc -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
			
SRCS	:= $(SRCDIR)/main.c $(SRCDIR)/definitions.c \
			$(SRCDIR)/parsing.c \
			$(SRCDIR)/file_handler.c \
			$(SRCDIR)/parsing_utils.c \
			$(SRCDIR)/error_functions.c \
			$(SRCDIR)/objects_parser.c \ 
			$(SRCDIR)/tuple_operations_one.c \
			$(SRCDIR)/tuple_operations_two.c \
			$(SRCDIR)/rays.c $(SRCDIR)/sphere.c \
			$(SRCDIR)/intersections.c \
			$(SRCDIR)/matrix_operations.c \
			$(SRCDIR)/matrix_inverse.c \
OBJS	:= ${SRCS:.c=.o}

#all: libmlx $(LIBFT) $(NAME)
all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

#$(LIBFT) :
#	@make -C $(LIBFT_DIR)

clean:
#	make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
#	rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx