#Makefile do programu z ćwiczenia 4#
.SUFFIXES: .c
NAME1 = cw4
NAME2 = cw4f
EXEC1 = cw4.x
EXEC2 = $(NAME2).x
OBJS1 = $(NAME1).o
#KOMENDY KOMPILACJI#
CFLAGS = -Wall -O -fPIC
LFLAGS = -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
#fUNKCJA URUCHAMIAJĄCA PROGRAM#
.PHONY: all
all: $(EXEC1)
%.o:%.c
	$(CO) $(CFLAGS) -c $<
$(EXEC1): $(OBJS1)
	$(CO) $(NAME1).c $(NAME2).c -o $(EXEC1) $(CFLAGS)
.PHONY: run
run: $(EXEC1)
	./$(EXEC1) in out
#SPRZĄTANIE#
.PHONY: clean tar
clean:
	rm -f *~ *.o *.a *.so *.x core core* a.out;
tar: clean
	(cd ../; tar -cvzf cw4.tar.gz cw4)
