#include <bits/stdc++.h>
#define VAL -1

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;

	//default constructor
	Edge(){}
	//parameterized constructor
	Edge(int in_source, int in_dest, int in_weight):
			source(in_source), dest(in_dest), weight(in_weight){}
};

class Tuple{
public:
	int vertex;
	string psf;
	int level;
    
    //default constructor
	Tuple(){}
	//paramterized constructor
	Tuple(int in_vertex, string in_psf, int in_level):
				vertex(in_vertex), psf(in_psf), level(in_level){}
};

void build_graph(vector<vector<Edge>>&graph, const int &edges){
	int source, dest, weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		graph[source].push_back(Edge(source, dest, weight));
		graph[dest].push_back(Edge(dest, source, weight));
	}
}

void display_graph(vector<vector<Edge>>&graph){
	for(auto g : graph){
		for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}

bool check_for_bipartite(vector<vector<Edge>>&graph, int vertex, vector<int>&visited){
	queue<Tuple>q;
	q.push(Tuple(vertex, ""+to_string(vertex), 0));

	while(!q.empty()){
		Tuple front_vertex = q.front();
		q.pop();

		if(visited[front_vertex.vertex]!=-1){
			if(front_vertex.level != visited[front_vertex.vertex]){
				return false;
			}
		}

        //update the visited array with level
		visited[front_vertex.vertex] = front_vertex.level;

        //traversal the adjacency list
		for(auto e : graph[front_vertex.vertex]){
			if(visited[e.dest]==-1){
				q.push(Tuple(e.dest, front_vertex.psf+to_string(e.dest), front_vertex.level+1));
			}
		}
	}
	return true;
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<int>visited(vertices,VAL);
	bool is_bipartite = true;
	for(int v=0; v<vertices; v++){
		if(visited[v]==-1){
	        is_bipartite = check_for_bipartite(graph, v, visited);
	        if(is_bipartite==false){
	    	    break;
	        }
	    }
	}
	if(is_bipartite==false){
		cout<<"Graph is not bipartite"<<endl;
	}
	else{
		cout<<"Garph is bipartite"<<endl;
	}
	return 0;
}

/*
Definition
-------------------
Bipartite:
If it possible to divide the vertices of graph into two mutually exclusive and exhaustive sets
such that all edges are across sets.

A graph is said to be bipartite if and only if
1. It is acyclic
2. If it a cyclic then it should be
	a. even size (even cycle graph) it will be a bipartite graph
	b. old size (is not a bipratite graph).


Test case 1
-----------------
4
4
0 1 10
1 2 10
2 3 10
0 3 10

Test case 2
-------------------
7   
7
0 1 10
1 2 10
2 3 10
0 3 10
4 5 10
5 6 10
4 6 10

*/