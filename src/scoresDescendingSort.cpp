/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct student 
{
	char name[10];
	int score;
};

void merge(struct student *students, int beg, int mid, int end, int len)
{
	long int i = beg, j = mid + 1, index = beg, k;
	struct student *temp;
	temp = (struct student *)malloc(sizeof(struct student)*len);
	while ((i <= mid) && (j <= end))
	{
		if (students[i].score>students[j].score)
		{
			temp[index] = students[i];
			i++;
		}
		else
		{
			temp[index] = students[j];
			j++;
		}
		index++;
	}
	if (i>mid)
	{
		while (j <= end)
		{
			temp[index] = students[j];
			j++;
			index++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[index] = students[i];
			i++;
			index++;
		}
	}
	for (k = beg; k<index; k++)
		students[k] = temp[k];
}

void merge_sort(struct student *students, int beg, int end, int len)
{
	int mid;
	if (beg<end)
	{
		mid = (beg + end) / 2;
		merge_sort(students, beg, mid, len);
		merge_sort(students, mid + 1, end, len);
		merge(students, beg, mid, end, len);
	}
}

void * scoresDescendingSort(struct student *students, int len)
{
	if (students != NULL)
	{
		if (len > 0)
			merge_sort(students, 0, len - 1, len);
		else
			students = NULL;
	}
	return NULL;
}