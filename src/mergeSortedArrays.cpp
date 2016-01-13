/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int len(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
		int i, j, size = 0, temp = 0;
		struct transaction *output;
		if (A == NULL || B == NULL)
			return NULL;
		output = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
		i = j = 0;
		while (i<ALen && j<BLen)
		{
			if (A[i].amount<B[j].amount)
			{
				output[size++] = A[i];
				i++;
			}
			else
			{
				output[size++] = B[j];
				j++;
			}
			if (A[i].amount == B[j].amount)
			{
				output[size++] = A[i];
				output[size++] = B[j];
				i++;
				j++;
			}
		}
		while (i < ALen)
		{
			output[size++] = A[i];
			i++;
		}
		while (j < BLen)
		{
			output[size++] = B[j];
			j++;
		}
		if (size)
			return output;
		else
			return NULL;

}