/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<stdlib.h>

void merge(int Arr[], int beg, int mid, int end, int len, int *count)
{
	int i = beg, j = mid + 1, index = beg, *temp, k;
	temp = (int *)malloc(sizeof(int)*len);
	while ((i <= mid) && (j <= end))
	{
		if (Arr[index - 1] == Arr[i] || Arr[index - 1] == Arr[j] || Arr[i] == Arr[j])
		{
			i++;
			(*count)++;
		}
		else if (Arr[i]<Arr[j])
		{
			temp[index++] = Arr[i];
			i++;
		}
		else
		{
			temp[index++] = Arr[j];
			j++;
		}
	}
	if (i>mid)
	{
		while (j <= end)
		{
			temp[index] = Arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[index] = Arr[i];
			i++;
			index++;
		}
	}
	for (k = beg; k<index; k++)
		Arr[k] = temp[k];
}

int merge_sort(int Arr[], int beg, int end, int len)
{
	int mid, count = 0;
	if (beg<end)
	{
		mid = (beg + end) / 2;
		merge_sort(Arr, beg, mid, len);
		merge_sort(Arr, mid + 1, end, len);
		merge(Arr, beg, mid, end, len, &count);
	}
	return count;
}

void * removeArrayDuplicates(int *Arr, int len)
{
	int count,i;
	if (Arr != NULL)
	{
		if (len > 0)
		{
			count = merge_sort(Arr, 0, len - 1, len);
			for (i = len - count; i < count; i++)
				free(&Arr[i]);
		}
		else
			Arr = NULL;
	}
	return NULL;
}