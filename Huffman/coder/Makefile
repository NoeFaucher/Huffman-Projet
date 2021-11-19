CFLAGS := -Wall -Wextra -g

SRC = coder.c \
			fonctions_coder.c \
			tri.c \

OBJ = $(SRC:.c=.o)

all : exe
	@echo "Bien compilé"

exe : $(OBJ)
	@gcc $^ -o $@

%.o : src/%.c
	@gcc -c $< -o $@ $(CFLAGS)

clean :
	@rm -rf obj
	@rm -f *.o
	@rm -f exe
	@echo "Tout est effacé"
