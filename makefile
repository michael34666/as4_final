#Michael_dadush12@gmail.com
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra

# SFML include and library paths
SFML_INCLUDE = -I/Users/your_username/SFML/include
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
MAIN_SRCS = main.cpp
TEST_SRCS = Test.cpp

# Object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Executable names
DEMO_TARGET = main
TEST_TARGET = test

# Default target (no longer building demo by default)
all: $(TEST_TARGET)

# Link the main program (tree)
tree: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIB) $(SFML_LIBS)
	#./$@

# Link the test program
test: TestCounter.o Test.o $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIB) $(SFML_LIBS)
	./$@

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS) $(DEMO_TARGET) $(TEST_TARGET) TestCounter.o tree tree.o

