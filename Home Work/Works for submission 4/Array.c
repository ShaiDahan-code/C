#include "Array.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
/*
Shai Dahan - 209462712
Sarel Alush - 316373851
*/
struct Array {
  LinkedList ls;
};
//***************************************************************************************//
Array ArrayCreate(Element (*cpy)(Element), void (*fre)(Element),
                  unsigned int size) {
  int i;
  Array my_array = (Array)malloc(sizeof(struct Array));
  if (!my_array) {
    fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__,
            __LINE__, sizeof(struct Array));
    exit(-1);
  }
  my_array->ls = LLCreate(cpy, fre);
  if (size > MAX_ARRAY_SIZE) {
    fprintf(stderr,
            "%s/%u : U ask %d Size but you can only get maxium of %d\n\n",
            __FILE__, __LINE__, size, MAX_ARRAY_SIZE);
    exit(-1);
  }
  for (i = 0; i < size; i++) {
    LLAdd(my_array->ls, i, NULL);
  }

  return my_array;
}
//********************************************************************************************************************//
void ArrayDestroy(Array a1) { LLDestroy(a1->ls); }
//********************************************************************************************************************//
unsigned int ArraySize(Array a1) { return LLSize(a1->ls); }
//********************************************************************************************************************//
void ArrayResize(Array a1, unsigned int size) {
  unsigned int my_array_size = ArraySize(a1);
  int i;
  if (my_array_size > size) {
    for (i = my_array_size; i > size; i--) {
      LLRemove(a1->ls, i);
    }
  }

  else if (my_array_size < size) {
    for (i = my_array_size; i <= size; i++) {
      LLAdd(a1->ls, i, NULL);
    }
  }
}
//********************************************************************************************************************//
void ArrayPut(Array a1, Element e1, unsigned int index) {
  if (index > MAX_ARRAY_SIZE) {
    fprintf(stderr,
            "%s/%u : U ask %d Size but you can only get maxium of %d\n\n",
            __FILE__, __LINE__, index, MAX_ARRAY_SIZE);
    exit(-1);
  }

  else if (index > ArraySize(a1)) {
    ArrayResize(a1, index);
  }
  LLRemove(a1->ls, index);
  LLAdd(a1->ls, index, e1);

}
//********************************************************************************************************************//
Element ArrayGet(Array a1, unsigned int index) {
  Element e1 = LLRemove(a1->ls, index);
  LLAdd(a1->ls, index, e1);
  return e1;
}
//***************************************************************************************//
