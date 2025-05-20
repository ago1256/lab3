CXX := g++
CXXFLAGS := -std=c++17 -O0

MAIN_SRCS := main.cpp interface.cpp errors.cpp
MAIN_OBJ := $(MAIN_SRCS:.cpp=.o)
MAIN_TARGET := program.exe


TEST_SRCS := time_compare.cpp errors.cpp
TEST_OBJ := $(TEST_SRCS:.cpp=.o)
TEST_TARGET := test.exe


.PHONY: all clean run test


all: $(MAIN_TARGET) $(TEST_TARGET)


run: $(MAIN_TARGET)
	./$(MAIN_TARGET)


test: $(TEST_TARGET)
	./$(TEST_TARGET)


clean:
	rm -f *.o $(MAIN_TARGET) $(TEST_TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@


$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

