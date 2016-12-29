# Put the directory above 'DNest4' into an environment variable
# called DNEST4_PATH for this to work.

CC = g++
CXXFLAGS = -std=c++14 -O3 -Wall -Wextra -pedantic
LIBS = 

default:
	$(CC) $(CXXFLAGS) -c *.cpp
	$(CC) -o main *.o $(LIBS)
	rm *.o

