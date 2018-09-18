#OBJS specifies which files to compile as part of project
OBJS = startGServer.cpp 


#CC specifies which compiler we're using 
CC = g++

#compiler_flags SPECIFIES the additional compilation options
COMPILER_FLAGS = -I. -w -std=c++11

#linker flags
LINKER_FLAGS =  -lboost_system -lboost_chrono -lpthread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lboost_timer -lrt


#OBJ_NAME specifies the name of our executable
OBJ_NAME = GServer

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

