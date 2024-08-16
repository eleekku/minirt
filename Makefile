#---------------------------------Archive-------------------------------------#
NAME = minirt
LIBFTNAME = libft.a

#---------------------------------Flags---------------------------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -ldl -lglfw -pthread -lm
RM = rm -rf

#---------------------------------Directories---------------------------------#
SRC_DIR 	= .
LIBFT_DIR 	= ./lib/Libft
OBJ_DIR		= objects
MLX_DIR		= ./lib/MLX42

#---------------------------------MLX-----------------------------------------#
MLX_HEAD	= $(MLX_DIR)/include/MLX42/MLX42.h
MLX_A		= $(MLX_DIR)/build/libmlx42.a #-ldl -pthread -lm 
#MLX_LIBS	= $(MLX_DIR)/build #-lmlx42  #"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework Cocoa -framework OpenGL -framework IOKit

#---------------------------------Source Files--------------------------------#
SRC_FLS = 	src/minirt.c \
			src/definitions.c \
			src/parsing.c \
			src/filehandler.c \
			src/parsing_utils.c \
			src/error_functions.c \
			src/objects_parser.c \
			src/tuple_operations_one.c \
			src/tuple_operations_two.c \
			src/rays.c src/sphere.c \
			src/intersections.c \
			src/matrix_operations.c \
			src/matrix_inverse.c \

OBJS 	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FLS))

#---------------------------------Colours-------------------------------------#
RED		= \033[1;91m
YELLOW		= \033[1;33m
GREEN		= \033[1;32m
CYAN		= \033[1;36m
PURPLE		= \033[1;35m
END		= \033[0m

#---------------------------------Rules---------------------------------------#
all: libmlx $(LIBFTNAME) $(NAME)

libmlx:
	@if [ ! -d $(MLX_DIR)/build ]; then\
		cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4;\
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:  $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_HEAD) -c $< -o

$(LIBFTNAME):
	@make -C $(LIBFT_DIR)
	@make bonus -C ./lib/Libft

$(NAME): $(OBJS)
	@echo "${YELLOW}|------------------------>${PURPLE}Compiling miniRT${YELLOW}<--------------------|${END}"
	$(CC) $(CFLAGS) $(MLX_HEAD) $(OBJS) $(MLX_A) $(MLX_LIBS) $(LIBFT_DIR)/$(LIBFTNAME)
	@echo "${YELLOW}|---------------->${GREEN}Congrats miniRT Compiled Successfully${YELLOW}<----------------|${END}"

clean:
	$(RM) $(OBJ_DIR) $(MLX_DIR)/build
	@make clean -C lib/Libft/
	@echo "${YELLOW}|------------------------>${RED}miniRT Cleaned${YELLOW}<----------------------|${END}"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C lib/Libft/
	@rm -f libft/$(LIBFTNAME)

re: fclean all