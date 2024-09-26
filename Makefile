NAME	:= miniRT

#Compiler options#
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./lib/MLX42
SRCDIR  := ./src
PARSE_DIR = $(SRCDIR)/parse

#Libft#
LIBFT_DIR	:= ./lib/Libft/
LIBFT		:= $(LIBFT_DIR)/libft.a

HEADERS	:= -I ./inc -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm	
SRCS	:= $(SRCDIR)/definitions.c \
			$(SRCDIR)/color_utils.c \
			$(SRCDIR)/cylinder.c \
			$(PARSE_DIR)/filehandler.c \
			$(PARSE_DIR)/parsing.c \
			$(PARSE_DIR)/parsing_utils.c \
			$(PARSE_DIR)/objects_parser.c \
			$(SRCDIR)/error_functions.c \
			$(SRCDIR)/tuple_operations_one.c \
			$(SRCDIR)/tuple_operations_two.c \
			$(SRCDIR)/rays.c $(SRCDIR)/sphere.c \
			$(SRCDIR)/intersections.c \
			$(SRCDIR)/matrix_operations.c \
			$(SRCDIR)/matrix_inverse.c \
			$(SRCDIR)/matrix_transform.c \
			$(SRCDIR)/matrix_transformations_utils.c \
			$(SRCDIR)/normal.c \
			$(SRCDIR)/matrix_utils.c \
			$(SRCDIR)/reflection.c \
			$(SRCDIR)/world.c \
			$(SRCDIR)/testing_main.c \
			$(SRCDIR)/plane.c \
			$(SRCDIR)/debug.c \
			$(SRCDIR)/color_operations.c \
			$(SRCDIR)/create_structs.c \
			$(SRCDIR)/clean_structs.c \
			$(SRCDIR)/clean_structs_two.c \
			$(SRCDIR)/light.c \
			$(SRCDIR)/view_transform.c \
			$(SRCDIR)/camera.c \
			$(SRCDIR)/shadows.c \
			$(SRCDIR)/pattern.c \
			$(SRCDIR)/cones.c \
			$(SRCDIR)/start_mlx.c \
			$(SRCDIR)/hook.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME)
#all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(PARSE_DIR)/%.o: $(PARSE_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

$(LIBFT) :
	@make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
