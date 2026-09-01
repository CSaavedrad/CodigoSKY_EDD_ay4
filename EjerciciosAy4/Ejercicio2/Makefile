CXX = g++-16
TARGET = receta

all:
	$(CXX) main.cpp tPasos.cpp tReceta.cpp -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) nueva_receta.txt
