# $@ - ��� ������� ����
# $^ - ������ ����������� � ������� ������

# gcc
# -g - �������� ���������� ������
# -Wall - ����������� ��������������
# -Wno-write-strings ������� �������������� �����


CC=mips-openwrt-linux-gcc
#CC=gcc
CCFLAGS=-Wall -Wno-write-strings
CLEAN=rm -f
PROGRAM_NAME=main
SOURCE_FILES=main.cpp
OBJECTS=sources/main.o
SOURCES=sources
LIB= -lcommon
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
		