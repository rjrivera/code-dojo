#OBJS specifies which files to compile as part of project
OBJS = 2-3-3.cpp Point.cpp

#CC specifies which compiler we're using 
CC = g++

#compiler_flags SPECIFIES the additional compilation options
COMPILER_FLAGS = -I. -w -std=c++11

#linker flags
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our executable
OBJ_NAME = ex3


all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

