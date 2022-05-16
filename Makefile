INCLUDE=-I./
CFLAGS=-std=c++2a
FLAGS=$(INCLUDE) $(CFLAGS)
LINKS=-pthread  -lstdc++
ifndef (TARGET)
	TARGET=thread	
endif
SRC=utils.o  computations.o
LIB=libcmp.a
C=clang++

all:$(TARGET)

$(SRC): %.o : %.cpp
	$C -c $^ $(FLAGS) -o $(@)

$(LIB):$(SRC)
	ld -r $(^) -o $@	

$(TARGET): $(LIB)
	echo $(@)
	$C   $@.cpp $(FLAGS) $(LINKS)  $^ -o $@ 

clean:
	rm -rf $(SRC) $(TARGET)  $(LIB)

