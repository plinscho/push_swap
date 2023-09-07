NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -MMD 
PUSH = push_swap.h
SRC = main.c input.c index.c nodes.c free.c \
		push.c radix_sort.c rotate.c swap.c sort.c sort_utils.c \

OBJECTS = $(SRC:.c=.o)
DEPS = $(patsubst %.o,%.d,$(OBJECTS))

all: ${NAME}

%.o: %.c
	@printf "\rCompiling push_swap: $< \n"
	$(CC) -c ${CFLAGS} $< -o $@

${NAME}: ${OBJECTS} ${PUSH} Makefile
	cc ${CFLAGS} -o ${NAME} ${OBJECTS}
	@printf "Programm compiled successfully!\n"

clean:
	@rm -rf *.d
	@rm -rf *.o
	@printf "Cleaned push_swap\n"

fclean: clean
	@rm $(NAME)
	@printf "Cleaned object files!\n"

re: fclean all

-include $(DEPS)

.PHONY: clean all fclean re