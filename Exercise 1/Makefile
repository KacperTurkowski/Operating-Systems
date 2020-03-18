.SUFFIXES: .c
DIR = 'basename $(CURDIR)'
NAME1 = cw1a
NAME2 = cwb
NAME3 = cw1c
NAME4 = cw1d
NAME5 = cw1e
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
OBJS4 = $(NAME4).o
OBJS5 = $(NAME5).o
#komendy kompilacji#
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
#funkcja kompilująca wszytskie programy#
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)
%.o:%.c
	$(CO) $(CFLAGS) -c $<
%.o:%.c
	$(CO) $(CFLAGS) -c $<
$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC4): $(OBJS4)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC5): $(OBJS5)
	$(LD) -o $@ $(LFLAGS) $^
#funkcja uruchamiająca poszczególne programy#
.PHONY:a b c d e
a: $(EXEC1)
	./$(EXEC1)
b: $(EXEC2)
	./$(EXEC2)
c: $(EXEC3)
	./$(EXEC3);sleep 5
d: $(EXEC4)
	./$(EXEC4)
e: $(EXEC5)
	./$(EXEC5)
#funkcja czyscząca pliki po użytkowaniu#
.PHONY: clean tar
clean:
	rm -f *~ *.o *.a *.so *.x core core* a.out;
tar: clean
	(cd ../; tar -cvzf cw1.tar.gz  cw1 )

