INCLUDE=-I./
CFLAGS=-std=c++2a
FLAGS=$(INCLUDE) $(CFLAGS)
LINKS=-pthread  -lstdc++
ifndef (TARGET)
	TARGET=thread	
endif
SRC=utils.o  computations.o
LIB=libcmp.a

all:$(TARGET)

$(SRC): %.o : %.cpp
	gcc -c $^ $(FLAGS) -o $(@)

$(LIB):$(SRC)
	ld -r $(^) -o $@	

$(TARGET): $(LIB)
	echo $(@)
	gcc   $@.cpp $(FLAGS) $(LINKS)  $^ -o $@ 

clean:
	rm -rf $(SRC) $(TARGET)  $(LIB)

