#Makefile do programu z ćwiczenia 5#
.SUFFIXES: .c .h
NAME1 = cw5a
NAME2 = function
NAME3 = consumer
NAME4 = producer
EXEC1 = $(NAME1).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
OBJS1 = $(NAME1).o
OBJS3 = $(NAME3).o
OBJS4 = $(NAME4).o
#KOMENDY KOMPILACJI#
CFLAGS = -Wall -O -fPIC
LFLAGS = -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
#FUNKCJA URUCHAMIAJĄCA PROGRAM#
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)
%.o:%.c
	$(CO) $(CFLAGS) -c $<
$(EXEC1): $(OBJS1)
	$(CO) $(NAME1).c $(NAME2).c -o $(EXEC1) $(CFLAGS)
$(EXEC3): $(OBJS3)
	$(CO) $(NAME3).c -o $(EXEC3) $(CFLAGS)
$(EXEC4): $(OBJS4)
	$(CO) $(NAME4).c -o $(EXEC4) $(CFLAGS)
.PHONY: run
run: $(EXEC1)
	./$(EXEC1) in out
.PHONY: cw5b
cw5b: $(EXEC3) $(EXEC4)
	mkfifo fifo
	xterm -hold -title Konsument -e ./$(EXEC3) out &
	xterm -hold -title Producent -e ./$(EXEC4) in
	diff -s in out
#SPRZĄTANIE#
.PHONY: clean tar
clean:
	rm fifo -f *~ *.o *.a *.so *.x core core* a.out;
tar: clean
	(cd ../; tar -cvzf cw5.tar.gz Exercise5)
