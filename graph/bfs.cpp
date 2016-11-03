
#include<list>
#include<iostream>
using namespace std;

class Graph {
	int V;
	list<int> * adj;
	void BFSUtil(int s, bool visited[]);  
public:
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	void BFS(int s);
	void DFS(int s);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph() {
	delete []adj;
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}
void Graph::BFS(int s){
	bool *visited = new bool[V];
	for (int i=0; i<V; i++)
		visited[i] = false;
	/*
	for (int i=0; i<V; i++)
		if (!visited[i])
			BFSUtil(i, visited);
	*/
	BFSUtil(s, visited);
}
void Graph::BFSUtil(int s, bool visited[]) {
	
	// Create a queue for BFS
	list<int> queue;
	
	queue.push_back(s);
	visited[s] = true;

	// "i" will be used to get all adjacent vertices of vertex
	list<int>::iterator i;

	while (!queue.empty()){
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for (i=adj[s].begin(); i!=adj[s].end(); i++) {
			if (!visited[*i]) {
				queue.push_back(*i);
				visited[*i] = true;
			}
		}
	}
}

void Graph::DFS(int s){}

int main() {
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Tranversal(starting from vertex 2) \n";
	g.BFS(1);
	return 0;
}


