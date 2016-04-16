#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"



int main(int count, char ** arg) {
	int countString;
	char ** arrayString;
	const char * delimiter = " ";
	arrayString = split("param1 param2 param3 param4 param5 param6 param7 param8 param9 param10 param11 param12 param13 param14 param15 param16",delimiter,&countString);
	
	for(int i = 0; i < countString; i++) {
		printf ("%i: %s\n",i, arrayString[i]);
	}

	freeArrayString(arrayString,countString);

	return 0;
}
