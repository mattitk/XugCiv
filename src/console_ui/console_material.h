#ifndef __CONSOLE_MATERIAL_H__
#define __CONSOLE_MATERIAL_H__

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

#include <vector>
#include <string>

#include "../globals/structs.h"

class ConsoleMaterial
{
	protected:
	int type;
	public:
	std::string name;
	char *textureString;
	void SetType(int type);
	std::vector<PropertyStruct *> properties;
	ConsoleMaterial();
	ConsoleMaterial(std::string filename);
	~ConsoleMaterial()
	{
		if(textureString)free(textureString);
	}
	int Load(std::string filename);
	void ListProperties();
};

#endif
