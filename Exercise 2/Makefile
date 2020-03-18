#Kacper Turkowski#
#Makefile do programy z zadania 2#
.SUFFIXES: .c
#nazwy#
NAME1 = cw1a
NAME2 = cwb
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
#komendy kompilatora#
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
CO = gcc
LD = $(CO)
#kompilacja #
.PHONY: all
all: $(EXEC1) $(EXEC2)
%.o:%.c
	$(CO) $(CLAGS) -c $<
$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
#uruchamianie#
.PHONY: run
run: $(EXEC2) $(EXEC1)
	./$(EXEC2) $(EXEC1)
#sprzątanie#
.PHONY: clean tar
clean:
	rm -f *~ *.o *.a *.so *.x core core* a.out;
#pakowanie#
tar: clean
	(cd ../; tar -cvzf cw2.tar.gz cw2 )
