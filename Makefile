src = *.c
push_swap = push_swap
FLAGS = -Wall -Wextra -Werror
CC = cc

all : push_swap
	
$(push_swap): $(src)	
	@$(CC) $(FLAGS) $(src) -o push_swap
	@tput setaf 2; echo "PUSH_SWAP IS READY"

clean :
	@rm -f push_swap
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all

src_bonus = ./bonus/checker.c functions.c linked_list_nodes.c ./bonus/get_next_line.c moves.c move2.c functions2.c check_Errors.c ./bonus/get_next_line_utils.c 
checker = checker
FLAGS = -Wall -Wextra -Werror
CC = cc

bonus : checker

$(checker) : $(src_bonus)
	@$(CC) $(FLAGS) $(src_bonus) -o checker
	@tput setaf 2; echo "BONUS IS READY"

clean_bonus :
	@rm -f checker
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all