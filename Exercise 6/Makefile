.SUFFIZES: .c .o .x .h
DIR ='basename $(CURDIR)'
NAME1 = Library
NAME2 = cw6
NAME3 = process
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
#komendy kompilacji#
CFLAGS = -Wall -O -fPIC -pthread
LFLAGS = -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
#FUNKCJA KOMPILUJĄCA I URUCHAMIAJĄCA PROGRAM#
.PHONY: all
all: $(EXEC2) $(EXEC3)
%.o: %.c
	$(CO) $(CFLAGS) -c $<
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(NAME1).c $(LFLAGS) -pthread $^
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(NAME1).c $(LFLAGS) -pthread $^
#uruchamienie#
.PHONY: run
run: $(EXEC3) $(EXEC2)
	./$(EXEC2) $(EXEC3) 2 3
.PHONY: clean tar
clean:
	rm -f *~ *.o *.a *.so *.x core core* a.out;
tar: clean
	(cd ../; tar -cvzf cw6.tar.gz Exercise6)
