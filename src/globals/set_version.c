#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define COULD_NOT_CREATE_A_FILE fprintf(stderr, "Could not create a file.\n");


int main(int argc, char **argv)
{
	char buf[256];
	FILE *f=fopen(argv[1], "r");
	
	long int filesize=0;
	int version=0;
	memset(&buf, 0, 255);
	if(f)
	{
		fseek(f, 0 , SEEK_END);
		filesize = ftell(f);
		rewind(f);
		fread(&buf, 1, filesize, f);
		fclose(f);
	}
	f=fopen(argv[1],"w");
	if(!f)
	{
		COULD_NOT_CREATE_A_FILE
		return 1;
	}
	for(int i=2;i<argc-1;++i)
	{

		fprintf(f, "%d.", atoi(argv[i]));
	}
	fprintf(f,"%s", argv[argc-1]);
	fclose(f);
	return 0;
}
