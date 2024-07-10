ZIG = zig

CXXFLAGS = -O2

TARGET_OS ?= native
TARGET_TRIPLE ?= $(shell $(ZIG) targets | jq -r ".native")

INCLUDE_DIR = ""
LIB_DIR = ""

ifeq ($(TARGET_OS), macos)
    TARGET_TRIPLE = x86_64-macos
    INCLUDE_DIR = /Library/Developer/CommandLineTools/usr/include/c++/v1
    LIB_DIR = /Library/Developer/CommandLineTools/usr/lib
endif

ifeq ($(TARGET_OS), linux)
    TARGET_TRIPLE = x86_64-linux-gnu
    INCLUDE_DIR = /usr/include/c++/11
    LIB_DIR = /usr/lib/x86_64-linux-gnu
endif

ifeq ($(TARGET_OS), windows)
    TARGET_TRIPLE = x86_64-windows-gnu
    INCLUDE_DIR = /usr/x86_64-w64-mingw32/include/c++
    LIB_DIR = /usr/x86_64-w64-mingw32/lib
endif

TARGET = LinearAlgebraTest

SOURCES = Matrix.cpp Vector.cpp Test.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(ZIG) cc $(CXXFLAGS) -target $(TARGET_TRIPLE) -o $@ $^ -I$(INCLUDE_DIR) -L$(LIB_DIR) -lc++

%.o: %.cpp
	$(ZIG) cc $(CXXFLAGS) -target $(TARGET_TRIPLE) -c $< -o $@ -I$(INCLUDE_DIR)

clean:
	rm -f $(TARGET) $(OBJECTS)

