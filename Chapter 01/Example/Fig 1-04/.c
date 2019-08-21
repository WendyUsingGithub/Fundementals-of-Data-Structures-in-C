#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 101
#define SWAP(x,y,t) (t=x) , (x=y) , (y=t)

void sort(int[], int);

int main()
{
	int i, n;
	int list[MAX_SIZE] = { 0 };
	
	srand(time(NULL));

	printf("Enter the number of numbers to generate :　");
	scanf_s("%d", &n);

	if (n<1 || n>MAX_SIZE)
	{
		fprintf(stderr, "Inproper value of n\n");
		exit(EXIT_FAILURE);
	}

	// generate numbers randomly
	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 1000;
		printf("%5d ", list[i]);
		
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}

	sort(list, n);
	printf("\nSorted array :\n");

	for (i = 0; i < n; i++)
	{
		printf("%5d ", list[i]);

		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}

void sort(int list[], int n)
{
	int i = 0;
	int j = 0;
	int min = 0;
	int temp = 0;

	for (i = 0; i < n - 1; i++)
	{
		min = i;

		// find min member in the unsorted part of the array
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[min])
			{
				min = j;
			}
		}
		SWAP(list[i], list[min], temp);
	}
}
