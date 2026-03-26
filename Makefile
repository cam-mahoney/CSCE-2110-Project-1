CXX = g++
CXXFLAGS = -Wall -std=c++11

SOURCES = main.cpp Driver.cpp DriverDatabase.cpp Ticket.cpp LinkedList.cpp HashTable.cpp Node.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = driver_system

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
