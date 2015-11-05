/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/
#include<stdlib.h>

int getIndex(int *Arr, int len, int number)
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

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int indexAt;
	if (Arr != NULL)
	{
		if (len>0)
		{
			indexAt = getIndex(Arr, len, num);
			Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
			while (len != indexAt)
			{
				Arr[len] = Arr[len - 1];
				len--;
			}
			Arr[indexAt] = num;
		}
		else
			Arr = NULL;
	}
	return Arr;
}