#pragma once
#include <iostream>
#include "Adjlist.h"
#include "Qu.h"
#include "Qu2.h"
#include "Edge.h"
#include "DisjointSet.h"
using namespace std;
class Graph
{
private:

	int v;
	Adjlist *array;
	bool * Bfs();
	bool IsCyclicUtil(int, int *);
	bool IsCyclic();
	int mindist(int *,bool *);
	void printdijkstra(int *);
	int minkey(int *, bool *);
	void printPrimMST(int *, int *);
	void printKruskalMST(Edge *);
public:
	Node *newnode(int,int);
	Graph *creatgraph(int);
	void addedge(int, int,int);
	void printgraph();
	void Bfs(Node*);
	void Bipartition(Node*);
	void Strongconnected();
	void IsDAG();
	void TopologicalOrder();
	void Dijkstra(int);
	void PrimMST();
	void KruskalMST();
	Graph();
	~Graph();
};

