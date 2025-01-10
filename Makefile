# 🎨 **Définition des couleurs pour les messages echo**
RESET   = \033[m
CYAN    = \033[0;96m
YELLOW  = \033[0;93m
RED     = \033[1;91m
GREEN   = \033[1;92m
MAGENTA = \033[0;95m
BLUE    = \033[1;94m
WHITE	= \033[0;97m

# 🛠 **Variables de compilation**
CC      = cc
NAME    = so_long

# 📂 **Organisation des fichiers**
OBJ_DIR = obj
SRCS    = srcs/display.c \
          srcs/display_movement.c \
          srcs/parsing_map.c \
          srcs/parsing_map_checker.c \
          srcs/exit_data.c \
          srcs/handle_input.c \
          srcs/handle_input_aux.c \
          srcs/init_data.c \
          srcs/init_assets.c \
          srcs/so_long.c \
          srcs/init_map.c \
          srcs/so_long_utils.c \
          srcs/check_path.c

HEADER  = includes/so_long.h

# ⚙️ **Génération de la liste des fichiers objets**
OBJS    = $(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# 📚 **Librairies et Flags**
MLX     = MacroLibX/libmlx.so 
LIBFT   = libft/libft.a
CFLAGS  = -Wall -Wextra -Iincludes -g 
LDFLAGS = $(MLX) $(LIBFT) $(shell pkg-config --libs sdl2)

# 📌 **Règle par défaut**
all: $(NAME)

# 📦 **Compilation de la librairie MLX**
MacroLibX:
	@echo "[Git] $(BLUE)Clone de la : 'MacroLibX'$(WHITE)"
	@git clone https://github.com/seekrs/MacroLibX.git

$(MLX): MacroLibX
	@echo "[Makefile] $(CYAN)Compilation de MacroLibX...$(RESET)"
	@make -j -C MacroLibX > /dev/null 2>/dev/null
	@echo "[Makefile] $(GREEN)MacroLibX compilé avec succès !$(RESET)"

# 📦 **Compilation de la librairie libft**
$(LIBFT):
	@echo "[Makefile] $(CYAN)Compilation de libft...$(RESET)"
	@make -C libft > /dev/null
	@echo "[Makefile] $(GREEN)libft compilée avec succès !$(RESET)"
	@echo "[Makefile] $(GREEN)libft est prête !$(RESET)"

# 🔗 **Création de l'exécutable**
$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@echo "[Makefile] $(CYAN)Lien des objets pour créer $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "[Makefile] $(GREEN)$(NAME) a été créé avec succès !$(RESET)"

# 🗂 **Compilation des fichiers .c en .o (dans obj/)**
$(OBJ_DIR)/%.o: srcs/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[Makefile] $(YELLOW)Compilation de $< -> $@$(RESET)"

# 🧹 **Nettoyage des fichiers objets**
clean:
	@rm -rf $(OBJ_DIR)
	@echo "[Makefile] $(RED)Suppression du dossier $(OBJ_DIR).$(RESET)"
	@echo "[Makefile] $(CYAN)Nettoyage de libft...$(RESET)"
	@make clean -C libft > /dev/null
	@echo "[Makefile] $(GREEN)libft nettoyée avec succès !$(RESET)"
	@echo "[Makefile] $(CYAN)Nettoyage de MacroLibX...$(RESET)"
	@make clean -C MacroLibX > /dev/null
	@echo "[Makefile] $(GREEN)MacroLibX nettoyé avec succès !$(RESET)"

# 🧹 **Nettoyage complet (objets, exécutables, librairies)**
fclean: clean
	@rm -f $(NAME)
	@echo "[Makefile] $(RED)Suppression de l'exécutable $(NAME).$(RESET)"
	@rm -f $(LIBFT)
	@echo "[Makefile] $(RED)Suppression de libft.a.$(RESET)"
	@rm -f MacroLibX/libmlx.so
	@echo "[Makefile] $(RED)Suppression de libmlx.so.$(RESET)"

# 🔄 **Recompilation complète**
re: fclean all
	@echo "[Makefile] $(MAGENTA)Recompilation complète terminée.$(RESET)"

# 🚀 **Règles pratiques pour exécuter le programme**
run: all
	@echo "[Makefile] $(BLUE)Lancement de $(NAME)...$(RESET)"
	@./$(NAME) $(ARGS)

run2: all
	@echo "[Makefile] $(BLUE)Lancement de $(NAME) avec Valgrind...$(RESET)"
	@valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARGS)

.PHONY: all clean fclean re run run2
