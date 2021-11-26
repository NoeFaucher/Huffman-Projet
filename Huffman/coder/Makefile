CFLAGS := -Wall -Wextra -g

SRC = main.c \
			coder.c \
			fonctions_coder.c \
			tri.c \

OBJ = $(SRC:%.c=obj/%.o)

DEPS = $(OBJ:%.o=%.d)

all : obj/ exe

obj/ :
	@mkdir -p obj

exe : $(OBJ)
	@gcc $^ -o $@
	@echo Compilation terminée.

obj/%.o : src/%.c
	@echo Compilation de $< ...
	@gcc -MMD -c $< -o $@ $(CFLAGS)
# MMD
clean :
	@rm -rf obj
	@rm -f exe
	@echo "Tout est effacé"

-include $(DEPS)
