/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student 
{
	char *name;
	int score;
};

void merge1(struct student *students, int beg, int mid, int end, int len)
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

void merge_sort1(struct student *students, int beg, int end, int len)
{
	int mid;
	if (beg<end)
	{
		mid = (beg + end) / 2;
		merge_sort1(students, beg, mid, len);
		merge_sort1(students, mid + 1, end, len);
		merge1(students, beg, mid, end, len);
	}
}

struct student ** topKStudents(struct student *students, int len, int K)
{
	int i;
	struct student **result;
	K = len<K ? len : K;
	if (students != NULL)
	{
		if (len>0&&K>0)
			merge_sort1(students, 0, len - 1, len);
		else
			return NULL;
	}
	result = (struct student **)malloc(sizeof(struct node *)*K);
	for (i = 0; i < K; i++)
		result[i] = &students[i];
	return result;
}