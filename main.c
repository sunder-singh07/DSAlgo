#include <stdio.h>
#include "./lib/array.h"

int main(int argc, char **argv)
{
    printf("Sunder Singh\n");

    // create array
    Array *pArr = NULL;
    Create(&pArr);
    short ch = 0;
    int el,idx;

    // do processing with user inputs
    do
    {
        printf("\n\nMenu\n");
        printf("1. Display \n");
        printf("2. Append \n");
        printf("3. Insert \n");
	printf("4. Exit \n");
	printf("Enter your choice :");
	scanf("%hd", &ch);

	switch(ch)
	{
	    case 1: 
	        Display(pArr);
		break;
	    case 2:
		printf("Enter element to append :");
		scanf("%d", &el);
		Append(pArr, el);
		break;
	    case 3:
		printf("Enter element and index : ");
		scanf("%d%d", &el, &idx);
		Insert(pArr, idx, el);
		break;
	    default:
		printf("Exiting...\n");
	}
    } while(ch < 4);

    // destroy the array
    Destroy(&pArr);

    return 0;
}
