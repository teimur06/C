#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "common.h"


void print_split(char * string, const char * delimiter) {
	int countString;
	char ** arrayString;
	arrayString = split(string,delimiter,&countString);
	
	for(int i = 0; i < countString; i++) {
		printf ("%i: %s\n",i, arrayString[i]);
	}
	freeArrayString(arrayString,countString);
}

int main(int count, char ** arg) {

	int opt;
	bool param_exist;
	const char * delimiter = " ";
	char * help_str = 
						"-h       - Print help and exit\n"
						"-p       - print na hui\n"
						"-o <val> - printe testVal\n";
	char * string = "param1 param2 param3 param4 param5 param6 param7 param8 param9 param10 param11 param12 param13 param14 param15 param16";
	
	param_exist = false;
	//ss
	while ((opt = getopt (count, arg, "hpo:")) != -1) {
		param_exist = true;
		switch (opt) {
			case 'h':
				printf(help_str);
				break;
				
			case 'p':
				print_split(string, delimiter);
				break;
				
			case 'o':
				initTestVal(atoi(optarg));
				printf("testVal = %i\n",testVal);
				break;				
				
			case '?':
				printf(help_str);
				break;
			
			default:
				
				break;
		}
	}
	
	if (!param_exist)
		printf(help_str);
	return 0;
}
