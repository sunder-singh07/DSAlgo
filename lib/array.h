#ifndef array

#define array

#include <stdio.h>

typedef struct _Array Array;

void Create(Array **p);
void Destroy(Array **p);
void Display(Array *p);
void Append(Array *p, int data);
void Insert(Array *p, int index, int data);

#endif

