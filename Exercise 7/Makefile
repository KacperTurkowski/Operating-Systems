.SUFFIXES: .c .o .x .h
DIR ='basename $(CURDIR)'
NAME1 = Library
NAME2 = cw7
EXEC2 = $(NAME2).x
OBJS2 = $(NAME2).o
OBJS1 = $(NAME1).o
##biblioteka statyczna i dzielona#
LIB_NAME = Library
#katalog dla bibliotek
LIB_DIR = ./lib
#biblioteka statyczne (static library)
LIB_STAT = lib$(LIB_NAME).a
#Biblioteka dzielona (shared library)
LIB_SHAR = lib$(LIB_NAME).so
#Pliki objektowe wchodzące do biblioteki
LIB_OBJS = $(OBJS2)
#Pliki nagłówkowe
HEAD1 = $(NAME1).h
#Komendy kompilacji
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
LDLIBS = -lrt
CO = gcc
LD = $(CO)
AR = ar
ARFLAGS = rv
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
#Tworzenie bibliotei statycznej
$(LIB_STAT): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)
#tworzenie biblioteki dzielonej
$(LIB_SHAR): $(LIB_OBJS)
	$(LD) -shared -o $@ $(LFLAGS) $(LIB_OBJS)
$(EXEC2): $(OBJS2) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) $(NAME1).c -pthread -lrt $<
.PHONY: all
all: $(EXEC2)
	$(LD) -o $@ $(NAME1).c $(LFLAGS) -pthread -lrt $^
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
$(EXEC2):
.PHONY: run
run: $(EXEC2)
	./$(EXEC2)
.PHONY: clean tar
clean:
	rm -f *.o *~ *.a *.so *.x core core* a.out;rm -rf ${LIB_DIR}
tar: clean
	(cd ../; tar -cvzf cw7.tar.gz Exercise7)
