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

int *trim(int *result, int *count)
{
	int index;
	for (index = 0; index < 10; index++)
	{
		if (result[index] != 0)
			result[(*count)++] = result[index];
	}
	return result;
}

void * removeArrayDuplicates(int *Arr, int len)
{
	int *result, i, count = 0;
	if (len < 1 || Arr == NULL)
		return NULL;
	result = (int *)calloc(10, sizeof(int));
	for (i = 0; i < len; i++)
	{
		if (result[Arr[i]] == 0)
			result[Arr[i]] = Arr[i];
	}
	result = trim(result, &count);
	for (i = 0; i < count; i++)
		Arr[i] = result[i];
	return result;
}

/*

METHOD 2:
void merge(int Arr[], int beg, int mid, int end, int len)
{
	int i = beg, j = mid + 1, index = beg, *temp, k;
	temp = (int *)malloc(sizeof(int)*len);
	while ((i <= mid) && (j <= end))
	{
		if (Arr[i]<Arr[j])
		{
			if (Arr[i] != temp[index - 1])
				temp[index++] = Arr[i];
			i++;
		}
		else
		{
			if (Arr[j] != temp[index - 1])
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

void merge_sort(int Arr[], int beg, int end, int len)
{
	int mid;
	if (beg<end)
	{
		mid = (beg + end) / 2;
		merge_sort(Arr, beg, mid, len);
		merge_sort(Arr, mid + 1, end, len);
		merge(Arr, beg, mid, end, len);
	}
}

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr != NULL)
	{
		if (len > 0)
			merge_sort(Arr, 0, len - 1, len);
		else
			Arr = NULL;
	}
	return NULL;
}

*/