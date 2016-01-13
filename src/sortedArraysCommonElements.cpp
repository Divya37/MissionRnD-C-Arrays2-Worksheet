/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

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

int compare(char *string1, char *string2)	//comparing two strings
{
	int i = 0, flag = 0;

	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	return flag;
}

struct transaction* sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int i, j, size = 0;
	struct transaction *result;
	if (A == NULL || B == NULL)
		return NULL;
	result = (struct transaction *)malloc(sizeof(struct transaction)*((ALen>BLen) ? ALen : BLen));

	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (compare(A[i].date,B[i].date)==0)
			{
				result[size++] = A[i];	
				break;
			}
		}
	}
	if (size)
		return result;
	else
		return NULL;
}
