#include <iostream>
#include <string>
using namespace std;

#define V 7 // Number of vertices in the graph
#define M 3 // Number of colors


int chooseBestNext(bool graph[V][V],int color[]) {

	int countConstraints[V] = {0};

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (graph[i][j])
				countConstraints[i]++;
		}
	}

	int max = countConstraints[0];
	int index = 0;
	

	for (int i = 0; i < V; ) {

	
		if ((countConstraints[i] > max) && (color[i] == 0)) {
			max = countConstraints[i];
			index = i;
			++i;
		}
		else if (color[i] != 0)
		{
			++i;
			if ((color[i] == 0) && (color[index] != 0)) {

				max = countConstraints[i];
				index = i;
				
			}
			
			
		}
		else
			++i;
		
	}
	//cout << index<<endl;
	return index;
}

bool forwardChecking(bool graph[V][V], bool hasColor[V][M],int color[],int v,int c) {

	bool copyOfhasColor[V][M];
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < M;++j) {
			copyOfhasColor[i][j] = hasColor[i][j];
		}

	//hasColor[v][c - 1] = false;

	for (int i = 0; i < V; ++i) {
		if (graph[v][i])
			hasColor[i][c - 1] = false;
	}

	
	for (int i = 0; i < V; ++i) {
		int m = 0;
		if (graph[v][i]) {
			for (int j = 0; j < M; ++j) {
				if (!hasColor[i][j])
					++m;
			}
		}
		if ((m == M) && (color[i] == 0)) {
			for (int i = 0; i < V; ++i)
				for (int j = 0; j < M; ++j) {
					hasColor[i][j] = copyOfhasColor[i][j];
				}

			hasColor[v][c - 1] = false;

			return true; //true if a vertex has no legal value
		}
			

	}
	//return the primary values of hascolor
	/*for (int i = 0; i < V; ++i)
		for (int j = 0; j < M; ++j) {
			hasColor[i][j] = copyOfhasColor[i][j];
		}*/

	return false;

		
}

void ArcConsistency(bool graph[V][V], bool hasColor[V][M], int color[], int v, int c) {

	bool copyOfhasColor[V][M];
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < M; ++j) {
			copyOfhasColor[i][j] = hasColor[i][j];
		}

	//hasColor[v][c - 1] = false;

	for (int i = 0; i < V; ++i) {
		if (graph[v][i])
			hasColor[i][c - 1] = false;
	}


	for (int i = 0; i < V; ++i) {
		int m = 0, k = 0;
		if (graph[v][i]) {
			for (int j = 0; j < M; ++j) {
				if (!hasColor[i][j])
					++m;
			}
			if ((m == M) && (color[i] == 0))
			{
				for (int i = 0; i < V; ++i)
					for (int j = 0; j < M; ++j) {
						hasColor[i][j] = copyOfhasColor[i][j];
					}
				copyOfhasColor[v][c - 1] = false;
				hasColor[v][c - 1] = false;
				color[v] = 0;
			}
		}
		if (graph[i][v]) {
			//hasColor[i][c - 1] = true; hasColor[v][c - 1] = false;
			for (int j = 0; j < M; ++j) {
				if (!hasColor[v][j])
					++k;
			}
			if ((k == M)&&(color[v]==0))
			{
				hasColor[v][c - 1] = true;
				hasColor[i][c - 1] = false;
			}
		}
	}
	/*//return the primary values of hascolor
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < M; ++j) {
			hasColor[i][j] = copyOfhasColor[i][j];
		}

	return false;*/


}


/* A utility function to check if
   the current color assignment
   is safe for vertex v i.e. checks
   whether the edge exists or not
   (i.e, graph[v][i]==1). If exist
   then checks whether the color to
   be filled in the new vertex(c is
   sent in the parameter) is already
   used by its adjacent
   vertices(i-->adj vertices) or
   not (i.e, color[i]==c) */
bool checkConstraint(int v, bool graph[V][V],int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && (c == color[i]))
			return false;
	return true;
}

/* A recursive utility function
to solve m coloring problem */
bool graphColoringrecursive(bool graph[V][V],int color[],bool hasColor[V][M], int v)
{
	bool finish = true;
	/* base case: If all vertices are
	   assigned a color then return true */
	for (int i = 0; i < V; ++i) {
		if (color[i] == 0)
			finish = false;
	}
	if (finish == true)
		return true;

	/* Consider this vertex v and
	   try different colors */
	for (int c = 1; c <= M; c++) {
		/* Check if assignment of color
		   c to v is fine*/
		if (checkConstraint(v, graph, color, c)&&(hasColor[v][c-1])&&(color[v] == 0)) {
			color[v] = c;

			ArcConsistency(graph, hasColor, color, v, c);
			/* recur to assign colors to
			   rest of the vertices */
			//if(forwardChecking(graph,hasColor,color,v,c)==false)
			if ((hasColor[v][c - 1]) && (color[v] != 0)) 
				if (graphColoringrecursive(graph, color, hasColor, chooseBestNext(graph, color)) == true)
					return true;
			

			/* If assigning color c doesn't
			   lead to a solution then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to
	   this vertex then return false */
	return false;
}

/* This function solves the m Coloring
   problem using Backtracking. It mainly
   uses graphColoringUtil() to solve the
   problem. It returns false if the m
   colors cannot be assigned, otherwise
   return true and prints assignments of
   colors to all vertices. Please note
   that there may be more than one solutions,
   this function prints one of the
   feasible solutions.*/

void printSolution(int color[],string cities[],string colors[])
{
	cout<<
		"Solution Exists:"
		" Following are the assigned colors "<<endl;
	for (int i = 0; i < V; i++)
		cout << cities[i] << "\t: " << colors[color[i] - 1]<<endl;
	
}
/* A utility function to print solution */

bool graphColoring(bool graph[V][V])
{
	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;
	
	bool hasColor[V][M];
	
	// Call graphColoringUtil() for best vertex 
	if (graphColoringrecursive(graph, color,hasColor, chooseBestNext(graph,color))== false) {
		cout<<"Solution does not exist"<<endl;
		return false;
	}
	string cities[V] = {"WA","NT","SA","Q","NSW","V","T"};
	string colors[M] = {"r","g","b"};
	// Print the solution
	printSolution(color,cities,colors);
	return true;
}


// driver program to test above function
int main()
{
	/* Create following graph and test
	   whether it is 3 colorable
	  (3)---(2)
	   |   / |
	   |  /  |
	   | /   |
	  (0)---(1)
	*/
	/*bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};*/
	bool graph[V][V] = {
		{ 0, 1, 1, 0 , 0, 0, 0}, //0:2
		{ 1, 0, 1, 1 , 0, 0, 0}, //1:3
		{ 1, 1, 0, 1 , 1, 1, 0}, //2:5
		{ 0, 1, 1, 0 , 1, 0, 0}, //3:3 
		{ 0, 0, 1, 1 , 0, 1, 0}, //4:3
		{ 0, 0, 1, 0 , 1, 0, 0}, //5:2 
		{ 0, 0, 0, 0 , 0, 0, 0}  //6:0
	};
	//int m = 3; // Number of colors
	graphColoring(graph);
	return 0;
}