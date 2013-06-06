/*
 *	17 - dynamictable.c
 */


#include <stdlib.h>
#include <stdio.h>

#pragma mark Datastructures
typedef struct DYNAMIC_TABLE {
	int size, num;
	int * table;
} Table;


#pragma mark Helper Functions
void printTable(Table T)
{
	if (T.size == 0)
	{
		printf("New table.\n");
		return;
	}
	else
	{
		printf("Table of size %i", T.size);
		
		if (T.num != 0)
			printf(" and %i elements\n[", T.num);
		else
		{
			printf(" and no elements.\n");
			return;
		}
	}
		
	for (int i = 0; i < T.size; i++)
	{
		if (i > 0)
			printf(", ");
		
		if (i < T.num)
			printf("%i", T.table[i]);
		else
			printf("nil");
	}
	printf("]\n");
}


#pragma mark 
void tableInsert(Table * T, int x)
{
	Table t = (* T);

	if (t.size == 0) {
		t.table = (int *)malloc(sizeof(int) * 1);
		t.size = 1;
	}
	
	if (t.num == t.size) {
		int * tmp = (int *)malloc(sizeof(int) * (2 * t.size));
		for (int i = 0; i < t.size; i++)
			tmp[i] = t.table[i];
		free(t.table);
		t.table = tmp;
		t.size *= 2;
	}
	
	t.table[t.num++] = x;
	(* T) = t;
}

/*
#pragma mark Main Program
int main(int argc, const char * argv[])
{
	Table T = {.size=0, .num=0, .table=0};
	printTable(T);
	
	for (int i = 0; i < 48; i++)
		tableInsert(&T, i * 2);
	
	printTable(T);
	free(T.table);
		
	return 0;
}
*/
