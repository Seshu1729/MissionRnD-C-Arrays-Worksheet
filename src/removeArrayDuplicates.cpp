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

int partition(int Arr[],int beg,int end)
{
	int left, right, temp, loc, flag;
	loc = left = beg;
	right = end;
	flag = 0;
	while (flag != 1)
	{
		while ((Arr[loc] <= Arr[right]) && loc != right)
			right--;
		if (loc == right)
			flag = 1;
		else if (Arr[loc] > Arr[right])
		{
			temp = Arr[loc];
			Arr[loc] = Arr[right];
			Arr[right] = temp;
			loc = right;
		}
		if (flag != 1)
		{
			while ((Arr[loc] >= Arr[left]) && loc != left)
				left++;
			if (loc == left)
				flag = 1;
			else if (Arr[loc] < Arr[left])
			{
				temp = Arr[loc];
				Arr[loc] = Arr[left];
				Arr[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
}

void quicksort(int Arr[], int beg, int end)
{
	int loc;
	if (beg < end)
	{
		loc = partition(Arr, beg, end);
		quicksort(Arr, beg, loc - 1);
		quicksort(Arr, loc + 1, end);
	}
}

void removeDup(int *Arr, int len)
{
	int index1 = 0, index2 = 0,label;
	for (index1 = 0; index1 < len;)
	{
		Arr[index2++] = Arr[index1];
		label = Arr[index1];
		while (label == Arr[index1] && index1 < len)
			index1++;
	}
}

void * removeArrayDuplicates(int *Arr, int len)
{
	int count, i;
	if (Arr != NULL)
	{
		if (len > 0)
		{
			quicksort(Arr, 0, len - 1);
			removeDup(Arr, len);
		}
		else
			Arr = NULL;
	}
	return NULL;
}

/*
METHOD 2:
void merge(int Arr[], int beg, int mid, int end, int len, int *count)
{
	int i = beg, j = mid + 1, index = beg, *temp, k;
	temp = (int *)malloc(sizeof(int)*len);
	while ((i <= mid) && (j <= end))
	{
		if (Arr[index - 1] == Arr[i] || Arr[i] == Arr[j])
		{
			i++;
			(*count)++;
		}
		else if (Arr[index - 1] == Arr[j])
		{
			j++;
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
*/