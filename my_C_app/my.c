#include <stdio.h>

int main() 
{
	FILE *fptr;
	fptr = fopen("/home/usmansikander/Desktop/my_C_app/textfile.text", "w"); // "w" defines "writing mode"
	/* write to file */
	fprintf(fptr, "I am working on lab 04 \n");
	fclose(fptr);
	return 0;
}

