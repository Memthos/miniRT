INCLUDES:=includes
VPATH:=srcs:srcs/utils

SRCS:=minirt.c ft_round.c vectors_ops_01.c vectors_ops_02.c color_conversions.c

OBJSDIR:=objs/
OBJS:=$(addprefix $(OBJSDIR), $(SRCS:.c=.o))

LIBFTDIR:=libs/libft_tools/
LIBFT:=$(addprefix $(LIBFTDIR), libft_tools.a)

MACROLIBXDIR:=libs/MacroLibX/
MACROLIBX:=$(addprefix $(MACROLIBXDIR), libmlx.so)

LIBS:=$(LIBFT) $(MACROLIBX) -lSDL2 -lm

CC:=cc
CFLAGS:=-Werror -Wextra -Wall -I$(INCLUDES) -g

NAME:=miniRT

all: $(OBJSDIR).manda
bonus: $(OBJSDIR).bonus

$(OBJSDIR).manda: $(OBJS) | $(LIBFT) $(MACROLIBX)
	@rm -rf $(NAME) $(OBJSDIR).bonus
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBS)
	@touch $(OBJSDIR).manda
	@echo "Finished compiling miniRT"

$(OBJSDIR).bonus: $(OBJS) | $(LIBFT) $(MACROLIBX)
	@rm -rf $(NAME) $(OBJSDIR).manda
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBS)
	@touch $(OBJSDIR).bonus
	@echo "Finished compiling miniRT bonuses"

$(OBJSDIR)%.o: %.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(LIBFT):
	@make -sC $(LIBFTDIR) all

$(MACROLIBX):
	@make -sC $(MACROLIBXDIR) all -j

clean:
	@rm -drf $(OBJSDIR)
	@make -sC $(LIBFTDIR) clean
	@make -sC $(MACROLIBXDIR) clean
	@echo "Cleaned miniRT object files"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFTDIR) fclean
	@make -sC $(MACROLIBXDIR) fclean
	@echo "Cleaned miniRT"

re: fclean all

.PHONY: all bonus clean fclean re
