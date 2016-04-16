# $@ - Имя текущей цели
# $^ - Список зависимотей в текущей связке

#CC=mips-openwrt-linux-gcc
CC=gcc
CCFLAGS=-Wall -g -Wno-write-strings
CLEAN=rm -f
PROGRAM_NAME=main
SOURCE_FILES=main.cpp
OBJECTS=sources/main.o
SOURCES=sources
LIB= -lcommon
LIBPATH=-L lib
export

$(PROGRAM_NAME): make-main $(OBJECTS)
	#$(CC) $(CCFLAGS) -o $@ $(OBJECTS) $(LIBPATH) $(LIB) -Wl,-rpath,lib
	$(CC) $(CCFLAGS) -o $@ $(OBJECTS) $(LIBPATH) $(LIB) 

make-main:
	$(MAKE)  -C $(SOURCES)  
	
clean: 
		$(CLEAN) *.o
		$(CLEAN) $(PROGRAM_NAME)
		$(MAKE) -C $(SOURCES) clean
		