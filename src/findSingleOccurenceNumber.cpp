/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<iostream>
int findSingleOccurenceNumber(int *A, int len) 
{
	int i, ele = -1, count, j, min_count;
	if (A == NULL)
		return -1;
	min_count = 999;
	for (i = 0; i<len; i++){
		count = 1;
		for (j = i + 1; j <= len - 1; j++){
			if (A[i] == A[j] && A[i] != '\0'){
				count++;
				A[j] = '\0';
			}
		}

		if (A[i] != '\0'){
			if (min_count > count)
			{
				min_count = count;
				ele = A[i];
			}
		}
	}
	return ele;
}