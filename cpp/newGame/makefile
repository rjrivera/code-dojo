#OBJS specifies which files to compile as part of project
OBJS = game.cpp


#CC specifies which compiler we're using 
CC = g++

#compiler_flags SPECIFIES the additional compilation options
COMPILER_FLAGS = -I. -w -std=c++11

#linker flags
LINKER_FLAGS =  -lboost_system -lpthread -lsfml-graphics -lsfml-window -lsfml-system


#OBJ_NAME specifies the name of our executable
OBJ_NAME = ex1

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

