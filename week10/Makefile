.SUFFIXES: .cpp .o
OBJECTS = vehicle.o car.o bike.o main.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean : 
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
vehicle.o : vehicle.cpp vehicle.h
car.o : car.cpp car.h
biek.o : bike.cpp bike.h

