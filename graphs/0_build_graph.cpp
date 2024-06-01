#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;

	Edge(){

	}
	Edge(int in_source, int in_dest, int in_weight):
					source(in_source), dest(in_dest), weight(in_weight){

	}
};

void build_graph(vector<vector<Edge>>&graph, const int &edges){
	int source;
	int dest;
	int weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		if(source >= graph.size() || dest >= graph.size()){
			return ;
		}
		graph[source].push_back(Edge(source, dest, weight));
		graph[dest].push_back(Edge(dest, source, weight));
	}
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	for(auto g : graph){
		for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
	return 0;
}

/*
Input
----------------
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
*/