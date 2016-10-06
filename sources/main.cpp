#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <mntent.h>
#include<sys/statvfs.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "common.h"
#include "graphic.h"


using namespace std;

void print_split(char * string, const char * delimiter) {
	int countString;
	char ** arrayString;
	arrayString = split(string,delimiter,&countString);
	
	for(int i = 0; i < countString; i++) {
		printf ("%i: %s\n",i, arrayString[i]);
	}
	freeArrayString(arrayString,countString);
}


class A{
public:
    A(){
        printf("OOO YES!");
    }
    /** Zad is method class A
     */
    void zad()
    {
        std::string html = " test sdlkmfsdklfsdkl sddsfds192.168.4.8dsertert";
       
    }
    
};


void paint_hui() {


	 openfb();
	 clearScreen();

	 line(5,5,80,100);
	 line(80,5,5,100);
	 line(100,5,140,50);
	 line(180,5,100,100);
	 line(200,5,200,100);
	 line(280,5,200,100);
	 line(280,5,280,100);
	 line(220,5,250,10);
	 closefb();

	
}

unsigned long long  ME(unsigned long long b, unsigned long long e, unsigned long long m) {
	unsigned long c = 1;
	for (unsigned long long  _e = 1; _e <= e; _e++) {
		c = (c*b) % m; 
	}
	return c;
}

int main(int count, char ** arg) {

	unsigned long long  b,e,m;
        int opt;
	//char * pEnd;
	bool param_exist;
	const char * delimiter = " ";
	char * help_str = 
						"-h       - Print help and exit\n"
						"-p       - print na hui\n"
						"-o <val> - printe testVal\n"
						"-M <b> <e> <m>  - \"b^e mod m\"\n"
                                                "-s       - printe split\n";
	char * string = "param1 param2 param3 param4 param5 param6 param7 param8 param9 param10 param11 param12 param13 param14 param15 param16";
	
	param_exist = false;
	
        A * a =new A;
        a->zad();
        delete a;
        
	while ((opt = getopt (count, arg, "shpo:M")) != -1) {
		param_exist = true;
		switch (opt) {
			case 'h':
				printf(help_str);
				break;
				
			case 'p':
				paint_hui();
				break;

                                
			case 's':
				print_split(string, delimiter);
				break;
                                
			case 'M':
				if ((count-optind) != 3  )
				{
					printf ("-M <b> <e> <m>  - \"b^e mod m\"\n");
					break;
				}	
				b = strtoull (arg[optind],NULL,10);
				e = strtoull (arg[optind+1],NULL,10);
				m = strtoull (arg[optind+2],NULL,10);
				printf("%llu^%llu mod %llu = %llu\n", b,e,m,ME(b,e,m));
				//printf("%llu\n",ME(b,e,m));
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
