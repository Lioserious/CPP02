# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 10:36:24 by lihrig            #+#    #+#              #
#    Updated: 2026/02/24 14:20:39 by lihrig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                 CONFIGURATION                                 #
# ============================================================================ #

# Name des finalen Programms
NAME        = program

# Compiler und Flags
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# Source-Dateien
SRCS        = main.cpp \
			fixed.cpp \
			compare.cpp \
			arithmetics.cpp \
			IncrementDecrement.cpp \
			MinMax.cpp \

# Objekt-Dateien Ordner
OBJS_DIR    = objects

# Objekt-Dateien (automatisch generiert aus SRCS)
OBJS        = $(SRCS:.cpp=.o)

# Vollständige Pfade für Objekt-Dateien
OBJS_FULL   = $(addprefix $(OBJS_DIR)/, $(OBJS))

# ============================================================================ #
#                                   FARBEN                                      #
# ============================================================================ #

# ANSI Escape-Codes für Farben
RESET       = \033[0m
BOLD        = \033[1m
DIM         = \033[2m

# Farben
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
MAGENTA     = \033[35m
CYAN        = \033[36m
WHITE       = \033[37m

# Hintergrundfarben
BG_GREEN    = \033[42m
BG_BLUE     = \033[44m

# ============================================================================ #
#                                 PROGRESS BAR                                  #
# ============================================================================ #

# Zähler für kompilierte Dateien
COMPILED    = 0
TOTAL       = $(words $(SRCS))

# Fortschrittsbalken-Funktion
define progress_bar
	$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	$(eval PERCENT=$(shell echo $$(($(COMPILED)*100/$(TOTAL)))))
	$(eval FILLED=$(shell echo $$(($(PERCENT)/5))))
	$(eval EMPTY=$(shell echo $$((20-$(FILLED)))))
	@printf "$(CYAN)$(BOLD)[$(RESET)"
	@printf "$(GREEN)$(BG_GREEN)%*s$(RESET)" $(FILLED) "" | tr ' ' '='
	@printf "%*s" $(EMPTY) "" | tr ' ' '-'
	@printf "$(CYAN)$(BOLD)]$(RESET) "
	@printf "$(YELLOW)$(BOLD)%3d%%$(RESET) " $(PERCENT)
	@printf "$(WHITE)Compiling: $(MAGENTA)$<$(RESET)\n"
endef

# ============================================================================ #
#                                    RULES                                      #
# ============================================================================ #

# Default-Target: Kompiliert das Programm
all: header $(NAME)

# Header-Banner beim Start
header:
	@echo "$(CYAN)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║$(YELLOW)$(BOLD)                    COMPILING FIXED                   $(CYAN)║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""

# Linken: Verbindet alle .o Dateien zum finalen Programm
$(NAME): $(OBJS_FULL)
	@echo ""
	@echo "$(BLUE)$(BOLD)🔗 Linking objects...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS_FULL) -o $(NAME)
	@echo ""
	@echo "$(GREEN)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║$(BOLD)                  ✅ COMPILATION SUCCESSFUL!                 $(GREEN)║$(RESET)"
	@echo "$(GREEN)╠════════════════════════════════════════════════════════════╣$(RESET)"
	@echo "$(GREEN)║$(RESET)  $(WHITE)Executable:$(RESET) $(MAGENTA)$(BOLD)./$(NAME)$(RESET)                                    $(GREEN)║$(RESET)"
	@echo "$(GREEN)║$(RESET)  $(WHITE)Files compiled:$(RESET) $(YELLOW)$(TOTAL)$(RESET)                                    $(GREEN)║$(RESET)"
	@echo "$(GREEN)╚════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""

# Kompilieren: Erstellt .o Dateien aus .cpp Dateien
$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(call progress_bar)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean: Löscht Objekt-Dateien
clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)✅ Object files removed!$(RESET)"
	@echo ""

# Fclean: Löscht alles (Objekte + Binary)
fclean: clean
	@echo "$(YELLOW)🗑️  Removing executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✅ Executable removed!$(RESET)"
	@echo ""

# Re: Alles neu kompilieren
re: fclean all

# ============================================================================ #
#                                    PHONY                                      #
# ============================================================================ #

# Phony-Targets (keine echten Dateien)
.PHONY: all clean fclean re header

