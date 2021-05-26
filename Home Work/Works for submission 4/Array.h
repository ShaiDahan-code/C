#ifndef ARRAY_H
#define ARRAY_H
#include <stdbool.h>
#define MAX_ARRAY_SIZE 1000000

/*
Shai Dahan - 209462712
Sarel Alush - 316373851
*/

typedef void* Element;
typedef struct Array* Array;



Array              ArrayCreate(Element (*cpy) (Element),
                                void (*fre) (Element),
                                unsigned int size);

void              ArrayDestroy(Array);
unsigned int      ArraySize(Array);
void              ArrayResize(Array, unsigned int);
void              ArrayPut(Array,Element,unsigned int index);
Element           ArrayGet(Array,unsigned int index);

#endif