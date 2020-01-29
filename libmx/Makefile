NAME = libmx.a

INC = libmx.h

SRC = binary_search bubble_sort count_substr count_words create_node \
del_extra_spaces del_strarr file_to_str foreach get_char_index \
get_substr_index hex_to_nbr isspace itoa list_size memccpy memchr memcmp \
memcpy memmem memmove memrchr memset nbr_to_hex pop_back pop_front pow \
print_strarr print_unicode printchar printint printstr push_back push_front \
quicksort read_line realloc replace_substr sort_list sqrt str_reverse strcat \
strcmp strcpy strdel strdup strjoin strlen strncmp strncpy strndup strnew \
strsplit strstr strtrim swap_char \

SRCS = $(addsuffix .c, $(addprefix mx_, $(SRC)))

OBJ = $(SRCS:.c=.o)

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@mkdir -p obj
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLGS) -c $(SRCS) -I $(INC)
	@ar -rc $(NAME) $(OBJ)
	@mv $(OBJ) ./obj
	@rm -rf $(SRCS) $(INC)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf ./obj
reinstall: uninstall install

