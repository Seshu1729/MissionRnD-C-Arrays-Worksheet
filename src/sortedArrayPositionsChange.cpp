/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

int getIndexOfSecondSelectedNumber(int *Arr, int len)
{
	int index = len;
	while (index--)
	{
		if (Arr[index] < Arr[index - 1])
			return index;
	}
	return -1;
}

int getIndexOfFirstSelectedNumber(int *Arr, int len, int number)
{
	int start = 0, end = len, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (Arr[mid]>number && (Arr[mid - 1] <= number || mid == 0))
			break;
		else if (Arr[mid]<number)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return mid;
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int index1, index2;
	if (Arr != NULL)
	{
		if (len > 0)
		{
			index1 = getIndexOfSecondSelectedNumber(Arr, len);
			if (index1 != -1)
			{
				index2 = getIndexOfFirstSelectedNumber(Arr, index1, Arr[index1]);
				swap(&Arr[index1], &Arr[index2]);
			}
		}
		else
			Arr = NULL;
	}
	return NULL;
}