#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <vector>
#include <string>

#include "../globals/structs.h"
#include "../globals/parser.h"

void LoadMainConfig()
{
  std::vector<PropertyStruct *> values; // = new std::vector<PropertyStruct *>();
  if(LoadConfig("config.cfg", &values))
  {
    printf("Loading config failed. Going for defaults.\n");
  }
  for(unsigned int j=0;j<values.size();++j)
  {
    switch(values[j]->type)
    {
      case 's':
        printf("%s = \"%s\"\n", values[j]->key, values[j]->value);
        break;
      case 'i':
        printf("%s = %ld\n", values[j]->key, values[j]->numerical_value);
        break;
      case 'f':
        printf("%s = %f\n", values[j]->key, values[j]->floating_value);
    }
  }
  printf("\nConfig loaded.\n");

}
#endif
