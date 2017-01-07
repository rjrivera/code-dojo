#OBJS specifies which files to compile as part of the project
OBJS = Random1.cpp SimpleMCMain2.cpp PayOff1.cpp SimpleMC.cpp

#CC specifies which compiler we're using 
CC = g++

#compiler_flags SPECIFIES the additional compilation options we-re using
# -w suppresses all warnings
COMPILER_FLAGS = -I. -w -std=c++11

#linker_flags SPECIFIES the libraries we're linking against
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our executable
OBJ_NAME = SimpMC2

#this is the target that compiles our executable
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
