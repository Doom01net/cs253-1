# This is a little Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know
# that what looks like leading spaces is really a leading tab character.
#
# 1) Type “make”, observe what happens.
# 2) Run the resulting program “small”.
#
# 3) Type “make”, again.  Why did nothing much happen?
#
# 4) rm small
# 5) make (What got remade, and why?)
#
# 6) rm foo.o
# 7) make (What got remade, and why?)
#
# 8) make clean (What did that do?)
# 9) make (What got remade, and why?)
#
# 10) Create a new function bar() in bar.cc & bar.h, similar to foo.cc
# 11) Change main.cc to use the new bar()
# 12) make (Why did it fail?)
# 13) Fix the Makefile
#
# 14) Uncomment the CXXFLAGS= line.
# 15) make (Why didn't anything happen?)
# 16) make clean
# 17) make (Observe the extra error-checking for g++)
#
# 18) When you type “make clean”, no file “clean” gets created.  Why not?
#
# For extra fame & glory:
#
# Consult the make tutorial at https://www.cs.colostate.edu/~cs253/make.html,
# and improve this makefile:
#
# 19) Use $@ in the rule that creates “small” itself.

CXX=g++
 CXXFLAGS=-std=c++11 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) main.o foo.o bar.o -o small

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: foo.cc foo.h
	$(CXX) $(CXXFLAGS) -c foo.cc

bar.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc
clean:
	-rm -f small *.o
