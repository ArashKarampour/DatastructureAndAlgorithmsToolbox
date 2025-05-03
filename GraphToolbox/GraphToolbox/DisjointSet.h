#pragma once
class DisjointSet
{
	int *rank, *parent, n;
public:
	void makeSet();
	int find(int);
	void Union(int, int);
	DisjointSet(int);
	~DisjointSet();
};

