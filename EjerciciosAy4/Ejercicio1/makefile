CXX = g++-16
TARGET = chile

all:
	$(CXX) main.cpp tChile.cpp tRegion.cpp -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)