#include "Graph.h"





Node * Graph::newnode(int a,int weight)
{
	Node *n = new Node;
	n->data = a;
	n->weight = weight;
	n->next = nullptr;
	//n->visited = false;
	return n;
}

Graph * Graph::creatgraph(int V)
{
	Graph * g = new Graph;
	g->v = V;
	g->array = new Adjlist[V];
	for (int i = 0; i < V; ++i)
		g->array[i].head = nullptr;
	
	return g;
}

void Graph::addedge(int s, int d,int weight)
{
	Node * n = this->newnode(d,weight);
	n->next = this->array[s].head;
	this->array[s].head = n;
	
}

void Graph::printgraph()
{
	Node *p;
	for (int i = 0; i < this->v; ++i) {
		p = this->array[i].head;
		cout << "Node " << i << " : ";
		while (p) {
			cout << p->data << "->";
			p = p->next;
		}
		cout << endl;
	}
}

void Graph::Bfs(Node *n)
{
	Qu q(this->v);
	cout << n->data<<" ";
	bool * visit;
	visit = new bool[this->v];
	for (int i = 0; i < this->v; ++i)
		visit[i] = false;
	//n->visited = true;
	visit[n->data] = true;
	q.add(n);
	//int p;
	while (!q.is_empty()) {
		
		n = q.del();
		
		for (Node *w = this->array[n->data].head; w != nullptr; w = w->next) {

			if (!visit[w->data]) {

				cout << w->data << " ";
				//w->visited = true;
				visit[w->data] = true;
				q.add(w);
			}
		}
	}
	cout << endl;
}

void Graph::Bipartition(Node *s)
{
	Qu q(this->v);
	//cout << s->data << " ";
	int * color;
	color = new int[this->v];
	for (int i = 0; i < this->v; ++i)
		color[i] = -1;
	//n->visited = true;
	color[s->data] = 1;
	q.add(s);
	bool isbipartite = true;
	while (!q.is_empty()) {

		s = q.del();
		
		for (Node *w = this->array[s->data].head; (w != nullptr)&&isbipartite ; w = w->next) {

			if (color[w->data] == -1) {

				color[w->data] = 1 - color[s->data];
				q.add(w);

			}
			else if (color[w->data] == color[s->data]) {
				cout << endl << "not Bipartite" << endl;
				isbipartite = false;
			}
				
		}
		
	}
	if(isbipartite)
		cout << endl<<"is Bipartite"<<endl;
}

void Graph::Strongconnected()
{
	bool *arr0 = new bool[this->v];
	for (int i = 0; i < this->v; ++i)
		arr0[i] = true;
	Graph *grev = new Graph;
	grev = grev->creatgraph(this->v);
	for (int i = 0; i < this->v; ++i)
		for (Node *w = this->array[i].head; w; w = w->next)
			grev->addedge(w->data, i,0);
	bool *arr1 = new bool[this->v];
	bool *arr2 = new bool[this->v];
	bool isSC = true;
	arr1 = this->Bfs();
	arr2 = grev->Bfs();
	for (int i = 0; (i < this->v)&&isSC; ++i) {
		if ((arr0[i] != arr1[i]) || (arr0[i] != arr2[i])) {
			cout << endl << "Not Strong Connected" << endl;
			isSC = false;
		}
	}
	if(isSC)
		cout << endl << "Is Strong Connected" << endl;

	
}




bool * Graph::Bfs()
{
	Qu q(this->v);

	bool * visit;
	visit = new bool[this->v];
	for (int i = 0; i < this->v; ++i)
		visit[i] = false;
	Node *n = this->array[0].head;
	visit[n->data] = true;
	
	q.add(n);
	//int p;
	while (!q.is_empty()) {

		n = q.del();

		for (Node *w = this->array[n->data].head; w != nullptr; w = w->next) {

			if (!visit[w->data]) {

				visit[w->data] = true;
				q.add(w);
			}
		}
	}
	
	return visit;
}

bool Graph::IsCyclicUtil(int u, int *color)
{
	color[u] = 1;

	for (Node * w = this->array[u].head; w; w = w->next) {

		if (color[w->data] == 1)
			return true;

		if ((color[w->data] == 0) && (IsCyclicUtil(w->data, color)))
			return true;
		


	}
	color[u] = 2;
	return false;
}

bool Graph::IsCyclic()
{
	int *color = new int[this->v];
	for (int i = 0; i < this->v; ++i)
		color[i] = 0;

	// Do a DFS traversal beginning with all 
	// vertices 
	for (int i = 0; i < this->v; ++i)
		if (color[i] == 0)
			if (IsCyclicUtil(i, color) == true)
				return true;

	return false;
	
}



void Graph::IsDAG()
{
	if (this->IsCyclic())
		cout << endl << "Not DAG->(has Cycle)";
	else
		cout << endl << "Is DAG->(has no Cycle)";
}

void Graph::TopologicalOrder()
{
	if (this->IsCyclic()) {
		cout << endl << "has no Topological Orders" << endl;
	}
	else {
		Qu2 q(this->v + 1);
		bool *visit = new bool[this->v];
		bool *edgeto = new bool[this->v];//shows that if there is an edge to the node or not.
		Node*n = new Node;
		for (int i = 0; i < this->v; ++i) {
			visit[i] = false; edgeto[i] = false;
		}
		int counter = 0; //int counter = 0; counter != this->v; ++counter; !q.is_full();
		while (counter != this->v) {
			for (int i = 0; i < this->v; ++i) {
				edgeto[i] = false;
			}

			for (int i = 0; i < this->v; ) {
				if (visit[i])
					++i;
				for (int j = 0; j < this->v; ++j) {
					n = this->array[j].head;
					
					for (Node*w = n; w; w = w->next) {
						if (w->data == i) {
							edgeto[w->data] = true;
							++i; j = 0;
						}
					}
				}
				++i;
			}

			for (int k = 0; k < this->v; ++k) {
				if ((!edgeto[k]) && (!visit[k])) {
					q.add(k);
					this->array[k].head = nullptr;
					visit[k] = true;
					++counter;
				}
			}

		}

		while (!q.is_empty()) {
			cout << q.del()<<" ";
		}
	}
}



int Graph::mindist(int *d, bool *shpset)//d = distance, shpset = shorthest path nodes set
{
	int min = INT_MAX, min_ind;

	for (int i = 0; i < this->v; ++i) {
		if (shpset[i] == false && d[i] <= min)
			min = d[i], min_ind = i;
	}
	return min_ind;
}

void Graph::printdijkstra(int *d)
{
	cout<<"Vertex \t\t Distance from Source\n";
	for (int i = 0; i < this->v; i++)
		cout<< i<< "\t\t" << d[i]<<endl;
}



void Graph::Dijkstra(int s)//s = source
{
	int *d = new int[this->v];
	bool *shpset = new bool[this->v];

	for (int i = 0; i < this->v; ++i)
		d[i] = INT_MAX, shpset[i] = false;

	d[s] = 0;

	for (int i = 0; i < this->v; ++i) {
		
		int u = mindist(d, shpset);

		shpset[u] = true;

		for (Node *w = this->array[u].head; w; w = w->next) {
			if (!shpset[w->data] && w && d[u] != INT_MAX && ((d[u] + w->weight) < d[w->data]))
				d[w->data] = d[u] + w->weight;
		}
		
	}
	printdijkstra(d);
}

int Graph::minkey(int * keyvalue, bool * mstset)
{
	int min = INT_MAX, min_ind;
	for (int i = 0; i < this->v; ++i)
		if (keyvalue[i] < min && !mstset[i])
			min = keyvalue[i], min_ind = i;
	return min_ind;
}

void Graph::printPrimMST(int *parent, int *weightarr)
{
	int s = 0;
	cout << "Edges\t\tWeights\n";
	for (int i = 1; i < this->v; ++i) {
		cout <<"G( "<<parent[i] << ", " << i << ") \t" << weightarr[i] << " \n";
		s += weightarr[i];
	}
	cout << "MST cost by Prim: " << s << endl;

}



void Graph::PrimMST()
{
	int * parent = new int[this->v], * weightarr = new int[this->v],  * keyvalue = new int[this->v];
	bool * mstset = new bool[this->v];
	for (int i = 0; i < this->v; ++i)
		keyvalue[i] = INT_MAX, mstset[i] = false;

	keyvalue[0] = 0; 
	parent[0] = -1;//first vertex as root

	for (int i = 0; i < this->v; ++i) {
		int u = minkey(keyvalue, mstset);
		mstset[u] = true;
		
		for (Node *w = this->array[u].head; w; w = w->next) {
			if (w && !mstset[w->data] && w->weight < keyvalue[w->data])
				keyvalue[w->data] = w->weight, parent[w->data] = u, weightarr[w->data] = w->weight;
		}
	}
	printPrimMST(parent, weightarr);
}

void Graph::printKruskalMST(Edge * e)
{
	int s = 0;
	cout << "Source\tDest\tWeight\n";
	for (int i = 0; e[i].src != -1; ++i) {
		cout << e[i].src << "\t" << e[i].dest << "\t" << e[i].weight << endl;
		s += e[i].weight;
	}
	cout << "MST cost by Kruskal: " << s << endl;
}

void Graph::KruskalMST()
{
	int n = 0;
	DisjointSet s(this->v);
	Edge * E = new Edge[(this->v - 1)*(this->v)]; //maximum number number of edges would be (n-1)*n for a directed graph with n verticies.
	for(int i = 0; i < this->v; ++i) {
		for (Node *w = this->array[i].head; w; w = w->next) {
			E[n].src = i, E[n].dest = w->data, E[n].weight = w->weight;
			++n;
		}
	}
	E[n].src = -1;
	for (int j = 0; E[j].src != -1; ++j) {
		int min = E[j].weight;
		for (int k = j+1; E[k].src != -1; ++k) {
			if (E[k].weight < min) {
				min = E[k].weight;
				swap(E[k], E[j]);
			}
		}
	}

	int e = 0; Edge * Eret = new Edge[(this->v - 1)*(this->v)]; n = 0;

	for (int i = 0; E[i].src != -1 && e < this->v - 1; ++i) {
		if (s.find(E[i].src) != s.find(E[i].dest)) {
			s.Union(E[i].src, E[i].dest);
			Eret[n] = E[i];
			++e; ++n;
		}
	}
	Eret[n].src = -1;

	printKruskalMST(Eret);


}

Graph::Graph()
{
}


Graph::~Graph()
{
}
