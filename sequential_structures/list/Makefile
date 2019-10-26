EXEC=a.out

all: 
	g++ -std=c++17 -g -Wall -Werror *.cpp *.hh

test: all
	./$(EXEC) -s

clean:
	$(RM) *~ *.o $(EXEC)
	$(RM) -r a.out.dSYM 
