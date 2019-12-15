.SUFFIXES: .cpp .o

OBJECTS = array_2d.o block.o color_block.o big_block.o fold_block.o tree_block.o cross_block.o

MAIN = main.o $(OBJECTS)
CXX = g++

TARGET = test
$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean:
	rm -rf $(MAIN) $(TARGET)

main.o = main.cpp
array_2d.o = array_2d.cpp
block.o = block.cpp
color_block.o = color_block.cpp
big_block.o = big_block.cpp
fold_block.o = fold_block.cpp
tree_block.o = tree_block.cpp
cross_block.o = cross_block.cpp

