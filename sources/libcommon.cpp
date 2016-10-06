#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// lib


int min(int a, int b)
{
	if (a == b) return a;
	if (a < b) return a; else return b;
}

int max(int a, int b)
{
	if (a == b) return a;
	if (a > b) return a; else return b;
}

// Отчищает массив строк
void freeArrayString(char**arrayString, int countString)
{
	for(int i = 0; i < countString; i++) 
		free(arrayString[i]);
	free(arrayString);
}



char ** addMallocArrayString(char ** arrayString, int * count_malloc) {
	int _count_malloc, count;
	char ** tempArrayString; 
	
	
	count = _count_malloc = *count_malloc;
	_count_malloc  = _count_malloc *   2 ;
	tempArrayString = arrayString;
	arrayString = (char**)malloc(_count_malloc* sizeof(char**));
	for(int i = 0; i < count; i++) arrayString[i] = tempArrayString[i];
	free(tempArrayString);
	*count_malloc = _count_malloc;
	return arrayString;
}


// Функция принимает себе указатель на строку, разделитель и возвращает массив строк
// string - строка которую нужно разделить
// delimiter - разделитель
// countString - возвращает колличество строк в массиве
char** split(char * string, const char * delimiter, int * countString)
{
    char *token, *last;
	char ** arrayString;    // Массив строк, возвращаемый в конце функции
	char * str; 			// переменная нужна для создания копии строки для разделения в куче
	int count;				// Текущее количества строк в массиве 
	int count_malloc;		// Это для примера, задает размер arrayString ( в будущем будет оп другому )
	
	count = 0;
	count_malloc = 5;
	arrayString = (char**)malloc(count_malloc*sizeof(char**)); // выделяем память для массива строк
	str = (char*)malloc(strlen(string)+1); 		// Выделяем память для копии строки
	strcpy(str,string);							// создаем копию строки в куче
	
	// Начинается разделение
    token = strtok_r(str, delimiter, &last);
    while (token != NULL) {
		if (count >= count_malloc)
			arrayString = addMallocArrayString(arrayString,&count_malloc);
		arrayString[count] = (char*) malloc(strlen(token)+1); // Выделяется память для текущего токена
		strcpy( arrayString[count] ,token);					  // копируем токкен в массив
        token = strtok_r(NULL, delimiter, &last);
		count++;
    }
	
	free(str); 
	
	*countString = count;
	return arrayString;
}


void initTestVal(int val) {
	testVal = val;
}


