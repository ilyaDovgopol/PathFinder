NAME = pathfinder

LMXD = libmx

INCD = inc

LMXI:= $(LMXD)/$(INCD)

SRCD = src

OBJD = obj

LMXA:= $(LMXD)/libmx.a

INC = pathfinder.h

INCS = $(addprefix $(INCD)/, $(INC))

SRC = main.c mx_atoi.c mx_cast_error_message.c mx_city_push_index.c \
mx_free_all.c mx_restore_path_helper.c mx_initialize.c mx_isalpha.c \
mx_make_dist_matrix.c mx_parse_remaining_lines.c mx_print_path_info.c \
mx_printerr.c mx_restore_all_paths.c \

SRCS = $(addprefix $(SRCD)/, $(SRC))

OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

CFLG = -std=c11 $(addprefix -W, all extra error pedantic) -g

all: install clean

install: $(LMXA) $(NAME)

$(LMXA):
	@make -sC $(LMXD)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%)"

$(OBJD):
	@mkdir -p $@

$(OBJS): | $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t \033[31;1mdeleted\033[0m\n"

reinstall: uninstall install

