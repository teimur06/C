/*
	Header file common.cpp

*/



int testVal;

// Отчищает массив строк
void freeArrayString(char**arrayString, int countString);

// Функция принимает себе указатель на строку, разделитель и возвращает массив строк
// string - строка которую нужно разделить
// delimiter - разделитель
// countString - возвращает колличество строк в массиве
char** split(char * string, const char * delimiter, int * countString);


void initTestVal(int val);


int min(int a, int b);
int max(int a, int b);