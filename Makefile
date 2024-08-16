#---------------------------------Archive-------------------------------------#
NAME = fdf
LIBFTNAME = libft.a

#---------------------------------Flags---------------------------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -ldl -lglfw -pthread -lm
RM = rm -rf

#---------------------------------Directories---------------------------------#
SRC_DIR 	= .
LIBFT_DIR 	= ./lib/libft
OBJ_DIR		= objects
MLX_DIR		= ./lib/MLX42

#---------------------------------MLX-----------------------------------------#
MLX_HEAD	= $(MLX_DIR)/include/MLX42/MLX42.h
MLX_A		= $(MLX_DIR)/build/libmlx42.a #-ldl -pthread -lm 
#MLX_LIBS	= $(MLX_DIR)/build #-lmlx42  #"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework Cocoa -framework OpenGL -framework IOKit

#---------------------------------Source Files--------------------------------#
SRC_FLS = 	fdf.c draw.c colors.c fdf_utils.c keys.c

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
	@make bonus -C ./lib/libft

$(NAME): $(OBJS)
	@echo "${YELLOW}|------------------------>${PURPLE}Compiling fil de fer (fdf)${YELLOW}<--------------------|${END}"
	$(CC) $(CFLAGS) $(MLX_HEAD) $(OBJS) $(MLX_A) $(MLX_LIBS) $(LIBFT_DIR)/$(LIBFTNAME) $(LIBFT_DIR)/ft_printf/libftprintf.a
	@echo "${YELLOW}|---------------->${GREEN}Congrats Fil De Fer (fdf) Compiled Successfully${YELLOW}<----------------|${END}"

clean:
	$(RM) $(OBJ_DIR) $(MLX_DIR)/build
	@make clean -C lib/libft/
	@echo "${YELLOW}|------------------------>${RED}Fil de Fer (fdf) Cleaned${YELLOW}<----------------------|${END}"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C lib/libft/
	@rm -f libft/$(LIBFTNAME)

re: fclean all