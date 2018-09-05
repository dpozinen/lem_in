#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 16:57:01 by dpozinen          #+#    #+#              #
#    Updated: 2018/05/15 16:57:01 by dpozinen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LEMSRC =	main.c read.c find_path.c choose_path.c tools_path.c \
			tools_validation.c tools_room.c tools_int_array.c output.c \
			boot_n_shut.c tools_1.c intersect.c extras.c tools_choose_path.c \
			tools_output.c
OBJDIR = objects
FLAGS = -Wall -Werror -Wextra -g

LEMOBJ = $(addprefix $(OBJDIR)/, $(LEMSRC:.c=.o))

LEMLIBNAME = lem_in_lib.a
NAME = lem_in

all: $(NAME)

$(NAME): make_lib $(OBJDIR) $(LEMOBJ)
	@ar rc $(LEMLIBNAME) $(LEMOBJ)
	@gcc $(FLAGS) -o $(NAME) $(LEMLIBNAME) libft/libft.a
	@echo "made ./$(NAME)"

make_lib:
	@make -C libft

$(OBJDIR):
	@mkdir $(OBJDIR)

$(LEMOBJ) : $(OBJDIR)/%.o : src/%.c
	@gcc $(FLAGS) -c $< -o $@ -I.

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(LEMLIBNAME)
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C libft

re: fclean all

go: $(NAME)
	./$(NAME) < tests/test

d: make_lib $(OBJDIR) $(LEMOBJ)
	@ar rc $(LEMLIBNAME) $(LEMOBJ)
	@gcc $(FLAGS) -g -o $(NAME)_debug $(LEMSRC) libft/libft.a -I libft/libft.h
	@echo "made ./$(NAME)_debug"
