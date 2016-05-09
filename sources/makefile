# $@ - имЯ текущей цели
# $^ - список зависимотей в текущей связке


INCLUDE=-I ../include 
#LIBPATH=-L ../lib
SOURCE_FILES=libcommon.cpp libgraphic.cpp
OBJECTS=libcommon.o libgraphic.o
HOME_LIBPATH=../lib
main.o: main.cpp libs
	$(CC) $(CCFLAGS)  $(INCLUDE) -c $< $(LIBPATH) $(LIB)
	
	
libs: $(OBJECTS)
	@echo create libs files
	#ar rv ../lib/libcommon.a $(OBJECTS) 
	mkdir -p $(HOME_LIBPATH)
	$(CC) -shared $(WL) -o $(HOME_LIBPATH)/libcommon.so libcommon.o -lm
	$(CC) -shared $(WL) -o $(HOME_LIBPATH)/libgraphic.so libgraphic.o -L $(HOME_LIBPATH) -lm  -lcommon
	#$(CLEAN) $(HOME_LIBPATH)/libcommon.so
	#$(CLEAN) $(HOME_LIBPATH)/libcommon.so.1
	#ln -s $(HOME_LIBPATH)/libcommon.so.1.0 $(HOME_LIBPATH)/libcommon.so.1
	#ln -s $(HOME_LIBPATH)/libcommon.so.1.0 $(HOME_LIBPATH)/libcommon.so
	#cp  $(HOME_LIBPATH)/libcommon.so.1.0 ../lib/libcommon.so.1.0
	
$(OBJECTS): $(SOURCE_FILES)
	@echo create $(OBJECTS) files
	$(CC) $(CCFLAGS) -fPIC  $(INCLUDE) -c $(SOURCE_FILES) -L $(HOME_LIBPATH)
	#$(CC) $(CCFLAGS)  $(INCLUDE) -c $(SOURCE_FILES) $(LIBPATH)
	
clean: 
		$(CLEAN) *.o
		$(CLEAN) ../lib/*.a
		$(CLEAN) ../lib/*.so*