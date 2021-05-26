#include "Array.h"
#include "Set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  _POSIX_C_SOURCE 200809L
#define  _GNU_SOURCE

/*
Shai Dahan - 209462712
Sarel Alush - 316373851
*/

Element cpy_str(Element e) {
  if (!e) {
    return NULL;
  }
  Element new_st = strdup((char *)e);
  if (!new_st) {
    fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n", __FILE__,
            __LINE__, sizeof(char *));
    exit(-1);
  }
  return new_st;
}

bool cmp_string(Element e1,Element e2){
  if(e1 == NULL || e2 == NULL){
    return false;
  }
  return strcmp((char*)e1,(char*)e2) == 0;
}



int main(int argc, char **argv) {

  if (argc != 4) {
    fprintf(stderr, "\n Usage: %s <date-file>\n\n", argv[0]);
    return 1;
  }
  
  
  Array ar;
  ar = ArrayCreate(cpy_str, free, 20);
  Set st;
  st = SetCreate(cpy_str,free,cmp_string);

  unsigned int day, month, year, i = 0;
  char *line_buf = NULL , check;
  size_t line_buf_size = 0;
  FILE *f;
  f = fopen(argv[1], "r");
  FILE *fWrite;
  fWrite = fopen(argv[3],"w");
  if (!f) {
    fprintf(stderr, "Error! opeing file %s", argv[1]);
    exit(1);
  }


  while (getline(&line_buf, &line_buf_size, f) != EOF) {
    if (sscanf(line_buf, "%d/%d/%d %c", &day, &month, &year, &check ) == 3) {

      ArrayPut(ar, line_buf, i);
      SetAdd(st,line_buf);  
      
      //printf("Day: %d \t month : %d \t year : %d\n",day,month,year);
      
      //printf("%s\n\n", (char *)ArrayGet(ar, i));
      i++;
    }
  }
  Element e = ArrayGet(ar, 0);
  fprintf(fWrite,"-------Array:---------\n");
  for(int j=1;(j<=ArraySize(ar) && e!=NULL);j++){
    fprintf(fWrite,"%s",e);
    e = ArrayGet(ar, j);
  }
  
  fprintf(fWrite,"-------Set:---------\n");
  char* es = SetFirst(st);
  while(!SetIsEmpty(st) && es != NULL){
    fprintf(fWrite,"%s",es);
    es = SetNext(st);
  }


  
  fclose(f);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  ArrayDestroy(ar);
  return 0;
}