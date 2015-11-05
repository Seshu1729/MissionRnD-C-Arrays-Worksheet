
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int getLessCount(int *Arr, int score, int beg, int end, int *lessCount)
{
	while (beg <= end)
	{
		*lessCount = (beg + end) / 2;
		if (Arr[*lessCount]<score&&Arr[*lessCount + 1] >= score)
			break;
		else if (Arr[*lessCount] >= score)
			end = *lessCount - 1;
		else
			beg = *lessCount + 1;
	}
	return *lessCount;
}

void getMoreCount(int *Arr, int score, int beg, int end, int *moreCount)
{
	while (beg <= end)
	{
		*moreCount = (beg + end) / 2;
		if (Arr[*moreCount]>score&&Arr[*moreCount - 1] <= score)
			break;
		else if (Arr[*moreCount] <= score)
			beg = *moreCount + 1;
		else
			end = *moreCount - 1;
	}
}

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount)
{
	if (Arr != NULL)
	{
		if (len>0)
		{
			getMoreCount(Arr, score, getLessCount(Arr, score, 0, len, lessCount), len, moreCount);
			if (*lessCount != 0 && len != 1)
				*lessCount = *lessCount + 1;
			*moreCount = len - *moreCount;
		}
		else
			Arr = NULL;
	}
	return NULL;
}
