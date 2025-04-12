TARGET = Rat_OMP.out
CC = g++

SRC = $(wildcard *.cpp)
OBG = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET) : $(OBG)
	$(CC) $(OBG) -fopenmp -lgomp -o $(TARGET)

%.o : %.cpp
	$(CC) -c -fopenmp $< -fopenmp -lgomp -o $@


