/*#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

// function to find out the minimum penalty 
void getMinimumPenalty(string x, string y, int axy, int gap)
{
	int i, j; // intialising variables 

	int m = x.length(); // length of gene1 
	int n = y.length(); // length of gene2 

	// table for storing optimal substructure answers 
	int **M = new int *[m + 1];
	for (int i = 0; i < m + 1; ++i) {
		M[i] = new int[n + 1];
	}
		

	// intialising the table  
	for (i = 0; i <= m; i++)
	{
		M[i][0] = i * gap;
	}
	for (i = 0; i <= n; i++)
	{
		M[0][i] = i * gap;
	}

	// calcuting the minimum penalty 
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				M[i][j] = M[i - 1][j - 1];
			}
			else
			{
				M[i][j] = min({ M[i - 1][j - 1] + axy ,
								M[i - 1][j] + gap    ,
								M[i][j - 1] + gap });
			}
		}
	}

	// Reconstructing the solution 
	int l = n + m; // maximum possible length 

	i = m; j = n;

	int xpos = l;
	int ypos = l;

	// Final answers for the respective strings 
	int *xans = new int[l + 1];int *yans = new int[l + 1];

	while (!(i == 0 || j == 0))
	{
		if (x[i - 1] == y[j - 1])
		{
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)y[j - 1];
			i--; j--;
		}
		else if (M[i - 1][j - 1] + axy == M[i][j])
		{
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)y[j - 1];
			i--; j--;
		}
		else if (M[i - 1][j] + gap == M[i][j])
		{
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)'_';
			i--;
		}
		else if (M[i][j - 1] + gap == M[i][j])
		{
			xans[xpos--] = (int)'_';
			yans[ypos--] = (int)y[j - 1];
			j--;
		}
	}
	while (xpos > 0)
	{
		if (i > 0) xans[xpos--] = (int)x[--i];
		else xans[xpos--] = (int)'_';
	}
	while (ypos > 0)
	{
		if (j > 0) yans[ypos--] = (int)y[--j];
		else yans[ypos--] = (int)'_';
	}

	// Since we have assumed the answer to be n+m long,  
	// we need to remove the extra gaps in the starting  
	// id represents the index from which the arrays 
	// xans, yans are useful 
	int id = 1;
	for (i = l; i >= 1; i--)
	{
		if ((char)yans[i] == '_' && (char)xans[i] == '_')
		{
			id = i + 1;
			break;
		}
	}

	// Printing the final answer 
	cout << "Minimum Penalty in aligning the genes = ";
	cout << M[m][n] << "\n";
	cout << "The aligned genes are :\n";
	for (i = id; i <= l; i++)
	{
		cout << (char)xans[i];
	}
	cout << "\n";
	for (i = id; i <= l; i++)
	{
		cout << (char)yans[i];
	}
	return;
}

// Driver code 
int main() {
	// input strings 
	string gene1 = "AGGGCT";
	string gene2 = "AGGCA";

	// intialsing penalties of different types 
	int misMatchPenalty = 3;
	int gapPenalty = 2;

	// calling the function to calculate the result 
	getMinimumPenalty(gene1, gene2,
		misMatchPenalty, gapPenalty);
	return 0;
}*/
#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

void getMinimumPenalty(string x, string y, int axy, int gap)
{
	int i, j;

	int m = x.length();
	int n = y.length();


	int **M = new int *[m + 1];
	for (int i = 0; i < m + 1; ++i) {
		M[i] = new int[n + 1];
	}



	for (i = 0; i <= m; i++)
	{
		M[i][0] = i * gap;
	}
	for (i = 0; i <= n; i++)
	{
		M[0][i] = i * gap;
	}


	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				M[i][j] = M[i - 1][j - 1];
			}
			else
			{
				M[i][j] = min({ M[i - 1][j - 1] + axy ,M[i - 1][j] + gap ,M[i][j - 1] + gap });
			}
		}
	}


	cout << "Minimum Penalty is= ";
	cout << M[m][n] << "\n";
	return;
}


int main() {

	string gene1 = "AGGGCT";
	string gene2 = "AGGCA";

	int misMatchPenalty = 3;
	int gapPenalty = 2;

	getMinimumPenalty(gene1, gene2,
		misMatchPenalty, gapPenalty);
	return 0;
}

