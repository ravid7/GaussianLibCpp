
OBJS = main.o kmeans.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs

main: $(OBJS)
	$(CC) $(OBJS) -o main $(LFLAGS)

main.o: main.cpp kmeans.h
	$(CC) $(CFLAGS) main.cpp $(LFLAGS)

kmeans.o: kmeans.cpp kmeans.h
	$(CC) $(CFLAGS) kmeans.cpp $(LFLAGS)

clean:
	rm -f *.o main *.out

tar:
	tar cfv Kmeans Makefile *.cpp *.h
