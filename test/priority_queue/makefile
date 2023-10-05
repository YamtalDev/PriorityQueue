# The compiler : gcc for C program :
CC = gcc

# Compiler flags :
CFLAGS = -ansi -pedantic-errors -Wall -Wextra

# Valgrind
VALGRIND = valgrind --leak-check=yes --track-origins=yes

# Debug
DEBUG = gdb -tui

#Remove
RM = rm -rf

# Archive
AR = ar -rcs

# Source file
SRC = ../../src/priority_queue.c

# External dependency object
EXTERNAL_O_SRC = ../../bin/objects/sorted_list.o

# External dependency src
EXTERNAL_SRC = ../../src/sorted_list.c

# External header sorted list
EXTERNAL_HEADER = ../../include/sorted_list.h

# External dependency src
EXTERNAL_O_SRC_2 = ../../bin/objects/dll.o

# External dependency object
EXTERNAL_SRC_2 = ../../src/dll.c

# External header dll
EXTERNAL_HEADER_2 = ../../include/dll.h

# Source object file
O_SRC = ../../bin/objects/priority_queue.o

# Header file
HEADER = ../../include/priority_queue.h

# Path to header
PATH_TO_HEADER = -I../../include/

# Main file
MAIN = ../../test/priority_queue/priority_queue_test.c

# Main file
O_MAIN = ../../bin/objects/priority_queue_test.o

# The build target executable
TARGET = ../../bin/executables/priority_queue

# Static Lib names
S_LIB = ../../bin/static_libs/libpriority_queue.a

# Shared Lib names
SO_NAME = ../../bin/shared_libs/libpriority_queue.so

# Shared lib path
PATH_TO_SO = -L../../bin/shared_libs

# Static lib path
PATH_TO_S = -L../../bin/static_libs

# Files of the project
C_FILES = $(MAIN) $(SRC) $(EXTERNAL_SRC_2)  $(EXTERNAL_SRC)

# Files of the project
O_FILES = $(O_MAIN) $(O_SRC) $(EXTERNAL_O_SRC)  $(EXTERNAL_O_SRC_2)

.PHONY : run vlg release debug lib.a lib.so link_shared link_static clean

#******************************************************************************

$(TARGET) : $(O_FILES) $(HEADER)
	clear
	$(CC) $(CFLAGS) $(O_FILES) -o $(TARGET)

#******************************************************************************

$(O_MAIN) : $(MAIN) $(HEADER)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) -c $(MAIN) -o $(O_MAIN)

$(O_SRC) : $(SRC) $(HEADER)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) -c $(SRC) -o $(O_SRC)

$(EXTERNAL_O_SRC) : $(EXTERNAL_SRC) $(EXTERNAL_HEADER)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) -c $(EXTERNAL_SRC) -o $(EXTERNAL_O_SRC)

$(EXTERNAL_O_SRC_2) : $(EXTERNAL_SRC_2) $(EXTERNAL_HEADER_2)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) -c $(EXTERNAL_SRC_2) -o $(EXTERNAL_O_SRC_2)

#******************************************************************************

run : $(TARGET)
	clear
	$(TARGET)

#******************************************************************************

vlg : $(TARGET)
	clear
	$(VALGRIND) $(TARGET)


#******************************************************************************

link_static : lib.a $(O_FILES)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) $(MAIN) $(PATH_TO_S) -lpriority_queue -o $(TARGET)_lstatic
	clear

#******************************************************************************

lib.a : $(O_FILES)
	$(AR) $(S_LIB) $(O_SRC)
	ranlib $(S_LIB)
	clear

#******************************************************************************

link_shared : lib.so
	$(CC) $(PATH_TO_HEADER) $(PATH_TO_SO) -Wl,-rpath=$(PATH_TO_SO) -Wall $(MAIN) -lpriority_queue -o $(TARGET)_lshared
	clear

#******************************************************************************

lib.so : CFLAGS += -fPIC -c
lib.so : 
	$(RM) $(TARGET) $(O_SRC)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) -c $(SRC) -o $(O_SRC)
	$(CC) -shared -o $(SO_NAME) $(O_SRC)
	clear

#******************************************************************************

debug : CFLAGS += -DDEBUG_ON -g
debug : $(TARGET)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) $(C_FILES) -o $(TARGET)
	$(DEBUG) $(TARGET)
	clear

#******************************************************************************

release : CFLAGS += -DNDEBUG -O3
release : $(TARGET)
	$(CC) $(PATH_TO_HEADER) $(CFLAGS) $(C_FILES) -o $(TARGET)
	clear

#******************************************************************************

clean :
	clear
	$(RM) $(TARGET) $(O_FILES) $(SO_NAME) $(S_LIB)


#******************************************************************************
