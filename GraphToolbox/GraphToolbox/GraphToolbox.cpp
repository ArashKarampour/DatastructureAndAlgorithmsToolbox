//#include <iostream>
#include "Graph.h"
using namespace std;
int main()
{
	Graph * g = new Graph;
	//g = g->creatgraph(4);//then nodes must be 0,1,2,3
	
	//g->addedge(0, 1,0);
	//g->addedge(1, 0,0);
	//g->addedge(0, 2,0);
	//g->addedge(2, 0,0);
	//g->addedge(2, 3,0);
	//g->addedge(3, 2,0);
	//g->addedge(3, 1,0);
	//g->addedge(1, 3,0);
	//g->addedge(0, 3,0);
	//g->addedge(3, 0,0);
	//Node *n = g->newnode(0,0);
	//g->Bfs(n);
	//g->printgraph();
	//g->Bipartition(n);
	//g->Strongconnected();
	//g->IsDAG();
	//g->TopologicalOrder();
	/*
	g = g->creatgraph(3);
	g->addedge(0, 1, 4);
	g->addedge(0, 2, 6);
	g->addedge(1, 2, 1);
	g->Dijkstra(0);
	*/
	
	g = g->creatgraph(9);
	g->addedge(0, 1, 4);
	g->addedge(0, 7, 8);
	g->addedge(1, 2, 8);
	g->addedge(1, 7, 11);
	g->addedge(2, 3, 7);
	g->addedge(2, 8, 2);
	g->addedge(2, 5, 4);
	g->addedge(3, 4, 9);
	g->addedge(3, 5, 14);
	g->addedge(4, 5, 10);
	g->addedge(5, 6, 2);
	g->addedge(6, 7, 1);
	g->addedge(6, 8, 6);
	g->addedge(7, 8, 7);
	g->PrimMST();
	g->KruskalMST();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
