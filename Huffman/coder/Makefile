CFLAGS := -Wall -Wextra

all : exe
	@echo "Bien compilé"

exe : coder.o fonctions_coder.o
	@gcc $^ -o $@

%.o : %.c
	@gcc -c $< -o $@ $(CFLAGS)

clean :
	@rm -f *.o
	@rm -f exe
	@echo "Tout est effacé"
