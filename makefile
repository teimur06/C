# $@ - Имя текущей цели
# $^ - Список зависимотей в текущей связке

# gcc
# -g - Добавить отладочные данные
# -Wall - показывапть предупреждения
# -Wno-write-strings удаляет предупреждения строк


#CC=mips-openwrt-linux-gcc
CC=g++
CCFLAGS=-Wall -Wno-write-strings -std=c++11
CLEAN=rm -f
PROGRAM_NAME=main
SOURCE_FILES=main.cpp
OBJECTS=sources/main.o
SOURCES=sources
LIB= -lcommon -lgraphic
WL=-Wl,-rpath,lib
LIBPATH=-L lib
export

$(PROGRAM_NAME): make-main $(OBJECTS)
	@echo create programm $(PROGRAM_NAME)
	$(CC) $(CCFLAGS) $(WL) -o $@ $(OBJECTS) $(LIBPATH)  $(LIB)
	#$(CC) $(CCFLAGS) -o $@ $(OBJECTS) $(LIBPATH) $(LIB) 

make-main:
	$(MAKE)  -C $(SOURCES)  
	
clean: 
		$(CLEAN) *.o
		$(CLEAN) $(PROGRAM_NAME)
		$(MAKE) -C $(SOURCES) clean
		