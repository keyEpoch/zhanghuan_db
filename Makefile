CXX = g++

SRC_DIR = ./src/
TARGET = zhanghuan_db
OBJ = bplustree.o zhanghuan_db.o

$(TARGET) : $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)
	rm -rf $(OBJ)

bplustree.o:
	$(CXX) -c $(SRC_DIR)bplustree.cc

zhanghuan_db.o:
	$(CXX) -c $(SRC_DIR)zhanghuan_db.cc

clean:
	rm -rf $(OBJ) $(TARGET)
