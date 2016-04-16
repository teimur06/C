# $@ - Имя текущей цели
# $^ - Список зависимотей в текущей связке

INCLUDE=-I ../include 
LIBPATH=-L ../lib
SOURCE_FILES=common.cpp
OBJECTS=common.o 

main.o: main.cpp libs
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< $(LIBPATH) $(LIB)
	
	
libs: $(OBJECTS)
	ar rv ../lib/libcommon.a $(OBJECTS) 
	#$(CC) -shared -o ../lib/libenv.so $(OBJECTS)  -lm
	
$(OBJECTS): $(SOURCE_FILES)
	#$(CC) $(CCFLAGS) -fPIC  $(INCLUDE) -c $(SOURCE_FILES) $(LIBPATH)
	$(CC) $(CCFLAGS)  $(INCLUDE) -c $(SOURCE_FILES) $(LIBPATH)
	
clean: 
		$(CLEAN) *.o
		$(CLEAN) ../lib/*.a
		$(CLEAN) ../lib/*.so