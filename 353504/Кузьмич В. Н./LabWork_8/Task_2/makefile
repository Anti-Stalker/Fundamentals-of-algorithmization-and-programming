CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -fPIC

SRCS = ArrayHeap.h;
OBJS = $(SRCS:.cpp=.o)
LIBNAME = libbinary_heap.so

all: $(LIBNAME)

$(LIBNAME): $(OBJS)
    $(CXX) -shared -o $(LIBNAME) $(OBJS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(LIBNAME)

.PHONY: all clean
