/****************IMPORTANT*******************
**ONLY TO USE AT THE BEGINNING OF A READING**
********************************************/
#include <iostream>
#include <stdio.h>

int fSize (FILE *fil)
{
	unsigned int a = 0;
	fseek(fil,0,SEEK_END);
	a = ftell(fil);
	fseek(fil,0,SEEK_SET);
	return a;
}