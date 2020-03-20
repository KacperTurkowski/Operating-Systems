#KACPER TURKOWSKI#
.SUFFIXES: .c
NAME1 = cw3a
NAME2 = cw3b
NAME3 = function
NAME4 = cw3c
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC4 = $(NAME4).x
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
OBJS4 = $(NAME4).o
#Komendy kompilatora#
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
#kompilacja#
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC4)
%.o:%.c
	$(CO) $(CLAGS) -c $<
$(EXEC1): $(OBJS1)
	$(CO) $(NAME1).c $(NAME3).c -o $(EXEC1) $(CFLAGS)
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC4): $(OBJS4)
	$(CO) $(NAME4).c -o $(NAME4).x $(LFLAGS)
#sprzątanie#
.PHONY: clean tar
clean:
	rm -f *~ *.o *.a *.so *.x core core* a.out;
tar: clean
	(cd ../; tar -cvzf cw3.tar.gz cw3)
