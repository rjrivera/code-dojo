#OBJS specifies which files to compile as part of project
OBJS = Main.c print.c 


#CC specifies which compiler we're using 
CC = gcc

#compiler_flags SPECIFIES the additional compilation options
COMPILER_FLAGS = -I. -w

#linker flags
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our executable
OBJ_NAME = ex4


all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

