#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"



int main(int count, char ** arg) {
	int countString;
	char ** arrayString;
	const char * delimiter = " ";
	char * string = "param1 param2 param3 param4 param5 param6 param7 param8 param9 param10 param11 param12 param13 param14 param15 param16";
	arrayString = split(string,delimiter,&countString);
	
	for(int i = 0; i < countString; i++) {
		printf ("%i: %s\n",i, arrayString[i]);
	}

	initTestVal(10);
	printf("testVal = %i\n",testVal);
	
	freeArrayString(arrayString,countString);

	return 0;
}
