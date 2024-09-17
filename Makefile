NAME	:= minirt

#Compiler options#
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./lib/MLX42
SRCDIR  := ./src

#Libft#
LIBFT_DIR	:= ./lib/Libft/
LIBFT		:= $(LIBFT_DIR)/libft.a

HEADERS	:= -I ./inc -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm	
SRCS	:= $(SRCDIR)/definitions.c \
			$(SRCDIR)/color_utils.c \
			$(SRCDIR)/cylinder.c \
			$(SRCDIR)/filehandler.c \
			$(SRCDIR)/parsing.c \
			$(SRCDIR)/parsing_utils.c \
			$(SRCDIR)/objects_parser.c \
			$(SRCDIR)/error_functions.c \
			$(SRCDIR)/tuple_operations_one.c \
			$(SRCDIR)/tuple_operations_two.c \
			$(SRCDIR)/rays.c $(SRCDIR)/sphere.c \
			$(SRCDIR)/intersections.c \
			$(SRCDIR)/matrix_operations.c \
			$(SRCDIR)/matrix_inverse.c \
			$(SRCDIR)/matrix_transformations.c \
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
			$(SRCDIR)/new_light.c \
			$(SRCDIR)/view_transform.c \
			$(SRCDIR)/camera.c \
			$(SRCDIR)/shadows.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME)
#all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
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
