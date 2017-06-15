#OBJS specifies which files to compile as part of the project
OBJS = prender.c

#CC specifies which compiler we're using
CC = gcc

#compiler_flags SPECIFIES the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c11

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL -lm

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = ex1

#this is the target that compiles our exectuable
all : $(OBJS)
	    $(CC)  $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


