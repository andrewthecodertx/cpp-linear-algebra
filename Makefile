CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = LinearAlgebraTest
SOURCES = Matrix.cpp Vector.cpp Test.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)
