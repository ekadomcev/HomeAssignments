PROJECT = avl_demo
TEST_PROJECT = test_avl_tree

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror -Isrc

BIN_DIR = bin
OBJ_DIR = obj

SRC = src/main.cpp src/AVLTree.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_SRC = tests/test_avl_tree.cpp src/AVLTree.cpp
TEST_OBJ = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean cleanall test

all: $(BIN_DIR)/$(PROJECT)

test: $(BIN_DIR)/$(TEST_PROJECT)
	./$(BIN_DIR)/$(TEST_PROJECT)

$(BIN_DIR)/$(PROJECT): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(BIN_DIR)/$(TEST_PROJECT): $(TEST_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -rf $(OBJ_DIR)

cleanall:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
