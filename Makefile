PUSH_SWAP = push_swap
CHECKER = checker
SRC = ./src/ft_algorithm_sort.c \
			./src/ft_big_bubble_sort.c \
			./src/ft_bubble_sort.c \
			./src/ft_checker.c \
			./src/ft_delete_first.c \
			./src/ft_delete_last.c \
			./src/ft_get_index_value.c \
			./src/ft_lst_bubble_reverse_sort.c \
			./src/ft_lst_bubble_sort.c \
			./src/ft_lst_is_over.c \
			./src/ft_lst_is_revsorted.c \
			./src/ft_lst_is_under.c \
			./src/ft_lst_issorted.c \
			./src/ft_lst_len.c \
			./src/ft_lst_max.c \
			./src/ft_lst_median.c \
			./src/ft_lst_min.c \
			./src/ft_lst_values.c \
			./src/ft_max_under_max.c \
			./src/ft_operations.c \
			./src/ft_operations_print.c \
			./src/ft_parsing_input.c \
			./src/ft_print_stacks.c \
			./src/ft_push_ab.c \
			./src/ft_push_back.c \
			./src/ft_push_front.c \
			./src/ft_push_max.c \
			./src/ft_push_min.c \
			./src/ft_push_selected_value.c \
			./src/ft_reverse_rotate.c \
			./src/ft_rotate.c \
			./src/ft_shell_help.c \
			./src/ft_swap_one_two.c \
			./src/get_next_line.c \
			./src/shell.c \
			./src/ft_visual_in_terminal.c \
			./src/ft_update_spe.c \
			./src/ft_free_tab.c
PUSH_SWAP_C = ./src/push_swap.c
CHECKER_C = ./src/checker.c
OBJ = $(SRC:.c=.o)
PUSH_SWAP_O = $(PUSH_SWAP_C:.c=.o)
CHECKER_O = $(CHECKER_C:.c=.o)

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

INC = ./includes
LIB = ./libft
PF = ./ft_printf

.PHONY: clean fclean all re lib

all: lib pf $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ) $(PUSH_SWAP_O)
				@echo Compiling $(PUSH_SWAP)
				@$(GCC) $(FLAGS) -o $(PUSH_SWAP) $(OBJ) $(PUSH_SWAP_O) -I $(INC) -L $(LIB) -lft -L $(PF) -lftprintf
				@echo ======[Done]======

$(CHECKER): $(OBJ) $(CHECKER_O)
				@echo Compiling $(CHECKER)
				@$(GCC) $(FLAGS) -o $(CHECKER) $(OBJ) $(CHECKER_O) -I $(INC) -L $(LIB) -lft -L $(PF) -lftprintf
				@echo ======[Done]======

$(OBJ): src/%.o : src/%.c
				@echo "$(PUSH_SWAP)|$(CHECKER) >>> Add/Update $^"
	    	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

$(PUSH_SWAP_O): src/%.o : src/%.c
				@echo "$(PUSH_SWAP) --> Add/Update $^"
	    	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

$(CHECKER_O): src/%.o : src/%.c
				@echo "$(CHECKER) --> Add/Update $^"
	    	@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

lib:
				@$(MAKE) -C $(LIB)
pf:
				@$(MAKE) -C $(PF)

clean:
				@$(MAKE) -C $(LIB) clean
				@$(MAKE) -C $(PF) clean
				@echo Clean objects $(PUSH_SWAP) - $(CHECKER)
				@rm -rf $(OBJ) $(PUSH_SWAP_O) $(CHECKER_O)

fclean: clean
				@$(MAKE) -C $(LIB) fclean
				@$(MAKE) -C $(PF) fclean
				@echo Clean $(PUSH_SWAP) - $(CHECKER)
				@rm -rf $(PUSH_SWAP) $(CHECKER)
				@echo ======[Clean]======

re: fclean all
