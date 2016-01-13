/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int i, j, count = 0, temp_count = 0;
		for (i = 0; i < len; i++)
		{
			temp_count = 0;
			for (j = 6; j <9; j++)//year check
			{
				if (Arr[i].date[j] == date[j])
					temp_count++;
				else
					break;
			}
			if (temp_count == 4)
			{
				temp_count = 0;
				
				for (j = 3; j<5; j++)//month check
				{
					if (Arr[i].date[j] == date[j])
						temp_count++;
					else
						break;
				}
				if (temp_count == 2)
				{
					temp_count = 0;
					for (j = 0; j<2; j++)//day check
					{
						if (Arr[i].date[j] == date[j])
							temp_count++;
						else
							break;
						
					}
					if (temp_count == 2)
					{
						temp_count = 0;
						break;
					}

					else if (Arr[i].date[j]>date[j])
						count++;
				}
				else
				{
					if (Arr[i].date[j]>date[j])
						count++;
				}
			}
			else
			{
				if (Arr[i].date[j]>date[j])
					count++;
			}

		}

		return count;
	

}
