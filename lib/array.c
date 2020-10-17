#include "array.h"
#include <stdlib.h>

struct _Array
{
        int* arr;
        int size;
        int length;
};

void CreateArray(Array *p)
{
    p->arr = (int*)malloc(p->size*sizeof(int));
}

void Create(Array **pp)
{
    Array *p = (Array*)malloc(sizeof(Array));
    *pp = p;
    printf("\nEnter number of elemens:\n");
    scanf("%d", &p->length);
    int size = p->length;
    int temp = size%8;
    size += 8-temp;
    p->size = size;
    CreateArray(p);
    printf("\nEnter the array elements:\n");
    for(int i=0; i < p->length; i++)
    {
        printf("Array element: %d = ", i);
	scanf("%d", &p->arr[i]);
    }
}

void Destroy(Array **pp)
{
    Array *p = *pp;
    free(p->arr);
    p->arr = NULL;
    p->length = 0;
    p->size = 0;
    free(p);
}

void Display(Array *p)
{
    printf("\nArray size = %d, Array length = %d\n", p->size, p->length);	
    printf("Array elements :\n");
    for(int i=0; i<p->length; i++)
        printf("%d ", p->arr[i]);
    printf("\n\n");
}

void AdjustSize(Array *p)
{
    if(p->length >=  p->size)
    {
        int *temp = p->arr;
        p->size *= 2;
        CreateArray(p);
        for(int i=0; i < p->length; i++)
        {
            p->arr[i] = temp[i];
        }
        free(temp);
    }
}


void Append(Array *p, int data)
{
    AdjustSize(p);
    p->arr[p->length++] = data;
}

void Insert(Array *p, int index, int data)
{
    if(index >= 0 && index <= p->length)
    {
        AdjustSize(p);
	for(int i = p->length; i > index; i--)
	{
	    p->arr[i] = p->arr[i-1];
	}
	p->arr[index] = data;
	p->length++;
    }
}


