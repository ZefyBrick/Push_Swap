# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2019/09/27 18:20:30 by cdubuque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap

CH = checker

INC = ./inc/push_swap.h

LIB = libft/libft.a

PSFILES = push_swap.c commands.c ft_validation.c ft_mas_order.c \
		ft_analizator.c ft_sort.c ft_sort_1.c ft_operations.c ft_other.c

CHFILES = checker.c get_next_line.c commands.c ft_validation.c ft_mas_order.c\
		ft_colors.c ft_visual.c ft_other.c ft_analizator.c ft_sort.c \
		ft_sort_1.c ft_operations.c\

PSSRC = $(addprefix src/,$(PSFILES))

PSOBJ = $(addprefix obj/,$(PSFILES:.c=.o))

CHSRC = $(addprefix src/,$(CHFILES))

CHOBJ = $(addprefix obj/,$(CHFILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

all : $(PS) $(CH) 

$(PS) : $(PSOBJ)
	make -C libft/
	gcc -o $(PS) $(PSOBJ) $(LIB)
	
$(CH) : $(CHOBJ)
	make -C libft/
	gcc -o $(CH) $(CHOBJ) $(LIB)

obj/%.o: src/%.c $(INC)
	mkdir -p obj/
	gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	make clean -C libft/
	rm -rf obj/

fclean : clean
	make fclean -C libft
	rm -f $(PS)
	rm -f $(CH)

re : fclean all

# NAME = push_swap.a
# PUSH_SWAP = push_swap
# CHECKER = checker

# SRC = commands.c \
# 		get_next_line.c \
# 		ft_validation.c \
# 		ft_mas_order.c \
# 		ft_analizator.c \
# 		ft_sort.c \
# 		ft_sort_1.c \
# 		ft_operations.c \
# 		ft_colors.c \
# 		ft_visual.c \
# 		ft_other.c
		
# SRCLIB = ./libft/*.o

# FLAGS = -Wall -Wextra -Werror

# HEADER = ./

# OBJC = $(SRC:.c=.o)
# LIBFT = ./libft/
# LIB = ./libft/libft.a

# LIBOBJS = $(wildcard ./libft/*.o)

# $(NAME): $(OBJC)
# 	make -C $(LIBFT)
# 	ar -rc $(NAME) $(OBJC) $(SRCLIB)
# 	ranlib $(NAME)
# 	gcc $(FLAGS) -o $(PUSH_SWAP) push_swap.c $(NAME) $(LIB)
# 	gcc $(FLAGS) -o $(CHECKER) checker.c $(NAME) $(LIB)

# #cp $(LIB) ./$(NAME)

# all: $(NAME)

# $(OBJC): %.o : %.c
# 	gcc -c  $(FLAGS) $<

# clean:
# 	/bin/rm -f $(OBJC)
# 	make -C $(LIBFT) clean

# fclean: clean
# 	/bin/rm -f $(NAME)
# 	make -C $(LIBFT) fclean

# re: fclean all

# debug:
# 	echo $(SRC)
# 	echo
# 	echo $(OBJC)
# 	echo
# 	echo $(LIBOBJS)