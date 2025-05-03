#include <iostream>

using namespace std;

// Number of factories. 2*N will be the number of applicants
const int N = 2;

void stableMatching(int ApplicantP[2 * N][N], int FactoryP[N][2 * N])
{
	int invprefer[N][2 * N];
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 2 * N; i++) {
			invprefer[j][FactoryP[j][i]] = i;

		}
	}
	// Storing Employees of factories. This is our output array.
	// The value of fEmployee[i][0] 
	// indicates the first applicant assigned to factory N.
	//And The value of fEmployee[i][1] indicates the second applicant assigned to factory N.
 	// the factory numbers between 0 and N-1. The value -1 
	// indicates that N'th factory is free 
	int fEmployee[N][2];

	// An array to store availability of vacant place.  If aFree[i] is 
	// false, then applicant 'i' is free, otherwise involved. 
	bool aFree[2 * N];

	// Initialize all applicants and factories as free 
	memset(fEmployee, -1, sizeof(fEmployee));
	memset(aFree, false, sizeof(aFree));
	int freeCount = 2 * N;

	// While there are free applicant 
	while (freeCount > 0)
	{
		// Pick the first free applicant (we could pick any) 
		int a;
		for (a = 0; a < 2 * N; a++)
			if (aFree[a] == false)
				break;

		// One by one go to all factories according to a's preferences. 
		// Here a is the picked free applicant 
		for (int i = 0; i < N && aFree[a] == false; i++)
		{
			int f = ApplicantP[a][i];

			// The factory of preference is free, f and a become 
			// partners (Note that the partnership maybe changed 
			// later). So we can say they are involved not employed 
			if (fEmployee[f][0] == -1)
			{
				fEmployee[f][0] = a;
				aFree[a] = true;
				freeCount--;
			}
			else if (fEmployee[f][1] == -1)
			{
				fEmployee[f][1] = a;
				aFree[a] = true;
				freeCount--;
			}

			else  // If f is not free 
			{
				
				int a0 = fEmployee[f][0];
				int a1 = fEmployee[f][1];
				// If f prefers a over her current engagement a0, 
				// then break the contract between f and a0 and 
				// involve a with f. 
				// If f prefers a over her current engagement a1, 
				// then break the contract between f and a1 and 
				// involve a with f. 
				
				if (invprefer[f][a] < invprefer[f][a0])
				{
					fEmployee[f][0] = a;
					aFree[a] = true;
					aFree[a0] = false;
				}
				else if (invprefer[f][a] < invprefer[f][a1])
				{
					fEmployee[f][1] = a;
					aFree[a] = true;
					aFree[a1] = false;
				}
			} // End of Else 
		} // End of the for loop that goes to all women in m's list 
	} // End of main while loop 


	// Print the solution 
	cout << "Factory   Employee[0]	Employee[1]" << endl;
	for (int i = 0; i < N; i++)
		cout << " " << i << "\t\t" << fEmployee[i][0] << "\t\t" << fEmployee[i][1] << endl;
}


int main()
{
	int ap[2 * N][N] = { {0,1},
	{0,1},
	{0,1},
	{0,1}
	};
	int fp[N][2 * N] = { {0,3,2,1},{3,2,0,1} };
	stableMatching(ap, fp);
	return 0;
	
}


