#ifndef __XUGFILE_H__
#define __XUGFILE_H__



typedef struct
{
	unsigned long int handle;
	unsigned long int segment_count;
	unsigned long int segment_size;
	unsigned long int segment_in_cache;
	char flags;
	
	int error_flags;
	int name_length;
	char *name;
	char *path;
	char **buffer;
}XugFile;

XugFile *XugFileInit();

/*
	XugFileCreate(path, name)
		XugFileInitNew
		XugFileSetName
		XugFileSetPath
		XugFileTouch
	XugFileLoad(path, name)
		XugFileInitNew
		XugFileLoad
*/

/*
XugFile *XugFileInitNew()
{
	XugFile x;
	x->segment_count=0;
	x->segment_size=0;
	x->file_in_buffer=0;
	x->error_flags=0;
	x->name_length=0;
	x->buffer=0;
	return x;
}

void XugFileRelease(XugFile *XugFile)
{
	if(file_in_buffer && buffer)
	{
		free(**buffer);
		file_in_buffer=0;
	}
	else
	{
		XugFile->error_flags = 
			XugFile->error_flags ^ XUGFILE_ERROR_MEMORY_LEAK;
	}
	


}
*/

#endif
