CC := g++
FLAGS := -Iinclude
TARGET := bin/trabalhocg
LIBS := -lGL -lglfw -lm

SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, bin/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS) | bin
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)

bin/%.o: src/%.cpp | bin
	$(CC) $(FLAGS) -c $< -o $@ $(LIBS) 

bin:
	mkdir -p bin

clean:
	rm -rf bin

run: clean $(TARGET)
	./$(TARGET) ./map/arena_teste.svg

.PHONY: all clean run
