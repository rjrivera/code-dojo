#OBJS specifies which files to compile as part of the project
OBJS = Random1.cpp SimpleMCMain1.cpp

#CC specifies which compiler we're using 
CC = g++

#compiler_flags SPECIFIES the additional compilation options we-re using
# -w suppresses all warnings
COMPILER_FLAGS = -I. -w

#linker_flags SPECIFIES the libraries we're linking against
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our executable
OBJ_NAME = SimpleMCMain1

#this is the target that compiles our executable
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
