CXXFLAGS=-Wall -Wextra -Wpedantic

main: main.o Complex.o Complex.h
	$(CXX) $(CXXFLAGS) main.o Complex.o -o $@

Complex.o:: Complex.h
main.o:: main.cc Complex.h

clean:
	rm -f main *.o
