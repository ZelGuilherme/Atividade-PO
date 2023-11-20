main.exe: main.o matrixManipulation.o
	g++ main.o matrixManipulation.o -o main.exe

matrixManipulation.o: classes/matrixManipulation.cpp
	g++ -c classes/matrixManipulation.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	del *.o