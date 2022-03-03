CC = g++

CXXFLAGS = -g -std=c++14

OBJS = main.o PCB.o

TARGET = Kim1338

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

clean:
	rm -f $(OBJS) $(TARGET) core
