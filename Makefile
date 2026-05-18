INCLUDES:=includes
VPATH:=srcs:srcs/array:srcs/parser:srcs/utils

SRCS:=minirt.c color_conversions.c add_array_slot.c parser.c

OBJSDIR:=objs/
OBJS:=$(addprefix $(OBJSDIR), $(SRCS:.c=.o))

LIBTOOLDIR:=libs/lib_tools/
LIBTOOL:=$(addprefix $(LIBTOOLDIR), lib_tools.a)

MACROLIBXDIR:=libs/MacroLibX/
MACROLIBX:=$(addprefix $(MACROLIBXDIR), libmlx.so)

LIBS:=$(LIBTOOL) $(MACROLIBX) -lSDL2 -lm

CC:=cc
CFLAGS:=-Werror -Wextra -Wall -I$(INCLUDES) -g

NAME:=miniRT

all: $(OBJSDIR).manda
bonus: $(OBJSDIR).bonus

$(OBJSDIR).manda: $(OBJS) | $(LIBTOOL) $(MACROLIBX)
	@rm -rf $(NAME) $(OBJSDIR).bonus
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBS)
	@touch $(OBJSDIR).manda
	@echo "Finished compiling miniRT"

$(OBJSDIR).bonus: $(OBJS) | $(LIBTOOL) $(MACROLIBX)
	@rm -rf $(NAME) $(OBJSDIR).manda
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBS)
	@touch $(OBJSDIR).bonus
	@echo "Finished compiling miniRT bonuses"

$(OBJSDIR)%.o: %.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(LIBTOOL):
	@make -sC $(LIBTOOLDIR) all

$(MACROLIBX):
	@make -sC $(MACROLIBXDIR) all -j

clean:
	@rm -drf $(OBJSDIR)
	@make -sC $(LIBTOOLDIR) clean
	@make -sC $(MACROLIBXDIR) clean
	@echo "Cleaned miniRT object files"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBTOOLDIR) fclean
	@make -sC $(MACROLIBXDIR) fclean
	@echo "Cleaned miniRT"

re: fclean all

norme:
	@norminette includes srcs | grep -v OK

.PHONY: all bonus clean fclean re norme
