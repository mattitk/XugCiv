#ifndef __XUGDIRECTORY_H__
#define __XUGDIRECTORY_H__

#include "xugfile.h"
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct
{
	long int handle;
	long int parent;
	int name_length;
	char *name;
	long int file_count;
	XugFile *files;
}XugDirectory;

XugDirectory *XugDirectoryInit()
{
	XugDirectory *d = (XugDirectory *)malloc(sizeof(XugDirectory));
	return d;
}

int AddFile(XugDirectory *d, XugFile *f)
{
	if(!d || !f) return 0;
	++d->file_count;
	return 1;
}

void XugDirectorySetName(XugDirectory *d, char *newName)
{
	int length=strlen(newName);
	if(d->name)free(d->name);
	d->name=(char *)malloc(sizeof(char)*length);
	memcpy(newName, d->name, length);
} 

void XugDirectoryRelease(XugDirectory *d)
{
	free(d->name);
	free(d->files);
	free(d);
}

#endif
