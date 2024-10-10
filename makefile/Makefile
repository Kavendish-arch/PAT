## 
# hello: ma

## version 2
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)

# main.o: main.cpp
# 	$(CXX) -c main.cpp

# printhello.o: printhello.cpp
# 	$(CXX) -c printhello.cpp

# factorial.o: factorial.cpp
# 	$(CXX) -c factorial.cpp


## version 3
CXX = g++
TARGET = hello
OBJ = main.o printhello.o factorial.o
CXXFLAGSS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^


%.o: %.cpp	
	$(CXX) $(CXXFLAGSS) $< -o $@


# .phony: clean
clean:
	rm -f *.o $(TARGET)

