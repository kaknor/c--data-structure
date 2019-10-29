CXX=g++
EXEC=a.out

all: 
	$(CXX) -std=c++17 -g -Wall -Werror *.cpp *.hh

test:
	./$(EXEC) -s

clean:
	$(RM) *~ *.o $(EXEC)
	$(RM) -r a.out.dSYM
	$(RM) *.gch
