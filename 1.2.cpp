#include <iostream>
#include "word.h"

//判断单词是否在单词表中出现
bool FindWorld(char *str)
{
	int n = 0;
	while (n < NUM)
	{
		if (strcmp(str, word[n]) == 0)
			return true;
		n++;
	}
	return false;
}


const int N = 4;  //数组维数
void SearchWord(char matrix[N][N])
{
	int N = 4;
	for (int i = 0; i < N; i++)              //三元组(行，列，方向→)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = j + 1;
			while (k < N)
			{
				word[iter++] = matrix[i][k];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k++;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向↘)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = i + 1, h = j + 1;
			while (k < N&&h < N)
			{
				word[iter++] = matrix[k][h];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k++, h++;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向↓)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = i + 1;
			while (k < N)
			{
				word[iter++] = matrix[k][j];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k++;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向↙)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = i + 1, h = j - 1;
			while (k < N&&h >= 0)
			{
				word[iter++] = matrix[k][h];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k += 1, h -= 1;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向←)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = j - 1;
			while (k >= 0)
			{
				word[iter++] = matrix[i][k];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k -= 1;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向↖)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = i - 1, h = j - 1;
			while (k >= 0 && h >= 0)
			{
				word[iter++] = matrix[k][h];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k--, h--;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向↑)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = i - 1;
			while (k >= 0)
			{
				word[iter++] = matrix[k][j];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k--;
			}
		}
	}

	for (int i = 0; i < N; i++)              //三元组(行，列，方向↗)  
	{
		for (int j = 0; j < N; j++)
		{
			char word[20] = { '\0' };
			int iter = 0;
			word[iter++] = matrix[i][j];
			int k = i - 1, h = j + 1;
			while (k >= 0 && h < N)
			{
				word[iter++] = matrix[k][h];
				if (FindWorld(word) == true)
					printf("%s\n", word);
				k--, h++;
			}
		}
	}
}

int main()
{
	char puzzle[N][N] = {
		't','h','i','s',
		'w','a','t','s',
		'o','a','h','h',
		'f','g','d','t'
	};
	SearchWord(puzzle);
	return 0;
}